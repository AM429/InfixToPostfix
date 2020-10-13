#include <string.h> 
#include <stdlib.h>
#include "Validation.h"
#include "loadScreen.h"
#include <stdio.h>


int Prec(char ch) { 
    switch (ch) { 
    case '+': case '-': return 1; 
    case '*': case '/':  return 2; 
    case '^': return 3; 
    } 
    return 0; 
} 

void error() {
  printf("\x1b[31mError in expression\n\x1b[0m");
  delMe();
  exit(0);
}

void replaceNewLineBySpace(char* s) {
  char* s1 = s;
  while ((s1 = strstr(s1, "\n")) != NULL)
    *s1 = ' ';
}

int isOperator(char s) {
    return (s == '^' || s == '*' || s == '/' || s == '+' ||s == '-') ? 1 : 0;
}

void replaceOperator(char *str) {
  char *delm = "/^*", *f=delm;
  //printf("string length: %d\n",(int)strlen(str));
  while (*str) {
    f=delm;
    while(*f){if (!!strchr(str, *(f))) *str = ' ';f++;}
    if((*str=='+'||*str=='-') && (*(str+1)=='+'||*(str+1)=='-'))*str = ' ';
    str++;
  }
}