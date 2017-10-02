#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"datastruct.h"

void help();
void quit();
void knowAboutAuthor();
void saySth();
void talkToMe();
void goToToilet();
void minus();
void multiply();

static FuncNode funcList[] =
{
    {"help", "this is help cmd!", help, &(funcList[1]) },
    {"quit", "quit the program!", quit, &(funcList[2]) },
    {"knowauthor", "tell you sth about author", knowAboutAuthor, &(funcList[3]) },
    {"sayhi", "to say sth casually", saySth, &(funcList[4]) },
    {"talk", "to say sth casually", talkToMe, &(funcList[5]) },
    {"toilet", "tell you how to go to the toilet", goToToilet, &(funcList[6]) },
    {"minus", "input 2 int, minus them", minus, &(funcList[7]) },
    {"multiply", "input 2 int, multiply them", multiply, &(funcList[8]) },
    {"version", "menu program v2.0", NULL, NULL }
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

void help()
{
    showAllCmd(funcList);
}
void quit()
{
    printf("now, quit the program\n");
    exit(0);
}
void knowAboutAuthor()
{
    printf("his name is Jerry, he loves helen\n");
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
