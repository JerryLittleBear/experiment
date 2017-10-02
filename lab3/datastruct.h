#ifndef __DATASTRUCT_H__
#define __DATASTRUCT_H__

//定义常量
#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 8

// 定义数据结构data struct and its operations
typedef struct FuncNode
{
    char* cmd;
    char* describe;
    void (*funcPointer)();
    struct FuncNode* next;
} FuncNode;

//函数声明
void findCmd(FuncNode*, char *);

#endif
