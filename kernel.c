/* MKS - Kernel File */
#include "mks/stdin.h"

void shell();
void exec(char cmd[]);
void banner();

int kernel() {
    terminal_init();
    clrscr();
    banner();
    nl();
    
    shell();
    
    return 0;
}

void shell() {
    char cmd[30];

    for(;;){
        print("sysrt >> ");
        memset(cmd, 0, strlen(cmd));
        input(cmd);
        exec(cmd);
    }
}

void exec(char cmd[]) {
    if(strcmp(cmd, "EXIT") == 0){
        println("Stopping the CPU. Bye!");
        asm volatile("hlt");
    } else if(strcmp(cmd, "CLR") == 0){
        clrscr();
    } else if(strcmp(cmd, "VERSION") == 0){
        println("This is MKS v1.0");
    } else {
        print("Invalid Command: ");
        println(cmd);
    }
}

void banner() {
    cprintln("====================================================", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
    cprintln("|    Welcome to MKS - The Minimal Kernel System    |", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
    cprintln("|    Created by M.V.Harish Kumar                   |", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
    cprintln("|    Enter <help> for more information             |", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
    cprintln("====================================================", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
}