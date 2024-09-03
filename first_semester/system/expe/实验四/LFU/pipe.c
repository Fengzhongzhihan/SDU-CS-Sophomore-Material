
#include "pipe.h"
#include "shell.h"
#include "mips.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "cache.h"


int iCache_read_count = 50;


//#define DEBUG

/* debug */
void print_op(Pipe_Op *op)
{
    if (op)
        printf("OP (PC=%08x inst=%08x) src1=R%d (%08x) src2=R%d (%08x) dst=R%d valid %d (%08x) br=%d taken=%d dest=%08x mem=%d addr=%08x\n",
                op->pc,
               op->instruction,
               op->reg_src1,
               op->reg_src1_value,
               op->reg_src2,
               op->reg_src2_value,
               op->reg_dst,
               op->reg_dst_value_ready,
                op->reg_dst_value,
               op->is_branch,
               op->branch_taken,
               op->branch_dest,
               op->is_mem,
               op->mem_addr);
    else
        printf("(null)\n");
}

/* global pipeline state */
Pipe_State pipe;

void pipe_init()
{
    memset(&pipe, 0, sizeof(Pipe_State));
    pipe.PC = 0x00400000;
}


void pipe_cycle()//周期
{
#ifdef DEBUG
    printf("\n\n----\n\nPIPELINE:\n");
    printf("DCODE: "); print_op(pipe.decode_op);
    printf("EXEC : "); print_op(pipe.execute_op);
    printf("MEM  : "); print_op(pipe.mem_op);
    printf("WB   : "); print_op(pipe.wb_op);
    printf("\n");
#endif

    pipe_stage_wb();
    pipe_stage_mem();
    pipe_stage_execute();
    pipe_stage_decode();
    pipe_stage_fetch();

    /* handle branch recoveries */
    if (pipe.branch_recover) {
#ifdef DEBUG
        printf("branch recovery: new dest %08x flush %d stages\n", pipe.branch_dest, pipe.branch_flush);
#endif

        pipe.PC = pipe.branch_dest;

        if (pipe.branch_flush >= 2) {
            if (pipe.decode_op) free(pipe.decode_op);
            pipe.decode_op = NULL;
        }

        if (pipe.branch_flush >= 3) {
            if (pipe.execute_op) free(pipe.execute_op);
            pipe.execute_op = NULL;
        }

        if (pipe.branch_flush >= 4) {
            if (pipe.mem_op) free(pipe.mem_op);
            pipe.mem_op = NULL;
        }

        if (pipe.branch_flush >= 5) {
            if (pipe.wb_op) free(pipe.wb_op);
            pipe.wb_op = NULL;
        }

        pipe.branch_recover = 0;
        pipe.branch_dest = 0;
        pipe.branch_flush = 0;

        stat_squash++;
    }
}

void pipe_recover(int flush, uint32_t dest)//覆盖
{
    /*如果已经计划了恢复，则它必须来自稍后的
    *阶段（执行较旧的指令），因此恢复覆盖
    *我们的恢复。在这种情况下，只需返回*/
    if (pipe.branch_recover) return;

    /*安排恢复。这将在所有管道阶段模拟当前循环后完成*/

    pipe.branch_recover = 1;
    pipe.branch_flush = flush;
    pipe.branch_dest = dest;
}

void pipe_stage_wb()//写回
{
    /*如果在这个流水线阶段没有指令，我们就完成了*/
    if (!pipe.wb_op)
        return;

    /*从我们的输入槽中取出op*/
    Pipe_Op *op = pipe.wb_op;
    pipe.wb_op = NULL;

    /*如果此指令写入寄存器，请立即执行*/
    if (op->reg_dst != -1 && op->reg_dst != 0) {
        pipe.REGS[op->reg_dst] = op->reg_dst_value;
#ifdef DEBUG
        printf("R%d = %08x\n", op->reg_dst, op->reg_dst_value);
#endif
    }

    /*如果这是系统调用，请执行操作*/
    if (op->opcode == OP_SPECIAL && op->subop == SUBOP_SYSCALL) {
        if (op->reg_src1_value == 0xA) {
            pipe.PC = op->pc; /*fetch将执行pc+=4，然后我们停止使用正确的pc*/
            RUN_BIT = 0;
        }
    }

    /*释放op*/
    free(op);

    stat_inst_retire++;
}

void pipe_stage_mem()//取操作数，访存
{
    /*如果在这个流水线阶段没有指令，我们就完成了*/
    if (!pipe.mem_op)
        return;

    /*从我们的输入槽中取出op*/
    Pipe_Op *op = pipe.mem_op;

    uint32_t val = 0;
//**********************************
    if (op->is_mem)
    {
        uint32_t theVal = data_cache_read_32(op->mem_addr & ~3);
        if (theVal == 0x0381CD55)
            return;
        val = theVal;
    }

    switch (op->opcode) {
        case OP_LW:
        case OP_LH:
        case OP_LHU:
        case OP_LB:
        case OP_LBU:
            {
                /*提取所需值*/
                op->reg_dst_value_ready = 1;
                if (op->opcode == OP_LW) {
                    op->reg_dst_value = val;
                }
                else if (op->opcode == OP_LH || op->opcode == OP_LHU) {
                    if (op->mem_addr & 2)
                        val = (val >> 16) & 0xFFFF;
                    else
                        val = val & 0xFFFF;

                    if (op->opcode == OP_LH)
                        val |= (val & 0x8000) ? 0xFFFF8000 : 0;

                    op->reg_dst_value = val;
                }
                else if (op->opcode == OP_LB || op->opcode == OP_LBU) {
                    switch (op->mem_addr & 3) {
                        case 0:
                            val = val & 0xFF;
                            break;
                        case 1:
                            val = (val >> 8) & 0xFF;
                            break;
                        case 2:
                            val = (val >> 16) & 0xFF;
                            break;
                        case 3:
                            val = (val >> 24) & 0xFF;
                            break;
                    }

                    if (op->opcode == OP_LB)
                        val |= (val & 0x80) ? 0xFFFFFF80 : 0;

                    op->reg_dst_value = val;
                }
            }
            break;
 
        case OP_SB:
        {
            switch (op->mem_addr & 3) {
            case 0: val = (val & 0xFFFFFF00) | ((op->mem_value & 0xFF) << 0); break;
            case 1: val = (val & 0xFFFF00FF) | ((op->mem_value & 0xFF) << 8); break;
            case 2: val = (val & 0xFF00FFFF) | ((op->mem_value & 0xFF) << 16); break;
            case 3: val = (val & 0x00FFFFFF) | ((op->mem_value & 0xFF) << 24); break;
            }
            //***************
            int result1 = data_cache_write_32(op->mem_addr & ~3, val);
            if(result1==0)
                return;
            //mem_write_32(op->mem_addr & ~3, val);
            break;
        }
        case OP_SH:
        {
#ifdef DEBUG
            printf("SH: addr %08x val %04x old word %08x\n", op->mem_addr, op->mem_value & 0xFFFF, val);
#endif
            if (op->mem_addr & 2)
                val = (val & 0x0000FFFF) | (op->mem_value) << 16;
            else
                val = (val & 0xFFFF0000) | (op->mem_value & 0xFFFF);
#ifdef DEBUG
            printf("new word %08x\n", val);
#endif
            //***************
            int result2 = data_cache_write_32(op->mem_addr & ~3, val);
            if (result2 == 0)
                return;
            //mem_write_32(op->mem_addr & ~3, val);
            break;
        }
        case OP_SW:
        {
            val = op->mem_value;
            int result3 = data_cache_write_32(op->mem_addr & ~3, val);
            if (result3 == 0)
                return;
            //mem_write_32(op->mem_addr & ~3, val);
            break;
        }
    }

    /*清除阶段输入并转移到下一阶段*/
    pipe.mem_op = NULL;
    pipe.wb_op = op;
}

void pipe_stage_execute()//执行
{
    /*如果正在进行乘法/除法，递减循环直到值准备就绪*/
    if (pipe.multiplier_stall > 0)
        pipe.multiplier_stall--;

    /*如果下游失速，返回（并留下我们的任何输入）*/
    if (pipe.mem_op != NULL)
        return;

    /*如果没有要执行的操作，则返回*/
    if (pipe.execute_op == NULL)
        return;

    /*抓取操作和读取源*/
    Pipe_Op *op = pipe.execute_op;

    /*读取寄存器值并检查旁路；必要时失速*/
    int stall = 0;
    if (op->reg_src1 != -1) {
        if (op->reg_src1 == 0)
            op->reg_src1_value = 0;
        else if (pipe.mem_op && pipe.mem_op->reg_dst == op->reg_src1) {
            if (!pipe.mem_op->reg_dst_value_ready)
                stall = 1;
            else
                op->reg_src1_value = pipe.mem_op->reg_dst_value;
        }
        else if (pipe.wb_op && pipe.wb_op->reg_dst == op->reg_src1) {
            op->reg_src1_value = pipe.wb_op->reg_dst_value;
        }
        else
            op->reg_src1_value = pipe.REGS[op->reg_src1];
    }
    if (op->reg_src2 != -1) {
        if (op->reg_src2 == 0)
            op->reg_src2_value = 0;
        else if (pipe.mem_op && pipe.mem_op->reg_dst == op->reg_src2) {
            if (!pipe.mem_op->reg_dst_value_ready)
                stall = 1;
            else
                op->reg_src2_value = pipe.mem_op->reg_dst_value;
        }
        else if (pipe.wb_op && pipe.wb_op->reg_dst == op->reg_src2) {
            op->reg_src2_value = pipe.wb_op->reg_dst_value;
        }
        else
            op->reg_src2_value = pipe.REGS[op->reg_src2];
    }

    /*如果旁路需要暂停（例如，在加载后立即使用），
    *无清除阶段输入的返回*/
    if (stall)
        return;

    /*执行操作*/
    switch (op->opcode) {
        case OP_SPECIAL:
            op->reg_dst_value_ready = 1;
            switch (op->subop) {
                case SUBOP_SLL:
                    op->reg_dst_value = op->reg_src2_value << op->shamt;
                    break;
                case SUBOP_SLLV:
                    op->reg_dst_value = op->reg_src2_value << op->reg_src1_value;
                    break;
                case SUBOP_SRL:
                    op->reg_dst_value = op->reg_src2_value >> op->shamt;
                    break;
                case SUBOP_SRLV:
                    op->reg_dst_value = op->reg_src2_value >> op->reg_src1_value;
                    break;
                case SUBOP_SRA:
                    op->reg_dst_value = (int32_t)op->reg_src2_value >> op->shamt;
                    break;
                case SUBOP_SRAV:
                    op->reg_dst_value = (int32_t)op->reg_src2_value >> op->reg_src1_value;
                    break;
                case SUBOP_JR:
                case SUBOP_JALR:
                    op->reg_dst_value = op->pc + 4;
                    op->branch_dest = op->reg_src1_value;
                    op->branch_taken = 1;
                    break;

                case SUBOP_MULT:
                    {
                        /*我们立即设置结果值；但是，我们会
                        *如果程序试图读取值，则模拟暂停
                        *在准备就绪之前（或覆盖HI/LO）。此外，如果
                        *稍后会有另一个乘法运算
                        *更新值并重新设置失速循环计数
                        *用于新操作。
                        */
                        int64_t val = (int64_t)((int32_t)op->reg_src1_value) * (int64_t)((int32_t)op->reg_src2_value);
                        uint64_t uval = (uint64_t)val;
                        pipe.HI = (uval >> 32) & 0xFFFFFFFF;
                        pipe.LO = (uval >>  0) & 0xFFFFFFFF;

                        /*四周期乘数延迟*/
                        pipe.multiplier_stall = 4;
                    }
                    break;
                case SUBOP_MULTU:
                    {
                        uint64_t val = (uint64_t)op->reg_src1_value * (uint64_t)op->reg_src2_value;
                        pipe.HI = (val >> 32) & 0xFFFFFFFF;
                        pipe.LO = (val >>  0) & 0xFFFFFFFF;

                        /*四周期乘数延迟*/
                        pipe.multiplier_stall = 4;
                    }
                    break;

                case SUBOP_DIV:
                    if (op->reg_src2_value != 0) {

                        int32_t val1 = (int32_t)op->reg_src1_value;
                        int32_t val2 = (int32_t)op->reg_src2_value;
                        int32_t div, mod;

                        div = val1 / val2;
                        mod = val1 % val2;

                        pipe.LO = div;
                        pipe.HI = mod;
                    } else {
                        //实际上，这将是一个除以0的异常
                        pipe.HI = pipe.LO = 0;
                    }

                    /*32周期分频器延迟*/
                    pipe.multiplier_stall = 32;
                    break;

                case SUBOP_DIVU:
                    if (op->reg_src2_value != 0) {
                        pipe.HI = (uint32_t)op->reg_src1_value % (uint32_t)op->reg_src2_value;
                        pipe.LO = (uint32_t)op->reg_src1_value / (uint32_t)op->reg_src2_value;
                    } else {
                        /* really this would be a div-by-0 exception */
                        pipe.HI = pipe.LO = 0;
                    }

                    /* 32-cycle divider latency */
                    pipe.multiplier_stall = 32;
                    break;

                case SUBOP_MFHI:
                    /*暂停直到值准备就绪*/
                    if (pipe.multiplier_stall > 0)
                        return;

                    op->reg_dst_value = pipe.HI;
                    break;
                case SUBOP_MTHI:
                    /* stall to respect WAW dependence */
                    /*暂停以尊重WAW依赖性*/

                    if (pipe.multiplier_stall > 0)
                        return;

                    pipe.HI = op->reg_src1_value;
                    break;

                case SUBOP_MFLO:
                    /* stall until value is ready */
                    if (pipe.multiplier_stall > 0)
                        return;

                    op->reg_dst_value = pipe.LO;
                    break;
                case SUBOP_MTLO:
                    /* stall to respect WAW dependence */
                    if (pipe.multiplier_stall > 0)
                        return;

                    pipe.LO = op->reg_src1_value;
                    break;

                case SUBOP_ADD:
                case SUBOP_ADDU:
                    op->reg_dst_value = op->reg_src1_value + op->reg_src2_value;
                    break;
                case SUBOP_SUB:
                case SUBOP_SUBU:
                    op->reg_dst_value = op->reg_src1_value - op->reg_src2_value;
                    break;
                case SUBOP_AND:
                    op->reg_dst_value = op->reg_src1_value & op->reg_src2_value;
                    break;
                case SUBOP_OR:
                    op->reg_dst_value = op->reg_src1_value | op->reg_src2_value;
                    break;
                case SUBOP_NOR:
                    op->reg_dst_value = ~(op->reg_src1_value | op->reg_src2_value);
                    break;
                case SUBOP_XOR:
                    op->reg_dst_value = op->reg_src1_value ^ op->reg_src2_value;
                    break;
                case SUBOP_SLT:
                    op->reg_dst_value = ((int32_t)op->reg_src1_value <
                            (int32_t)op->reg_src2_value) ? 1 : 0;
                    break;
                case SUBOP_SLTU:
                    op->reg_dst_value = (op->reg_src1_value < op->reg_src2_value) ? 1 : 0;
                    break;
            }
            break;

        case OP_BRSPEC:
            switch (op->subop) {
                case BROP_BLTZ:
                case BROP_BLTZAL:
                    if ((int32_t)op->reg_src1_value < 0) op->branch_taken = 1;
                    break;

                case BROP_BGEZ:
                case BROP_BGEZAL:
                    if ((int32_t)op->reg_src1_value >= 0) op->branch_taken = 1;
                    break;
            }
            break;

        case OP_BEQ:
            if (op->reg_src1_value == op->reg_src2_value) op->branch_taken = 1;
            break;

        case OP_BNE:
            if (op->reg_src1_value != op->reg_src2_value) op->branch_taken = 1;
            break;

        case OP_BLEZ:
            if ((int32_t)op->reg_src1_value <= 0) op->branch_taken = 1;
            break;

        case OP_BGTZ:
            if ((int32_t)op->reg_src1_value > 0) op->branch_taken = 1;
            break;

        case OP_ADDI:
        case OP_ADDIU:
            op->reg_dst_value_ready = 1;
            op->reg_dst_value = op->reg_src1_value + op->se_imm16;
            break;
        case OP_SLTI:
            op->reg_dst_value_ready = 1;
            op->reg_dst_value = (int32_t)op->reg_src1_value < (int32_t)op->se_imm16 ? 1 : 0;
            break;
        case OP_SLTIU:
            op->reg_dst_value_ready = 1;
            op->reg_dst_value = (uint32_t)op->reg_src1_value < (uint32_t)op->se_imm16 ? 1 : 0;
            break;
        case OP_ANDI:
            op->reg_dst_value_ready = 1;
            op->reg_dst_value = op->reg_src1_value & op->imm16;
            break;
        case OP_ORI:
            op->reg_dst_value_ready = 1;
            op->reg_dst_value = op->reg_src1_value | op->imm16;
            break;
        case OP_XORI:
            op->reg_dst_value_ready = 1;
            op->reg_dst_value = op->reg_src1_value ^ op->imm16;
            break;
        case OP_LUI:
            op->reg_dst_value_ready = 1;
            op->reg_dst_value = op->imm16 << 16;
            break;

        case OP_LW:
        case OP_LH:
        case OP_LHU:
        case OP_LB:
        case OP_LBU:
            op->mem_addr = op->reg_src1_value + op->se_imm16;
            break;

        case OP_SW:
        case OP_SH:
        case OP_SB:
            op->mem_addr = op->reg_src1_value + op->se_imm16;
            op->mem_value = op->reg_src2_value;
            break;
    }

    /* handle branch recoveries at this point */
    /*此时处理分支恢复*/

    if (op->branch_taken)
        pipe_recover(3, op->branch_dest);

    /* remove from upstream stage and place in downstream stage *//*从上游阶段移除并放置在下游阶段*/
    pipe.execute_op = NULL;
    pipe.mem_op = op;
}

void pipe_stage_decode()//指令解码，指令译码
{
    /*如果下游失速，返回（并留下我们的任何输入）*/
    if (pipe.execute_op != NULL)
        return;

    /*如果没有解码操作，则返回*/
    if (pipe.decode_op == NULL)
        return;

    /*抓取op并从舞台输入中移除*/
    Pipe_Op *op = pipe.decode_op;
    pipe.decode_op = NULL;

    /*根据需要设置信息字段（source/dest regs、immediate、jump dest）*/
    uint32_t opcode = (op->instruction >> 26) & 0x3F;
    uint32_t rs = (op->instruction >> 21) & 0x1F;
    uint32_t rt = (op->instruction >> 16) & 0x1F;
    uint32_t rd = (op->instruction >> 11) & 0x1F;
    uint32_t shamt = (op->instruction >> 6) & 0x1F;
    uint32_t funct1 = (op->instruction >> 0) & 0x1F;
    uint32_t funct2 = (op->instruction >> 0) & 0x3F;
    uint32_t imm16 = (op->instruction >> 0) & 0xFFFF;
    uint32_t se_imm16 = imm16 | ((imm16 & 0x8000) ? 0xFFFF8000 : 0);
    uint32_t targ = (op->instruction & ((1UL << 26) - 1)) << 2;

    op->opcode = opcode;
    op->imm16 = imm16;
    op->se_imm16 = se_imm16;
    op->shamt = shamt;

    switch (opcode) {
        case OP_SPECIAL:
            /*所有“SPECIAL”指令都是使用ALU和两个源的R类型
                         *规则。设置源寄存器和立即值*/
            op->reg_src1 = rs;
            op->reg_src2 = rt;
            op->reg_dst = rd;
            op->subop = funct2;
            if (funct2 == SUBOP_SYSCALL) {
                op->reg_src1 = 2; // v0
                op->reg_src2 = 3; // v1
            }
            if (funct2 == SUBOP_JR || funct2 == SUBOP_JALR) {
                op->is_branch = 1;
                op->branch_cond = 0;
            }

            break;

        case OP_BRSPEC:
            /* branches that have -and-link variants come here */
            /*这里有-和链接变体的分支*/

            op->is_branch = 1;
            op->reg_src1 = rs;
            op->reg_src2 = rt;
            op->is_branch = 1;
            op->branch_cond = 1; /* conditional branch */
            op->branch_dest = op->pc + 4 + (se_imm16 << 2);
            op->subop = rt;
            if (rt == BROP_BLTZAL || rt == BROP_BGEZAL) {
                /* link reg */
                /*链接寄存器*/

                op->reg_dst = 31;
                op->reg_dst_value = op->pc + 4;
                op->reg_dst_value_ready = 1;
            }
            break;

        case OP_JAL:
            op->reg_dst = 31;
            op->reg_dst_value = op->pc + 4;
            op->reg_dst_value_ready = 1;
            op->branch_taken = 1;
            /* fallthrough通过 */
        case OP_J:
            op->is_branch = 1;
            op->branch_cond = 0;
            op->branch_taken = 1;
            op->branch_dest = (op->pc & 0xF0000000) | targ;
            break;

        case OP_BEQ:
        case OP_BNE:
        case OP_BLEZ:
        case OP_BGTZ:
            /* ordinary conditional branches (resolved after execute) */
            /*普通条件分支（执行后解析）*/

            op->is_branch = 1;
            op->branch_cond = 1;
            op->branch_dest = op->pc + 4 + (se_imm16 << 2);
            op->reg_src1 = rs;
            op->reg_src2 = rt;
            break;

        case OP_ADDI:
        case OP_ADDIU:
        case OP_SLTI:
        case OP_SLTIU:
            /* I-type ALU ops with sign-extended immediates */
            /*I型ALU操作，带符号扩展立即数*/

            op->reg_src1 = rs;
            op->reg_dst = rt;
            break;

        case OP_ANDI:
        case OP_ORI:
        case OP_XORI:
        case OP_LUI:
            /* I-type ALU ops with non-sign-extended immediates */
            /*I型ALU操作，具有非符号扩展立即数*/

            op->reg_src1 = rs;
            op->reg_dst = rt;
            break;

        case OP_LW:
        case OP_LH:
        case OP_LHU:
        case OP_LB:
        case OP_LBU:
        case OP_SW:
        case OP_SH:
        case OP_SB:
            /* memory ops */
            /*存储器操作*/

            op->is_mem = 1;
            op->reg_src1 = rs;
            if (opcode == OP_LW || opcode == OP_LH || opcode == OP_LHU || opcode == OP_LB || opcode == OP_LBU) {
                /* load */
                op->mem_write = 0;
                op->reg_dst = rt;
            }
            else {
                /* store */
                op->mem_write = 1;
                op->reg_src2 = rt;
            }
            break;
    }

    /*我们将在执行阶段处理reg读取和旁路*/

    /*将op放置在下游插槽中*/
    pipe.execute_op = op;
}

void pipe_stage_fetch()//取指令
{
    /*如果管道被暂停（我们的输出槽不是空的），返回*/
    if (pipe.decode_op != NULL)
        return;

    //延迟操作iCache_read_count为全局变量，初值为50
    if (iCache_read_count > 0 && iCache_read_count < 50)
    {//正在延迟
        iCache_read_count--;
        //stat_inst_fetch++;
        //stat_inst_retire++;
        return;
    }

    if (iCache_read_count==0)
    {//延时结束，缺失替换
        Pipe_Op* op = malloc(sizeof(Pipe_Op));
        memset(op, 0, sizeof(Pipe_Op));
        op->reg_src1 = op->reg_src2 = op->reg_dst = -1;

        op->instruction = inst_cache_miss(pipe.PC);//指令cache缺失替换操作，取出指令内容
        op->pc = pipe.PC;
        pipe.decode_op = op;//将该指令放入流水线

        //更新PC
        pipe.PC += 4;
        stat_inst_fetch++;
        
        iCache_read_count = 50;//将延迟数字复位
        return;
    }

    //正常先从cache中找
    uint32_t the_inst = is_inst_cache_hit(pipe.PC);
    if (the_inst == 0x0381CD55)
    {//没有命中
        iCache_read_count--;
        
        //stat_inst_fetch++;
        //stat_inst_retire++;
        return;//之后执行延迟
    }
    else
    {//命中
        Pipe_Op* op = malloc(sizeof(Pipe_Op));
        memset(op, 0, sizeof(Pipe_Op));
        op->reg_src1 = op->reg_src2 = op->reg_dst = -1;
        
        op->instruction = the_inst;
        op->pc = pipe.PC;
        pipe.decode_op = op;

        //更新PC
        pipe.PC += 4;

        stat_inst_fetch++;
        return;
    }

   

    ///* allocate an op and send it down the pipeline. */
    //Pipe_Op *op = malloc(sizeof(Pipe_Op));
    //memset(op, 0, sizeof(Pipe_Op));
    //op->reg_src1 = op->reg_src2 = op->reg_dst = -1;

    //op->instruction = mem_read_32(pipe.pc);
    //op->pc = pipe.pc;
    //pipe.decode_op = op;

    ///* update pc */
    //pipe.pc += 4;

    //stat_inst_fetch++;
}
