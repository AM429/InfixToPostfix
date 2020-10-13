#ifndef VALIDATION_H_INCLUDED
#define VALIDATION_H_INCLUDED

int Prec(char ch);
void error();
void replaceNewLineBySpace(char *s);
int isOperator(char s);
void replaceOperator(char *str);
#endif