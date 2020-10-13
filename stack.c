#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define Maxsize 100

/*
 * Item: An item that is being pushed to or popped from the stack
 * It may be float (to be used while evaluating the postfix)
 * It may be char (to be used while converting infix to postfix)
 */

Stack * initialize() {
  Stack * s = malloc(sizeof(Stack));
  s->top = 0;
  return s;
}
/*
 *
 */
int isEmpty(Stack * s) {
  return s->top ? 0 : 1;
}
/*
 *
 */
Item top(Stack * s) {
  if (!isEmpty(s))
    return s->items[s->top-1];
  else
    printf("\x1b[31mFailed\n\x1b[0m");
}
/*
 *
 */
Item pop(Stack * s) {
  return s->items[--s->top];
}
/*
 *
 */
void push(Stack * s, Item val) {
     if (s->top<Maxsize){
        s->items[s->top]=val;
        s->top = s->top +1 ;
    }
    else {
        printf("\x1b[31mSTACK FULL\n\x1b[0m");
    }
}