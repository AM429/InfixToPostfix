#ifndef STACKTRACER_H_INCLUDED
#define STACKTRACER_H_INCLUDED
#include "stack.h"

void StackDump(Stack *s,int iter);
void printBytesBigEndian(unsigned char *pt,int n);
void printByte(unsigned char x);
void traceOperations(float a,float b, char op);

#endif