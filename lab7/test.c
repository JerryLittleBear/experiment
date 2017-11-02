#include"menu.h"
#include<string.h>
#include<stdio.h>

int main(int argc, char** argv)
{
    /*char* cmd;
    char* desc;
    int (*handler)();
    MenuConfig(cmd, desc, handler);
    MenuConfig(quit, );
    ExecuteMenu();*/
    printf("%d\n", argc);
    while(argc)
    {
        printf("%s\n", argv[--argc]);
    }
    return 0;
}
