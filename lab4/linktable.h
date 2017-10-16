#ifndef __LINKTABLE_H__
#define __LINKTABLE_H__

#include <pthread.h>
//链表节点
typedef struct LinkTableNode
{
    struct LinkTableNode* next;
}LinkTableNode;
//链表结构，含链表头尾、长度等
typedef struct LinkTable
{
    struct LinkTableNode* lHead;
    struct LinkTableNode* lTail;
    int nodeNum;
    pthread_mutex_t mutex;//进程互斥锁
}LinkTable;

LinkTable* createLinkTable();

int deleteLinkTable(LinkTable* lt);

int addLinkTableNode(LinkTable* lt, LinkTableNode* node);

int deleteLinkTableNode(LinkTable* lt, LinkTableNode* node);

LinkTableNode* getLinkTableHead(LinkTable* lt);

LinkTableNode* getNextLinkTableNode(LinkTable* lt, LinkTableNode* node);
#endif
