#include"menu.h"
#include<string.h>
#include<stdio.h>
#include<unistd.h>

int Hello(int argc, char** argv)
{
    const char * optString = "abc";
    opterr = 0;
    int opt;
    while((opt = getopt(argc, argv, optString)) != -1)
    {
        switch(opt)
        {
            case 'a':
                printf("method a\n");
                break;
            case 'b':
                printf("method b\n");
                break;
            default:
                break;
        }
    }
    optind = 0;	
    return 0;
}

int main(int argc, char** argv)
{
    /*char* cmd;
    char* desc;
    int (*handler)();*/
    MenuConfig("help", "This is help cmd", Help);
    MenuConfig("quit", "Quit the program", Quit);
    MenuConfig("hello", "This is a test cmd", Hello);
    ExecuteMenu();
    return 0;
}
