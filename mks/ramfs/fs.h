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

int get_file_index(char fname[]) {
    int fp = -1;
    for (int i = 0; i < fsc; i++) {
        if(strcmp(fs[i].fname, fname) == 0){
            fp = i;
            break;
        }
    }
    return fp;
}

file* open_file(char fname[]) {
    int fp = get_file_index(fname);
    if (fp == -1) { 
        file File;
        strcpy(File.fname, " ");
        strcpy(File.fcontent," ");
        File.size = 0;
        file* f = &File;
        return f;
    } else {
       file* f = &fs[fp];
       return f;
    }
}

void fread(file* f, char cont[]){
    strcpy(cont, f->fcontent);
}

void fwrite(file* f, char mode, char cont[]){
    if (mode == 'w') {
        strcpy(f->fcontent, cont);
        f->size = strlen(f->fcontent);
    } else if (mode == 'a') {
        strcat(f->fcontent, cont);
        f->size = strlen(f->fcontent);
    }
}

int delfile(char* fname) {
    int fp = get_file_index(fname);
    if (fp == -1) { 
        return 0;
    } else {
       for (int i = fp-1; i  < fsc - 1; i++) {
        fs[i] = fs[i + 1];
       }
       fsc--;
       return 1;
    }
}

#endif