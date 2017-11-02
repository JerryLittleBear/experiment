#ifndef __MENU_H__
#define __MENU_H__

/*----------Add Command to Menu----------*/
int MenuConfig(char* cmd, char* desc, int (*handler)());

/*----------Menu Engine Execute----------*/
int ExecuteMenu();

#endif
