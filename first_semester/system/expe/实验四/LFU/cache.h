
#include"shell.h"
#include <string.h>
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
    inst_cache_line lines[4];//一组四路
} inst_cache_sets;

typedef struct//指令cache
{
    inst_cache_sets sets[64];//64组
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
    data_cache_line lines[8];
}data_cache_sets;

typedef struct
{
    data_cache_sets sets[256];//256组
}data_cache;

//判断指令是否命中cache
uint32_t is_inst_cache_hit(uint32_t address);
//将块从内存中放入cache
uint32_t inst_cache_miss(uint32_t address);
//从cache中读取数据
uint32_t data_cache_read_32(uint32_t address);
//到cache中写数据
uint32_t data_cache_write_32(uint32_t address, uint32_t value);
