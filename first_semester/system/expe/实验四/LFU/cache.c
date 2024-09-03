#include "cache.h"
#include "pipe.h"
#include "shell.h"
#include "mips.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


int data_cache_write_count = 50;
int data_cache_read_count = 50;
//标志初始化
int inst_cache_count = 0;
int data_cache_count = 0;

inst_cache iCache;
data_cache dCache;


//指令cache是否命中，命中返回指令
uint32_t is_inst_cache_hit(uint32_t address)//判断是否命中
{
    if (inst_cache_count == 0)
    {
        memset(&iCache, 0, sizeof(inst_cache));
        inst_cache_count++;
    }
    
    uint32_t sets_index = (address << 21) >> 26;//得到六位的组号

    int i;
    for (i = 0; i < 4; i++)//检查对应组中的四行
    {
        uint32_t tag = iCache.sets[sets_index].lines[i].tag;//取得每一行的标志位

        if (!(tag ^ (address >> 11)))//tag 位相同再检查 valid
        {
            if (iCache.sets[sets_index].lines[i].valid == 1)//有效位为一，命中
            {
                
                if (iCache.sets[sets_index].lines[i].LFU < 3)//需要更新LFU位
                    iCache.sets[sets_index].lines[i].LFU++;

                return iCache.sets[sets_index].lines[i].data[(address & 0x0000001f) >> 2];
                //address & 0x0000001f为address后五位（块内偏移量）
                //右移两位缩小四倍，即为四个字节单元的偏移量
            }
        }
    }
    return 0x0381CD55;//如果未命中
}



//指令cache缺失替换操作
uint32_t inst_cache_miss(uint32_t address)
{
    //从内存中取出缺失的块
    uint32_t block_address = address & 0xffffffe0;    //计算块地址，块中第一个字的地址
    uint32_t mem[8];
    int i;
    for (i = 0; i < 8; i++)
        mem[i] = mem_read_32(block_address + i * 4);

    //将取出的块放入cache中对应的组
    uint32_t sets_index = (address << 21) >> 26;    //计算组号

    //找组中的空行
    int j;
    for (j = 0; j < 4; j++)//有空行则将块放入
    {
        if (iCache.sets[sets_index].lines[j].valid == 0)//空位
        {
            iCache.sets[sets_index].lines[j].LFU = 0;    //LFU初始化为0
            iCache.sets[sets_index].lines[j].valid = 1;    //valid 置为有效
            iCache.sets[sets_index].lines[j].tag = address >> 11;    // 更新tag
            
            //将块放入数据区
            int k;
            for (k = 0; k < 8; k++)
                iCache.sets[sets_index].lines[j].data[k] = mem[k];

            return iCache.sets[sets_index].lines[j].data[(address & 0x0000001f) >> 2];//返回数据
        }
    }

    //没有空行的话，替换LFU最小的行
    int min_LFU_line = 0;
    int min_LFU = iCache.sets[sets_index].lines[0].LFU;
    int m;
    for (m = 1; m < 4; m++)    //寻找LFU最小的行
    {
        int theLFU = iCache.sets[sets_index].lines[m].LFU;
        if (theLFU < min_LFU)
        {
            min_LFU = theLFU;
            min_LFU_line = m;
        }
    }
    //替换该行内容
    iCache.sets[sets_index].lines[min_LFU_line].LFU = 0;
    iCache.sets[sets_index].lines[min_LFU_line].valid = 1;
    iCache.sets[sets_index].lines[min_LFU_line].tag = address >> 11;
    int n;
    for (n = 0; n < 8; n++)
        iCache.sets[sets_index].lines[min_LFU_line].data[n] = mem[n];

    return iCache.sets[sets_index].lines[min_LFU_line].data[(address & 0x0000001f) >> 2];
}




uint32_t data_cache_read_32(uint32_t address)
{
    printf("address1:%x\n", address);
    if (data_cache_count == 0)
    {//初始化
        memset(&dCache, 0, sizeof(data_cache));
    }
    data_cache_count++;

    uint32_t sets_index = (address << 19) >> 24;//计算组号

    //检查组中有无tag相同的行
    int i;
    for (i = 0; i < 8; i++)//判断是否命中
    {
        uint32_t tag = dCache.sets[sets_index].lines[i].tag;
        if (!(tag ^ (address >> 13)))
        {//tag位相同
            if (dCache.sets[sets_index].lines[i].valid == 1)
            {//命中
                //更新LFU
                if (dCache.sets[sets_index].lines[i].LFU < 7)
                    dCache.sets[sets_index].lines[i].LFU++;

                return dCache.sets[sets_index].lines[i].data[(address & 0x0000001f) >> 2];
            }
        }
    }
    //没命中
    if (data_cache_read_count != 0)
    {
        data_cache_read_count--;

        return 0x0381CD55;
    }
    data_cache_read_count = 50;//将延迟计数复位
    //miss操作
    uint32_t block_address = address & 0xffffffe0;//从内存中取出缺失的块
    uint32_t mem[8];
    int j;
    for (j = 0; j < 8; j++)
        mem[j] = mem_read_32(block_address + j * 4);
    
    //寻找空行
    int k;
    for (k = 0; k < 8; k++)
    {
        //找到空行装填入缺失块
        if (dCache.sets[sets_index].lines[k].valid == 0)
        {
            dCache.sets[sets_index].lines[k].valid = 1;
            dCache.sets[sets_index].lines[k].LFU = 0;
            dCache.sets[sets_index].lines[k].dirty = 0;
            dCache.sets[sets_index].lines[k].tag = address >> 13;
            int m;
            for (m = 0; m < 8; m++)
                dCache.sets[sets_index].lines[k].data[m] = mem[m];

            return dCache.sets[sets_index].lines[k].data[(address & 0x0000001f) >> 2];
        }
    }
    //没有空行，找LFU最小的行
    int min_LFU_line = 0;
    int min_LFU = dCache.sets[sets_index].lines[0].LFU;
    int n;
    for (n = 1; n < 8; n++)
    {
        int theLFU = dCache.sets[sets_index].lines[n].LFU;
        if (theLFU < min_LFU)
        {
            min_LFU = theLFU;
            min_LFU_line = n;
        }
    }

    //根据最小LFU行的dirty确定它是否需要写回
    if (dCache.sets[sets_index].lines[min_LFU_line].dirty == 1)
    {
        uint32_t sets_index_13 = sets_index;
        sets_index_13 << 5;//低5位是0，中间八位是组号，高位是0
        uint32_t block_address = (dCache.sets[sets_index].lines[min_LFU_line].tag << 13) | sets_index_13;
        for (i = 0; i < 8; i++)
            mem_write_32(block_address + i * 4, dCache.sets[sets_index].lines[min_LFU_line].data[i]);
    }

    //将该块替换
    dCache.sets[sets_index].lines[min_LFU_line].valid = 1;
    dCache.sets[sets_index].lines[min_LFU_line].LFU = 0;
    dCache.sets[sets_index].lines[min_LFU_line].dirty = 0;
    dCache.sets[sets_index].lines[min_LFU_line].tag = address >> 13;
    for (i = 0; i < 8; i++)
        dCache.sets[sets_index].lines[min_LFU_line].data[i] = mem[i];

    return dCache.sets[sets_index].lines[min_LFU_line].data[(address & 0x0000001f) >> 2];
}




uint32_t data_cache_write_32(uint32_t address, uint32_t value)
{
    if (data_cache_count == 0)//初始化
    {
        memset(&dCache, 0, sizeof(data_cache));
        data_cache_count++;
    }
    
    uint32_t sets_index = (address << 19) >> 24;//计算组号

    //检查组中有无tag相同的行
    int i;
    for (i = 0; i < 8; i++)
    {
        uint32_t tag = dCache.sets[sets_index].lines[i].tag;
        if (!(tag ^ (address >> 13)))
        {//tag相同
            if (dCache.sets[sets_index].lines[i].valid == 1)
            {//命中
                //更新LFU
                if (dCache.sets[sets_index].lines[i].LFU < 7)
                    dCache.sets[sets_index].lines[i].LFU++;
                dCache.sets[sets_index].lines[i].valid = 1;
                dCache.sets[sets_index].lines[i].dirty = 1;
                dCache.sets[sets_index].lines[i].data[(address & 0x0000001f) >> 2] = value;

                return 1;
            }
        }
    }

    //没命中
    if (data_cache_write_count != 0)
    {
        data_cache_write_count--;
        return 0;
    }

    data_cache_write_count=50;

    //miss 操作
    //从内存中取出缺失块
    uint32_t block_address = address & 0xffffffe0;
    uint32_t mem[8];
    int j;
    for (j = 0; j < 8; j++)
        mem[j] = mem_read_32(block_address + j * 4);

    //寻找空行
    int k;
    for (k = 0; k < 8; k++)
    {
        //找到空行填入缺失块
        if (dCache.sets[sets_index].lines[k].valid == 0)
        {
            dCache.sets[sets_index].lines[k].valid = 1;
            dCache.sets[sets_index].lines[k].LFU = 0;
            dCache.sets[sets_index].lines[k].dirty = 1;//脏位
            dCache.sets[sets_index].lines[k].tag = address >> 13;
            int m;
            for (m = 0; m < 8; m++)
                dCache.sets[sets_index].lines[k].data[m] = mem[m];
            dCache.sets[sets_index].lines[k].data[(address & 0x0000001f) >> 2] = value;

            return 1;
        }
    }

    //没有空行找最小
    int min_LFU_line = 0;
    int min_LFU = dCache.sets[sets_index].lines[0].LFU;
    int n;
    for (n = 1; n < 8; n++)
    {
        int theLFU = dCache.sets[sets_index].lines[n].LFU;
        if (theLFU < min_LFU)
        {
            min_LFU = theLFU;
            min_LFU_line = n;
        }
    }

    //根据最小LFU行的dirty确定它是否需要写回
    if (dCache.sets[sets_index].lines[min_LFU_line].dirty == 1)
    {
        uint32_t sets_index_13 = sets_index;
        sets_index_13 << 5;//低5位是0，中间八位是组号，高位是0
        uint32_t block_address = (dCache.sets[sets_index].lines[min_LFU_line].tag << 13) | sets_index_13;
        for (i = 0; i < 8; i++)
            mem_write_32(block_address + i * 4, dCache.sets[sets_index].lines[min_LFU_line].data[i]);
    }

    //将该块替换
    dCache.sets[sets_index].lines[min_LFU_line].valid = 1;
    dCache.sets[sets_index].lines[min_LFU_line].LFU = 0;
    dCache.sets[sets_index].lines[min_LFU_line].dirty = 1;
    dCache.sets[sets_index].lines[min_LFU_line].tag = address >> 13;

    for (i = 0; i < 8; i++)
        dCache.sets[sets_index].lines[min_LFU_line].data[i] = mem[i];

    dCache.sets[sets_index].lines[min_LFU_line].data[(address & 0x0000001f) >> 2] = value;

    return 1;//成功写入返回1
}

