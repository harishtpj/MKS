/* MKStack */
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