#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern void* _gc_alloc(size_t size);

char *strremove(char *str, int index) {
  char *newstr = _gc_alloc(sizeof(char) * strlen(str) + 1);
  strcpy(newstr, str);
  newstr[strlen(str)] = '\0';

  memmove(&newstr[index], &newstr[index + 1], strlen(newstr) - index);

  return newstr;
}

char *strinsert(char *destination, char *seed, int pos) {
  char* strC;

  strC = (char*)_gc_alloc(strlen(destination)+strlen(seed)+1);
  strncpy(strC,destination,pos);
  strC[pos] = '\0';
  strcat(strC,seed);
  strcat(strC,destination+pos);
  strcpy(destination,strC);

  return strC;
}

char *stradd(char *str1, char *str2) {
  char *str3 = (char*)_gc_alloc(strlen(str1) + strlen(str2) + 1);
  strcpy(str3, str1);
  strcat(str3, str2);

  return str3;
}

char* itos(int n) {
  char* string = _gc_alloc(sizeof(char)*10);
  sprintf(string, "%i", n);

  return string;
}

char* dtos(double n) {
  char* string = _gc_alloc(sizeof(char)*23);
  sprintf(string, "%g", n);

  return string;
}