#ifndef FSUTILS_H
#define FSUTILS_H

#include "../stdout.h"
#include "../stdin.h"
#include "fs.h"

void new_file() {
    char fname[15];
    char fterm[10];
    char fcont[10000];
    char fbuf[80];
    print("PLEASE ENTER FILE NAME: ");
    input(fname);
    print("ENTER FILE TERMINATOR: ");
    input(fterm);

    input(fbuf);
    while (strcmp(fbuf, fterm) != 0) {
        strcat(fbuf, "\n");
        strcat(fcont, fbuf);
        memset(fbuf, 0, sizeof(fbuf));
        input(fbuf);
    }

    create_file(fname, fcont);
    nl();
    print("SUCESSFULLY CREATED FILE ");
    println(fname);
    nl();
    
}

#endif