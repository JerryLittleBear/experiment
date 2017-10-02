#include<stdio.h>
#include<stdlib.h>
#include"datastruct.h"

//the define
void findCmd(FuncNode* fn, char* cmd)
{
    FuncNode* fnTemp = fn;
    int flag = 0;

    while(fnTemp != NULL)
    {
        if(!strcmp(fnTemp->cmd, cmd))
        {
            //printf("%s\n", fnTemp->describe);
            (fnTemp->funcPointer)();
            flag = 1;
            return;
        }
        fnTemp = fnTemp->next;
    }
    if(flag == 0)
    {
        printf("couldn't find the command\n");
    }
    return;
}

void showAllCmd(FuncNode* fn)
{
    FuncNode* fnTemp = fn;
    while(fnTemp)
    {
        printf("%s----%s\n", fnTemp->cmd, fnTemp->describe);
        fnTemp = fnTemp->next;
    }
}
