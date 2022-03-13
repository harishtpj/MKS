#include "maps/kbdmap.h"
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

void test_input()
{
  char ch = 0;
  char keycode = 0;
  do{
    keycode = get_input_keycode();
    if(keycode == KEY_ENTER){
      nl();
    }else{
      ch = get_ascii_char(keycode);
      putchar(2 * x + 160 * y ,ch);
		  x++;
    }
    sleep(0x02FFFFFF);
  }while(ch > 0);
}

void input(char data[]) {
  char ch = 0;
  char keycode = 0;
  int index = 0;

  do{
    keycode = get_input_keycode();
    if(keycode == KEY_ENTER){
      data[index] = '\0';
      nl();
      break;
    }else{
      ch = get_ascii_char(keycode);
      putchar(2 * x + 160 * y ,ch);
		  x++;
      data[index] = ch;
      index++;
    }
    sleep(CALC_SLEEP);
  }while(ch > 0);
}