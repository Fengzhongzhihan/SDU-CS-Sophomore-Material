#ifndef _PIPE_H_
#define _PIPE_H_

#include "shell.h"

/* 流水线操作（此结构的实例）是流经流水线的指令的高级表示。
 * 此结构与实际通过流水线的控制信号不是一对一对应的。
 * 它承载原始指令、操作数信息和收集的值，以及目的地信息。 */
typedef struct Pipe_Op {
    /* 此指令的程序计数器 */
    uint32_t pc;
    /* 原始指令 */
    uint32_t instruction;
    /* 解码后的操作码和子操作码字段 */
    int opcode, subop;

    /* 立即数值（如果有的话，用于ALU立即数） */
    uint32_t imm16, se_imm16;
    /* 移位量 */
    int shamt;

    /* 寄存器源值 */
    int reg_src1, reg_src2; /* 如果此指令有寄存器源，则为 0 -- 31，否则为 -1 */
    uint32_t reg_src1_value, reg_src2_value; /* 来自源寄存器的操作数值 */

    /* 内存访问信息 */
    int is_mem;       /* 是否为加载/存储指令？ */
    uint32_t mem_addr; /* 地址（如果适用） */
    int mem_write; /* 是否写入内存？ */
    uint32_t mem_value; /* 从内存加载的值或要写入内存的值 */

    /* 寄存器目的地信息 */
    int reg_dst; /* 如果此指令有目的地寄存器，则为 0 -- 31，否则为 -1 */
    uint32_t reg_dst_value; /* 写入目的地寄存器的值 */
    int reg_dst_value_ready; /* 目的地值是否已产生？ */

    /* 分支信息 */
    int is_branch;        /* 是否为分支？ */
    uint32_t branch_dest; /* 分支目的地（如果被执行） */
    int branch_cond;      /* 是否为条件分支？ */
    int branch_taken;     /* 分支是否被执行？（尽快解决：在解码时为无条件分支，在执行时为条件分支） */
    int is_link;          /* 跳转和链接或分支和链接指令？ */
    int link_reg;         /* 放置链接内容的寄存器？ */

} Pipe_Op;

/* 流水线状态表示流水线的当前状态。
 * 它保存指向每个阶段输入处的操作的指针。
 * 随着阶段的执行，它们会将操作从其输入中移除（将指针设置为NULL），
 * 并将操作放置到其输出中。
 * 如果阶段执行时表示阶段输出的指针不为空，则表示流水线停顿，
 * 并且该阶段不能覆盖其输出（否则将丢失一条指令）。 */
typedef struct Pipe_State {
    /* 当前位于给定阶段输入处的流水线操作（无操作为NULL） */
    Pipe_Op *decode_op, *execute_op, *mem_op, *wb_op;

    /* 寄存器文件状态 */
    uint32_t REGS[32];
    uint32_t HI, LO;

    /* 获取阶段中的程序计数器 */
    uint32_t PC;

    /* 用于PC更新的信息（分支恢复）。
     * 分支应使用此机制重定向获取阶段，并根据需要清除分支后的操作。 */
    int branch_recover; /* 设置为 '1' 以加载新的PC */
    uint32_t branch_dest; /* 下一个获取将从此PC开始 */
    int branch_flush; /* 在恢复期间清除多少个阶段？（1 = 获取，2 = 获取/解码，...） */

    /* 乘法器停顿信息 */
    int multiplier_stall; /* 直到HI/LO准备就绪的剩余周期数 */

    /* 根据需要放置其他信息 */

} Pipe_State;

/* 全局变量 -- 流水线状态 */
extern Pipe_State pipe;

/* 在模拟器启动期间调用 */
void pipe_init();

/* 此函数调用其他函数 */
void pipe_cycle();

/* 辅助函数：流水线阶段可调用此函数来安排分支恢复 */
/* 清除 'flush' 个阶段（1 = 仅执行，2 = 获取/解码，...），
 * 然后将获取PC设置为给定目标。 */
void pipe_recover(int flush, uint32_t dest);

/* 每个函数实现流水线的一个阶段 */
void pipe_stage_fetch();
void pipe_stage_decode();
void pipe_stage_execute();
void pipe_stage_mem();
void pipe_stage_wb();

#endif
