#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//using Pascal style to name the functions
void KnowAboutAuthor();
void Help();
void quit();
void SaySth();
void TalkToMe();
void GoToToilet();
void Minus();
void Multiply();

int main()
{
    char cmd[100];

    while(1)
    {
        printf("please input command: ");
        scanf("%s", cmd);
        getchar();
        if(!strcmp(cmd, "help"))
        {
            Help();
        }        
        else if(!strcmp(cmd, "knowauthor"))
        {
            KnowAboutAuthor();
        }       
        else if(!strcmp(cmd, "toilet"))
        {
            GoToToilet();
        }       
        else if(!strcmp(cmd, "minus"))
        {
            Minus();
        }       
        else if(!strcmp(cmd, "multiply"))
        {
            Multiply();
        }
        else if(!strcmp(cmd, "talk"))
        {
            TalkToMe();
        }
        else if(!strcmp(cmd, "sayhi"))
        {
            SaySth();
        }  
        else if(!strcmp(cmd, "quit"))
        {
            quit();
        }
        else
        {
            printf("wrong command,reinput\n");
        }
    }
    return 0;
}

void KnowAboutAuthor()
{
    printf("his name is Jerry, he loves helen\n");
}

void Help()
{
    printf("hi! you can use commands as follow:\n");
    printf("help\nquit\nknowauthor\ntoilet\ntalk\nsayhi\ntoilet\nminus\nmultiply\n");
}
void quit()
{
    printf("now, quit the program\n");
    exit(0); 
}
void SaySth()
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
void TalkToMe()
{
    char answer[20];

    printf("question No.1: if you are a boy or girl?\n");
    scanf("%s", answer);
    getchar();
    printf("this is a pretty %s.\n", answer);
}
void GoToToilet()
{
    printf("out of the door, turn left, is the toilet\n");
}
void Minus()
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
void Multiply()
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
