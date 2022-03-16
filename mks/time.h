#ifndef TIME_H
#define TIME_H

#include "stdout.h"

#define CMOS_READ(addr) ({ \
outb_p(0x80|addr,0x70); \
inb_p(0x71); \
})

#define outb_p(value,port) \
__asm__ ("outb %%al,%%dx\n" \
                "\tjmp 1f\n" \
                "1:\tjmp 1f\n" \
                "1:"::"a" (value),"d" (port))

#define inb_p(port) ({ \
unsigned char _v; \
__asm__ volatile ("inb %%dx,%%al\n" \
        "\tjmp 1f\n" \
        "1:\tjmp 1f\n" \
        "1:":"=a" (_v):"d" (port)); \
_v; \
})

#define outb(value,port) \
__asm__ ("outb %%al,%%dx"::"a" (value),"d" (port))


#define inb(port) ({ \
unsigned char _v; \
__asm__ volatile ("inb %%dx,%%al":"=a" (_v):"d" (port)); \
_v; \
})


int sec, min, hrs, day, month, yr, cent;

void get_time() {
    sec = CMOS_READ(0);
    min = CMOS_READ(2);
    hrs = CMOS_READ(4);
    day = CMOS_READ(7);
    month = CMOS_READ(8);
    yr = CMOS_READ(9);
    cent = CMOS_READ(32);

    if (sec > 60) {
        min += sec / 60;
        sec = sec % 60;
    }
    
}

void print_date() {
    putint(day);
    putchar('/');
    putint(month);
    putchar('/');
    putint(cent);
    putint(yr); 
}

void print_time(){
    putint(hrs);
    putchar(':');
    putint(min);
    putchar(':');
    putint(sec);
}

#endif