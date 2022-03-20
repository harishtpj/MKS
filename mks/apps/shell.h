/* MKS User Interaction Shell */
/* Copyright (c) 2022 M.V.Harish Kumar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

#ifndef SHELL_H
#define SHELL_H

#include "../stdin.h"
#include "../time.h"
#include "stack.h"
#include "../ramfs/fs.h"
#include "../ramfs/fsutils.h"

void userinfo(char uname[]){
    print("PLEASE ENTER YOUR NAME (UPTO 8 CHARS): ");
    input(uname);
    print("WELCOME, ");
    print(uname);
    println("!");
}

void help(){
    //print("");
    char opt[2];
    println("THIS HELP MENU IS CLASSIFIED INTO 3 TYPES:");
    print("BASIC - B\nSTACK - S\nFILE - F\n");
    print("ENTER YOUR OPTION: ");
    input(opt);
    if(strcmp(opt, "B") == 0) {
        print("PRINT   : PRINTS STRING");
        nl();
        print("CLR     : CLEARS SCREEN");
        nl();
        print("TIME    : SHOWS CMOS TIME(EXPERIMENTAL)");
        nl();
        print("VERSION : PRINTS OS VERSION");
        nl();
        print("EXIT    : EXIT AND SHUTDOWNS MKS");
        nl();
        print("HELP    : SHOWS HELP MSG");
        nl();
    }else if(strcmp(opt, "S") == 0) {
        print("PUSH    : PUSH UNSIGNED INT");
        nl();
        print("POP     : POP UNSIGNED INT");
        nl();
        print("PRSTK   : PRINT STACK");
        nl();
        print("ISE     : SAYS IF STACK IS EMPTY");
        nl();
        print("ISF     : SAYS IF STACK IS FULL");
        nl();
    } else if(strcmp(opt, "F") == 0) {
        print("DIR      : LIST FILES IN RAMFS");
        nl();
        print("TYPE     : PRINT CONTENTS OF FILE");
        nl();
        print("NEW FILE : CREATES NEW FILE");
        nl();
    } else {
        print("INVALID OPTION: ");
        println(opt);
    }

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
        println("This is MKS v1.0 created by M.V.Harish Kumar");
    } else if(strcmp(cmd, "PRINT") == 0){
        char printstr[50];
        print("PLEASE ENTER STR: ");
        input(printstr);
        println(printstr);
    } else if(strcmp(cmd, "HELP") == 0){
        help();
    } else if(strcmp(cmd, "TIME") == 0){
        get_time();
        print_time();
        nl();
    } else if(strcmp(cmd, "PUSH") == 0){
        char ni[50];
        print("PLEASE ENTER NO TO PUSH: ");
        input(ni);
        push(atoi(ni));
    } else if(strcmp(cmd, "PRSTK") == 0){
        printStack();
    } else if(strcmp(cmd, "POP") == 0){
        pop();
    } else if(strcmp(cmd, "ISE") == 0){
        if(isempty()) {
            println("TRUE");
        } else {
            println("FALSE");
        } 
    } else if(strcmp(cmd, "ISF") == 0){
        if(isfull()) {
            println("TRUE");
        } else {
            println("FALSE");
        } 
    } else if(strcmp(cmd, "DIR") == 0){
        list_files();
    } else if(strcmp(cmd, "TYPE") == 0){
        char fname[15];
        char fcont[10000];
        print("PLEASE ENTER FILE NAME: ");
        input(fname);
        file* f = open_file(fname);
        fread(*f, fcont);
        println(fcont);
    } else if(strcmp(cmd, "NEW FILE") == 0){
        new_file();
    } else {
        print("INVALID COMMAND: ");
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
    cprintln("|    CREATED BY M.V.HARISH KUMAR                   |", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
      cprint("  ", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
      cprint("|    ENTER ", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
      cprint("<HELP> ", VGA_COLOUR_RED, VGA_COLOUR_BLUE);
      cprintln("for more information             |", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
    cprintln("====================================================", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
}

#endif