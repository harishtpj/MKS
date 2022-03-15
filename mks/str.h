#ifndef STR_H
#define STR_H

#include <stddef.h>
#include <stdbool.h>

size_t strlen (char *str) {
    return (*str) ? strlen(++str) + 1 : 0;
}

char* strcat(char* destination, const char* source) {
    // make `ptr` point to the end of the destination string
    char* ptr = destination + strlen(destination);
 
    // appends characters of the source to the destination string
    while (*source != '\0') {
        *ptr++ = *source++;
    }
 
    // null terminate destination string
    *ptr = '\0';
 
    // the destination is returned by standard `strcat()`
    return destination;
}

char* strcpy(char* destination, const char* source) {
    // return if no memory is allocated to the destination
    if (destination == NULL) {
        return NULL;
    }
 
    // take a pointer pointing to the beginning of the destination string
    char *ptr = destination;
 
    // copy the C-string pointed by source into the array
    // pointed by destination
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
 
    // include the terminating null character
    *destination = '\0';
 
    // the destination is returned by standard `strcpy()`
    return ptr;
}

int strcmp(const char *X, const char *Y) {
    while (*X)
    {
        // if characters differ, or end of the second string is reached
        if (*X != *Y) {
            break;
        }
 
        // move to the next pair of characters
        X++;
        Y++;
    }
 
    // return the ASCII difference after converting `char*` to `unsigned char*`
    return *(const unsigned char*)X - *(const unsigned char*)Y;
}

uint32 digit_count(int num){
  uint32 count = 0;
  if(num == 0)
    return 1;
  while(num > 0){
    count++;
    num = num/10;
  }
  return count;
}

void itoa(int num, char *number) {
  int dgcount = digit_count(num);
  int index = dgcount - 1;
  char x;
  if(num == 0 && dgcount == 1){
    number[0] = '0';
    number[1] = '\0';
  }else{
    while(num != 0){
      x = num % 10;
      number[index] = x + '0';
      index--;
      num = num / 10;
    }
    number[dgcount] = '\0';
  }
}

void *memset(void *s, int c,  unsigned int len){
    unsigned char* p=s;
    while(len--)
    {
        *p++ = (unsigned char)c;
    }
    return s;
}

bool is_delim(char c, char *delim) {
  while(*delim != '\0')
  {
    if(c == *delim)
      return true;
    delim++;
  }
  return false;
}

char *strtok(char *s, char *delim) {
  static char *p; // start of the next search 
  if(!s)
  {
    s = p;
  }
  if(!s)
  {
    // user is bad user 
    return NULL;
  }

  // handle beginning of the string containing delims
  while(1)
  {
    if(is_delim(*s, delim))
    {
      s++;
      continue;
    }
    if(*s == '\0')
    {
      return NULL; // we've reached the end of the string
    }
    // now, we've hit a regular character. Let's exit the
    // loop, and we'd need to give the caller a string
    // that starts here.
    break;
  }

  char *ret = s;
  while(1)
  {
    if(*s == '\0')
    {
      p = s; // next exec will return NULL
      return ret;
    }
    if(is_delim(*s, delim))
    {
      *s = '\0';
      p = s + 1;
      return ret;
    }
    s++;
  }
}

char *strchr(char *s, char c) {
   while(*s != c && *s != '\0') {
      s++;
   }
   if(*s == c) {
      return s;
   }else {
      return NULL;
   }
}

long atoi(const char* S) {
    long num = 0;
 
    int i = 0;
 
    // run till the end of the string is reached, or the
    // current character is non-numeric
    while (S[i] && (S[i] >= '0' && S[i] <= '9'))
    {
        num = num * 10 + (S[i] - '0');
        i++;
    }
 
    return num;
}

#endif