#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

void infixToPostfix(char *infix,char *postfix);
float evaluatePostfix(char *postfix);
float performOperation(float a,float b,const char op);

#endif