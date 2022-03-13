/* MKS - Kernel File */
#include "mks/stdin.h"

void shell(char cmd[]) {
    print("sysrt >>");
    print(" ");
    memset(cmd, 0, strlen(cmd));
    input(cmd);
    sleep(1);
    if(strcmp(cmd, "EXIT") == 0){
        println("Stopping the CPU. Bye!");
        asm volatile("hlt");
    } else if(strcmp(cmd, "CLR") == 0){
        clrscr();
    } else if(strcmp(cmd, "VERSION") == 0){
        println("This is MKS v1.0");
    } else {
        print("You Said: ");
        println(cmd);
    }
}

int kernel() {
    char cmd[30];
    clrscr();
    println("Welcome to MKS - The Minimal Kernel System");
    println("Created by M.V.Harish Kumar");
    println("Enter <help> for more information");
    
    
    for(;;) {
        shell(cmd);
    }
    
    return 0;
} 