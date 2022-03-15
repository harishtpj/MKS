/* MKS User Interact Shell */
#ifndef SHELL_H
#define SHELL_H

#include "../stdin.h"

void userinfo(char uname[]){
    print("PLEASE ENTER YOUR NAME (UPTO 8 CHARS): ");
    input(uname);
    print("WELCOME, ");
    print(uname);
    println("!");
}

void exec(char cmd[]) {
    if(strcmp(cmd, " ") == 0){
        nl();
    } else if(strcmp(cmd, "CLR") == 0){
        clrscr();
    } else if(strcmp(cmd, "EXIT") == 0){
        println("Stopping the CPU. Bye!");
        asm volatile("hlt");
    } else if(strcmp(cmd, "VERSION") == 0){
        println("This is MKS v1.0");
    } else if(strcmp(cmd, "PRINT") == 0){
        char printstr[50];
        print("PLEASE ENTER STR: ");
        input(printstr);
        println(printstr);
    } else {
        print("Invalid Command: ");
        println(cmd);
    }
}

void shell(char uname[]) {
    char cmd[30];

    for(;;){
        print(uname);
        print("@MKS $>>> ");
        memset(cmd, 0, strlen(cmd));
        input(cmd);
        exec(cmd);
    }
}

void banner() {
    cprintln("====================================================", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
    cprintln("|    WELCOME TO MKS - THE MINIMAL KERNEL SYSTEM    |", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
    cprintln("|    CREATED BY M.V.Harish KUMAR                   |", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
      cprint("  ", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
      cprint("|    ENTER ", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
      cprint("<help> ", VGA_COLOUR_RED, VGA_COLOUR_BLUE);
      cprintln("for more information             |", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
    cprintln("====================================================", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
}

#endif