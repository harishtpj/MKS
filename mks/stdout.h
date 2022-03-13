/* stdout.h - Standard Output of MKS */
#include "str.h"
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

void terminal_scroll_up();

char* fb = (char*) 0xB8000;
int x = 0;
int y = 0;

void clrscr() {
    unsigned int j = 0;
    while(j < VGA_WIDTH * VGA_HEIGHT * 2) {
		/* blank character */
		fb[j] = ' ';
		/* attribute-byte - light grey on black screen */
		fb[j+1] = 0x07; 		
		j = j + 2;
	}
}

void putc(unsigned int i, char c, unsigned char fg, unsigned char bg) {
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

void putchar(unsigned int i, char c) {
    fb[i] = c;
    fb[i + 1] = 0x07;
}

void print(char str[]) {
    int pos = 2 * x + 160 * y;
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        putchar(pos, str[i]);
        x++;
        pos = 2 * x + 160 * y;
    }
}
void println(char str[]) {
    int pos = 2 * x + 160 * y;
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        putchar(pos, str[i]);
        x++;
        pos = 2 * x + 160 * y;
    }
    x = 0;
    putchar(pos, ' ');
    y++;
}

void nl() {
    int pos = 2 * x + 160 * y;
    x = 0;
    putchar(pos, ' ');
    y++;
}

void putint(int num) {
  char str_num[digit_count(num)+1];
  itoa(num, str_num);
  println(str_num);
}