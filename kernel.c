/* MKS - Kernel File */
#include "mks/stdin.h"
#include "mks/stdout.h"
#include "mks/apps/shell.h"

void shell();
void exec(char cmd[]);
void banner();

int kernel() {
    char uname[10];

    terminal_init();
    clrscr();
    banner();
    nl();
    
    userinfo(uname);
    nl();
    shell(uname);

    
    return 0;
}