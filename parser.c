#include "stack.h"
#include <stdlib.h>
#include "Validation.h"
#include <math.h>
#include "parser.h"
#include <string.h>
#include "StackTracer.h"
#include <ctype.h>

#define _DEBUG 0


void infixToPostfix(char * infix, char * postfix) {
  Item x;
  char *infixDuplicate = _strdup(infix);
  Stack * s = initialize();
  char *ch = strtok(infixDuplicate, " ");   
  while (ch != NULL) {
    if(_DEBUG) StackDump(s,0);
    if (isalpha(ch[0]) || isdigit(ch[0])) {
        strcat(postfix, ch);
        strcat(postfix," ");

    }else if(ch[0]=='-' && isdigit(ch[1])||(ch[0]=='-' && ch[1]!='\0')){
        strcat(postfix, ch);
        strcat(postfix," ");
    } 
 
    else if (ch[0] == ')') {
        while (!isEmpty(s) && top(s).cData != '(') {
            char p= pop(s).cData;
            strncat(postfix,&p,1);
            strcat(postfix," ");
      }
      pop(s);
    }
    else if (ch[0] == '('){
          Item k; k.cData = ch[0];push(s,k);}

    else if (isOperator(ch[0])) {
    while (!isEmpty(s) && top(s).cData != '(' && (Prec(ch[0]) <= Prec(top(s).cData))){
        x = pop(s); char temp = x.cData;
        if (x.cData!='(')  strncat(postfix,&temp,1);strcat(postfix," ");}
        Item myitem;
        myitem.cData = ch[0];
        push(s, myitem);
    }
    ch = strtok(NULL, " ");
  }
  while (!isEmpty(s)) {char a =pop(s).cData; strncat(postfix,&a,1);strcat(postfix," ");}
  free(infixDuplicate);
}

/*
* evaluatePostfix: Evaluates an expression in postfix notation
* (Reverse-Polish Notation)
* ASSUME single-digit operands
*..a) If the element is a number, push it into the stack
*..b) If the element is a operator, pop operands for the operator from stack. 
*     Evaluate the operator and push the result back to the stack
*..c) When the expression is ended, the number in the stack is the final answer
*
* ex:  2# -2.5# 3.14# *-5.4#8.1# +-0.5^*+
*/
float evaluatePostfix(char* postfix) {
    Stack *s = initialize();
    char *tok;
    float y;
    Item x,res;
    char *DuplicatePostfix =  _strdup(postfix);  
    tok=strtok(DuplicatePostfix, " ");
    while(tok!=NULL){
        if(_DEBUG)StackDump(s,0);
        if (isdigit(tok[0])){
            x.fData=atof(tok);
            push(s,x);
        }
        else if(tok[0]=='-'&&tok[1]!='\0'){
            x.fData=strtof(tok,NULL);
            push(s,x);
        }else{
            float a=pop(s).fData;
            float b=pop(s).fData;
            res.fData=performOperation(a, b,tok[0]);
            if(_DEBUG)traceOperations(a,b,tok[0]);
            push(s,res);
        }
        tok=strtok(NULL," ");
    }
    y=pop(s).fData;free(DuplicatePostfix);
    if(!isEmpty(s)) error();
    return y;
}

float performOperation(float a, float b, const char op) {
        if (op == '+') {
            return a + b;
        } else if (op == '-') {
            return  b - a;
        } else if (op == '/') {
            return b/a;
        } else if (op == '*') {
            return b*a;
        } else if (op == '^') {
            return pow(b,a);
        } else {error(); return -999999.999999;}
}