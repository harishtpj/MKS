/* MKS - The Main Kernel File */
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

#include "mks/stdin.h"
#include "mks/stdout.h"
#include "mks/apps/shell.h"

void shell();
void exec(char cmd[]);
void banner();

int kernel() {
    char uname[10];

    terminal_init();
    putint(strlen("Hello"));
    clrscr();
    banner();
    nl();
    
    userinfo(uname);
    nl();
    create_file("HELLO.TXT", "Hello, World!");
    create_file("WELCOME.TXT", "Welcome to MKS! This is the v1.0 of this OS.\n"
                                "This is just a sample text file inserted into\n"
                                "RAMFS File System.");

    shell(uname);

    
    return 0;
}