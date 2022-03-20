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

void append_file() {
    char fname[15];
    char fterm[10];
    char fcont[10000];
    char fbuf[80];
    print("PLEASE ENTER FILE NAME: ");
    input(fname);

    file* f = open_file(fname);
    if (strcmp(f->fname, " ") == 0) {
        print("NO FILE FOUND: "); 
        print(fname);
    } else {
        print("ENTER FILE TERMINATOR: ");
        input(fterm);

        input(fbuf);
        while (strcmp(fbuf, fterm) != 0) {
            strcat(fbuf, "\n");
            strcat(fcont, fbuf);
            memset(fbuf, 0, sizeof(fbuf));
            input(fbuf);
        }

        fwrite(f, 'a', fcont);
        nl();
        print("SUCESSFULLY APPENDED FILE ");
        println(fname);
    }
    nl();
    
}

void edit_file() {
    char fname[15];
    char fterm[10];
    char fcont[10000];
    char fbuf[80];
    print("PLEASE ENTER FILE NAME: ");
    input(fname);

    file* f = open_file(fname);
    if (strcmp(f->fname, " ") == 0) {
        print("NO FILE FOUND: "); 
        print(fname);
    } else {
        print("ENTER FILE TERMINATOR: ");
        input(fterm);

        input(fbuf);
        while (strcmp(fbuf, fterm) != 0) {
            strcat(fbuf, "\n");
            strcat(fcont, fbuf);
            memset(fbuf, 0, sizeof(fbuf));
            input(fbuf);
        }
        fwrite(f, 'w', fcont);
        nl();
        print("SUCESSFULLY EDITED FILE ");
        println(fname);
    }
    nl();
    
}

void delete_file() {
    char fname[15];
    print("PLEASE ENTER FILE NAME TO DELETE: ");
    input(fname);
    if (delfile(fname)) {
        print("SUCESSFULLY DELETED FILE ");
        println(fname);
    } else {
        print("NO FILE FOUND: "); 
        println(fname);
    }
}

void init_fs() {

    create_file("HELLO.TXT", "Hello, World!");
    create_file("WELCOME.TXT", "Welcome to MKS! This is the v2.0 of this OS.\n"
                               "This is just a sample text file inserted into\n"
                               "RAMFS File System.");
    create_file("SAMPLE.TXT", "THIS IS JUST A SAMPLE FILE PROVIDED FOR FILE FUNCTIONS.\n");

}

#endif