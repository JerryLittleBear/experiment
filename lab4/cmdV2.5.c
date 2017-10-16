#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linktable.h"

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

typedef struct CmdNode
{
    LinkTableNode* next;
    char* cmd;
    char* desc;
    void (*funcPointer)();
}CmdNode;

void help();
void quit();
void version();
void knowAboutAuthor();
void saySth();
void talkToMe();
void goToToilet();
void minus();
void multiply();
CmdNode* findCmd(LinkTable* lt, char* cmd);
int initMenuData(LinkTable** lt);
void showAllCmd();

LinkTable* lt;//把存储命令的链表定义为全局变量会比较好

/*-----------------------------主函数-----------------------------*/
int main()
{
    initMenuData(&lt);
    CmdNode* cn;

    while(1)
    {
        char cmd[CMD_MAX_LEN];

        printf("Input a cmd number >> ");
        scanf("%s", cmd);
        getchar();
        cn = findCmd(lt, cmd);
        cn->funcPointer();
    }
    return 0;
}
/*-----------------------------在链表中寻找命令-----------------------------*/
CmdNode* findCmd(LinkTable* lt, char* cmd)
{
    CmdNode* cn = (CmdNode*)((CmdNode* )getLinkTableHead(lt))->next;//类型转换的应用。在这里，先获取lt->lHead，转换为CmdNode指针类型，再指向下一个结点，
    
    while(cn != NULL)
    {
        if(!strcmp(cn->cmd, cmd))
        {
            return cn;
        }
        cn = (CmdNode* )getNextLinkTableNode(lt, (LinkTableNode* )cn);
    }
    return NULL;
}
/*-----------------------------将所有命令输入链表-----------------------------*/
int initMenuData(LinkTable** lt)
{
    *lt = createLinkTable();

    CmdNode* cn = (CmdNode*)malloc(sizeof(CmdNode));
    cn->cmd = "help";
    cn->desc = "this is help command";
    cn->funcPointer = help;
    addLinkTableNode(*lt, (LinkTableNode*)cn);//强制类型转换的应用

    cn = (CmdNode*)malloc(sizeof(CmdNode));
    cn->cmd = "knowauthor";
    cn->desc = "know about author";
    cn->funcPointer = knowAboutAuthor;
    addLinkTableNode(*lt, (LinkTableNode*)cn);

    cn = (CmdNode*)malloc(sizeof(CmdNode));
    cn->cmd = "quit";
    cn->desc = "quit program";
    cn->funcPointer = quit;
    addLinkTableNode(*lt, (LinkTableNode*)cn);

    cn = (CmdNode*)malloc(sizeof(CmdNode));
    cn->cmd = "version";
    cn->desc = "show version of the program";
    cn->funcPointer = version;
    addLinkTableNode(*lt, (LinkTableNode*)cn);

    cn = (CmdNode*)malloc(sizeof(CmdNode));
    cn->cmd = "toilet";
    cn->desc = "how to go to toilet";
    cn->funcPointer = goToToilet;
    addLinkTableNode(*lt, (LinkTableNode*)cn);

    cn = (CmdNode*)malloc(sizeof(CmdNode));
    cn->cmd = "minus";
    cn->desc = "input two integer, minus them";
    cn->funcPointer = minus;
    addLinkTableNode(*lt, (LinkTableNode*)cn);

    cn = (CmdNode*)malloc(sizeof(CmdNode));
    cn->cmd = "multiply";
    cn->desc = "input two integer, multiply them";
    cn->funcPointer = multiply;
    addLinkTableNode(*lt, (LinkTableNode*)cn);

    return 0;
}
/*-----------------------------显示所有命令及其描述-----------------------------*/
void showAllCmd(LinkTable* lt)
{
    CmdNode* node = (CmdNode*)(lt->lHead->next);
    while(node != NULL)
    {
        printf("    %s————%s\n", node->cmd, node->desc);
        node = (CmdNode* )getNextLinkTableNode(lt, (LinkTableNode* )node);
    }
}
/*-----------------------------"help"命令-----------------------------*/
void help()
{
    printf("/*-----------------command list-----------------*/\n");
    showAllCmd(lt);
    printf("/*-----------------command list-----------------*/\n");
}
/*-----------------------------"quit"命令-----------------------------*/
void quit()
{
    printf("now, quit the program\n");
    exit(0);
}
/*-----------------------------"version"命令-----------------------------*/
void version()
{
    printf("menu V2.5\n");
}
/*-----------------------------"knowauthor"命令-----------------------------*/
void knowAboutAuthor()
{
    printf("his name is Jerry, he loves helen\n");
}
/*-----------------------------另一些自定义命令-----------------------------*/
void saySth()
{
    int i;
    char sentenceDuplicate[128];//using the lowCamel style to name a variable

    printf("no matter what you say, I will repeat your sentence 3 times, lol!\n");
    scanf("%s", sentenceDuplicate);
    getchar();//吸收输入缓冲区里的回车符
    for(i = 0;i < 3;i++)
    {
        printf("No.%d round repetition: %s\n", i, sentenceDuplicate);
    }

}
void talkToMe()
{
    char answer[20];

    printf("question No.1: if you are a boy or girl?\n");
    scanf("%s", answer);
    getchar();
    printf("this is a pretty %s.\n", answer);
}
void goToToilet()
{
    printf("out of the door, turn left, is the toilet\n");
}
void minus()
{
    int integer1, integer2;

    printf("please input first integer:\\");
    scanf("%d", &integer1);
    getchar();
    printf("please input second integer:\\");
    scanf("%d", &integer2);
    getchar();
    printf("the resule is %d\n", integer1 - integer2);
}
void multiply()
{
    int integer1, integer2;

    printf("please input first integer:\\");
    scanf("%d", &integer1);
    getchar();
    printf("please input second integer:\\");
    scanf("%d", &integer2);
    getchar();
    printf("the resule is %d\n", integer1 * integer2);
}
