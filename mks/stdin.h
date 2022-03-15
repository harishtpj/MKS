#ifndef STDIN_H
#define STDIN_H

#include "kbdmap.h"
#include "stdout.h"

#define CALC_SLEEP 50331647

uint8 inb(uint16 port) {
  uint8 ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
  return ret;
}

void outb(uint16 port, uint8 data) {
  asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
}

char get_input_keycode() {
  char ch = 0;
  while((ch = inb(KEYBOARD_PORT)) != 0){
    if(ch > 0)
      return ch;
  }
  return ch;
}

void wait_for_io(uint32 timer_count)
{
  while(1){
    asm volatile("nop");
    timer_count--;
    if(timer_count <= 0)
      break;
    }
}

void sleep(uint32 timer_count)
{
  wait_for_io(timer_count);
}

void input(char data[]) {
  char ch = 0;
  char keycode = 0;
  char *dataPtr = data;

  do{
    keycode = get_input_keycode();
    ch = get_ascii_char(keycode);
    if(ch == '\n') { ch = 0;}
    putchar(ch);
    *dataPtr++ = ch;
    sleep(CALC_SLEEP);
  }while(ch > 0);

  nl(); 
}

#endif