/* MKSlib - Standard Output header */
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

#ifndef STDOUT_H
#define STDOUT_H

#include "str.h"
#include <stdint.h>
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

uint16_t* terminal_buffer;

enum vga_colour {
    VGA_COLOUR_BLACK,
    VGA_COLOUR_BLUE,
    VGA_COLOUR_GREEN,
    VGA_COLOUR_CYAN,
    VGA_COLOUR_RED,
    VGA_COLOUR_MAGENTA,
    VGA_COLOUR_BROWN,
    VGA_COLOUR_LIGHT_GREY,
    VGA_COLOUR_DARK_GREY,
    VGA_COLOUR_LIGHT_BLUE,
    VGA_COLOUR_LIGHT_GREEN,
    VGA_COLOUR_LIGHT_CYAN,
    VGA_COLOUR_LIGHT_RED,
    VGA_COLOUR_LIGHT_MAGENTA,
    VGA_COLOUR_LIGHT_BROWN,
    VGA_COLOUR_WHITE,
};

void ungetchar();
void vga_set_cursor_pos(uint8 x, uint8 y);
void vga_disable_cursor();


static inline uint8_t vga_entry_colour(enum vga_colour foreground, enum vga_colour background){
    return foreground | (background << 4);
}

static inline uint16_t vga_entry(unsigned char c, uint8_t colour){
    return (uint16_t) c | ((uint16_t) colour << 8);
}

void terminal_putcharat(char c, uint16_t colour, size_t x, size_t y){
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, colour);
    vga_set_cursor_pos(x+1, y);
}

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_colour;
static uint8 cursor_pos_x = 0, cursor_pos_y = 0;

void clrscr(){
    for(size_t y = 0; y < VGA_HEIGHT; y++){
        for(size_t x = 0; x < VGA_WIDTH; x++){
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_colour);
        }
    }
    terminal_row = 0;
    terminal_column = 0;
    cursor_pos_x = 0;
    cursor_pos_y = 0;
    vga_set_cursor_pos(cursor_pos_x, cursor_pos_y);
}

void terminal_init(){
    terminal_row = 0;
    terminal_column = 0;
    cursor_pos_x = 0;
    cursor_pos_y = 0;
    terminal_colour = vga_entry_colour(VGA_COLOUR_WHITE, VGA_COLOUR_BLUE);
    terminal_buffer = (uint16_t *) 0xB8000;
    clrscr();
    //vga_disable_cursor();
}

void terminal_scroll_up(){
    int i;
    for(i = 0; i < (VGA_WIDTH*VGA_HEIGHT-80); i++)
        terminal_buffer[i] = terminal_buffer[i+80];
    for(i = 0; i < VGA_WIDTH; i++)
        terminal_buffer[(VGA_HEIGHT - 1) * VGA_WIDTH + i] = vga_entry(' ', terminal_colour);
}

void putchar(char c){
    if(terminal_column == VGA_WIDTH || c == '\n'){
        terminal_column = 0;
        if(terminal_row == VGA_HEIGHT-1){
            terminal_scroll_up();
        } else {
            terminal_row++;
        }
    }
    if(c == '\n') return;
    if(c == '\b') ungetchar();
    terminal_putcharat(c, terminal_colour, terminal_column++, terminal_row);
}
 
void terminal_write(const char* data, size_t size){
    for (size_t i = 0; i < size; i++)
        putchar(data[i]);
}

void print(char* data){
    terminal_write(data, strlen(data));
}

void println(char* data){
    strcat(data, "\n");
    terminal_write(data, strlen(data));
}

void nl(){
    print("\n");
}

void cprint(char* data, enum vga_colour fg, enum vga_colour bg){
    uint8_t oldcolour = terminal_colour;
    terminal_colour = vga_entry_colour(fg, bg);
    print(data);
    terminal_colour = oldcolour;
}
void cprintln(char* data, enum vga_colour fg, enum vga_colour bg){
    uint8_t oldcolour = terminal_colour;
    terminal_colour = vga_entry_colour(fg, bg);
    println(data);
    terminal_colour = oldcolour;
}

void putint(unsigned int n){
    if(n/10){
        putint(n/10);
    }
    putchar((n % 10) + '0');
}

void putcn(char c, int count){
    for (int i = 0; i < count; i++) {
        putchar(c);
    }
}

void ungetchar() {
    if((terminal_column * VGA_WIDTH + terminal_row) > 0) {
        terminal_putcharat(0, terminal_colour, terminal_column--, terminal_row);
    }

    // set last printed character to 0
    terminal_putcharat(' ', terminal_colour, terminal_column, terminal_row);
}

/**
 * write a given byte to given port number
 */
void outportb(uint16 port, uint8 val) {
    asm volatile("outb %1, %0" :: "dN"(port), "a"(val));
}

/**
 * read 2 bytes(short) from given port number
 */
uint16 inports(uint16 port) {
    uint16 rv;
    asm volatile ("inw %1, %0" : "=a" (rv) : "dN" (port));
    return rv;
}

/**
 * set cursor position to given (x, y)
 * by writing to CRT controller registers
 */
void vga_set_cursor_pos(uint8 x, uint8 y) {
    // The screen is 80 characters wide...
    uint16 cursorLocation = y * VGA_WIDTH + x;
    outportb(0x3D4, 14);
    outportb(0x3D5, cursorLocation >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, cursorLocation);
}

/**
 * disable blinking top-left cursor
 * by writing to CRT controller registers
 */
void vga_disable_cursor() {
    outportb(0x3D4, 10);
    outportb(0x3D5, 32);
}

#endif