#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define Maxsize 100

typedef union {
    float fData;
    char  cData;
} Item;

typedef struct {
    Item items[Maxsize];   
    int top;
} Stack;

void push(Stack *s,Item val);
Item pop(Stack *s);
int isEmpty(Stack *s);
Stack *initialize();
Item top(Stack *s);

#endif