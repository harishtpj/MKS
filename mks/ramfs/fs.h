#ifndef FS_H
#define FS_H

#include "../stdout.h"
#include "../str.h"

typedef struct {
    char fname[15];
    char fcontent[10000];
    size_t size;
} file;

file fs[100];
int fsp = -1;
int fsc = 0;

void list_files() {
    if (fsp == -1){
        println("No Files Found.");
    } else {
        print("RAMFS Directory Listing");
        nl();
        // Filename      Size
        print("Filename            Size");
        nl();
        nl();
        for(int i = 0; i < fsc; i++){
            // fs[i].fname          fs[i].size
            print(fs[i].fname);
            putcn(' ', 20 - strlen(fs[i].fname));
            putint(fs[i].size);
            nl();
        }
        nl();
    }
}

void create_file(char* fname, char* fcontent) {
    file File;
    strcpy(File.fname, fname);
    strcpy(File.fcontent, fcontent);
    File.size = strlen(fcontent);
    fsp++;
    fs[fsp] = File;
    fsc++;
}

file* open_file(char fname[]) {
    int fp;
    for (int i = 0; i < fsc; i++) {
        if(strcmp(fs[i].fname, fname) == 0){
            fp = i;
            break;
        }
    }
    file* f = &fs[fp];
    return f;
}

void fread(file f, char cont[]){
    strcpy(cont, f.fcontent);
}

#endif