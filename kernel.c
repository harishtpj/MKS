/* MKS - Kernel File */
#include "mks/stdin.h"

int kernel() {
    char cmd[30];
    clrscr();
    println("Welcome to MKS - The Minimal Kernel System");
    println("Created by M.V.Harish Kumar");
    println("Enter <help> for more information");
    
    for(;;) {
        print("sysrt >> ");
        memset(cmd, 0 , sizeof(cmd));
        input(cmd);
        if(strcmp(cmd, "EXIT") == 0){
            println("Stopping the CPU. Bye!");
            asm volatile("hlt");
        } else {
            print("You Said: ");
            println(cmd);
        }
        
    }
    
    return 0;
}