#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"datastruct.h"

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 8

void help();
void quit();

typedef struct FuncNode
{
    char* cmd;
    char* describe;
    void (*funcPointer)();
    struct FuncNode * next;
} FuncNode;

static FuncNode funcList[] =
{
    {"help", "this is help cmd!", help, &(funcList[1]) },
    {"quit", "quit the program!", quit, &(funcList[2]) },
    {"version", "menu program v2.0", NULL, NULL }
};

void findCmd(FuncNode* fn, char* cmd)
{
    FuncNode* fntemp = fn;
    int flag = 0;

    while(fntemp != NULL)
    {
        if(!strcmp(fntemp->cmd, cmd))
        {
            printf("%s\n", fntemp->describe);
            (fntemp->funcPointer)();
            flag = 1;
            return;
        }
        fntemp = fntemp->next;
    }
    if(flag == 0)
    {
        printf("couldn't find the command\n");
    }
    return;
};
int main()
{
/* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];

        printf("Input a cmd number >> ");
        scanf("%s", cmd);
        getchar();
        findCmd(funcList, cmd);
    }
    return 0;
}
void knowAboutAuthor()
{
    printf("his name is Jerry, he loves helen\n");
}

void help()
{
    printf("hi! you can use commands as follow:\n");
    printf("help\nquit\nknowauthor\ntoilet\ntalk\nsayhi\ntoilet\nminus\nmultiply\n");
}
void quit()
{
    printf("now, quit the program\n");
    exit(0);
}
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
}
