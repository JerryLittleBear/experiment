#include <malloc.h>
#include "linktable.h"
/*-----------------------------创建链表-----------------------------*/
LinkTable* createLinkTable()
{
    LinkTable* ltTemp;
    ltTemp = (LinkTable* )malloc(sizeof(LinkTable));
    if(ltTemp == NULL)
    {    
        return ;
    }
    ltTemp->lHead = (LinkTableNode* )malloc(sizeof(LinkTableNode));
    if(ltTemp->lHead == NULL)
    {
        return ;
    }
    ltTemp->lTail = ltTemp->lHead;
    ltTemp->lHead->next = NULL;
    ltTemp->nodeNum = 0;

    return ltTemp;
}
/*-----------------------------删除链表-----------------------------*/
int deleteLinkTable(LinkTable* lt)
{
    LinkTableNode* node, * tempNode;
    
    node = lt->lHead;//node指向头指针
    while(node != NULL)
    {
        tempNode = node;
        free(node);
        node = tempNode->next;
    }
    free(lt);

    return 0;
}
/*-----------------------------增加链表结点-----------------------------*/
int addLinkTableNode(LinkTable* lt, LinkTableNode* node)
{
    lt->lTail->next = node;
    lt->lTail = node;
    lt->lTail->next = NULL;
    (lt->nodeNum)++;
    return 0;
}
/*-----------------------------删除链表结点-----------------------------*/
int deleteLinkTableNode(LinkTable* lt, LinkTableNode* node)
{
    LinkTableNode* n1, * n2;
    n1 = lt->lHead;
    n2 = lt->lHead->next;
    while(n1->next != node && n1->next->next != NULL)
    {
        n1 = n1->next;
    }
    n2 = n1->next;
    n1->next = n1->next->next;
    free(n2);
    return 0;
}
/*-----------------------------获取链表头指针-----------------------------*/
LinkTableNode* getLinkTableHead(LinkTable* lt)
{
    return lt->lHead;
}

LinkTableNode* getNextLinkTableNode(LinkTable* lt, LinkTableNode* node)
{
    return node->next;
}
