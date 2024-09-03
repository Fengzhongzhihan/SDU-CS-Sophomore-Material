
#include"shell.h"
#include <string.h>
#include<math.h>
#define iline 2
#define dline 2
#define isets 2
#define dsets 2
#define isetMax 100010
#define dsetMax 100010
//指令cache
typedef struct
{
    int valid;//有效位
    int LRU;//判断如何选择替换的行
    uint32_t tag;//标志位
    uint32_t data[8];//数据区域，八个四字节
} inst_cache_line;

typedef struct//指令cache的一组
{
    inst_cache_line lines[iline];//一组2路
} inst_cache_sets;

typedef struct//指令cache
{
    inst_cache_sets sets[isetMax];//2组
} inst_cache;


//数据cache
typedef struct
{
    int valid;
    int LRU;
    int dirty;// 脏位,判断数据是否需要写回内存
    uint32_t tag;
    uint32_t data[8];
}data_cache_line;

typedef struct
{
    data_cache_line lines[dline];//一组两路
}data_cache_sets;

typedef struct
{
    data_cache_sets sets[isetMax];//8组
}data_cache;

//判断指令是否命中cache
uint32_t inst_cache_hit(uint32_t address);
//将块从内存中放入cache
uint32_t inst_cache_miss(uint32_t address);
//从cache中读取数据
uint32_t data_cache_read(uint32_t address);
//到cache中写数据
uint32_t data_cache_write(uint32_t address, uint32_t value);
