/* MKStack - Stack Operations */
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

#ifndef STACK_H
#define STACK_H

#include "../stdout.h"
#define STACK_SIZE 10

int count = 0;

// Creating a stack
int stack[STACK_SIZE];
int top = -1;

// Check if the stack is full
int isfull() {
  if (top == STACK_SIZE - 1)
    return 1;
  else
    return 0;
}

// Check if the stack is empty
int isempty() {
  if (top == -1)
    return 1;
  else
    return 0;
}

// Add elements into stack
void push(int newitem) {
  if (isfull()) {
    println("STACK FULL");
  } else {
    top++;
    stack[top] = newitem;
  }
  count++;
}

// Remove element from stack
void pop() {
  if (isempty()) {
    println("\n STACK EMPTY \n");
  } else {
    print("ITEM POPPED = ");
    putint(stack[top]);
    top--;
  }
  count--;
  nl();
}

// Print elements of stack
void printStack() {
  print("STACK: ");
  for (int i = 0; i < count; i++) {
    putint(stack[i]);
    putchar(' ');
  }
  nl();
}

#endif