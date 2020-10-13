#include<stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Validation.h"
#include <string.h>
#include "loadScreen.h"


/*
 * infixToPostfix: converts an expression in infix notation to
 * to a postfix notation (Reverse-Polish Notation)
 * ASSUME single-digit operands
 * ASSUME ^*+-/ operators
 * e.g., 22+31 --> 22 31 +
 * e.g., (2+3)*4 --> 2 3 + 4 *
 */
//Driver Code
int main(int argc, char**argv){
    char EnableColor ='0'; // when this program is compiled in the same directory as it's source c files it overwrites is source code by setting this to 1 and deletes it's own exe, such that the program would not have to continously add to the registery eventhough it does not matter all that much. this was done for fun.
    char infixExpr[256] = "";///2+(-2.5*3.14)*(-5.4+8.1)^(-0.5)-8
    char postfixExpr[256] = "";//"2.0 -2.5 3.14 * -5.4 8.1 + -0.5 ^ * 8 - +";
    if(!(EnableColor-'0')){enableColor();}
    PrintSC();
    printf("Enter an expression you want to evaluate or Ctrl+Z to exit: ");
    while(fgets(infixExpr, 255, stdin) != NULL){
        replaceNewLineBySpace(infixExpr);
        infixToPostfix(infixExpr, postfixExpr); //function disabled temp
        printf("Postfix : %s\n", postfixExpr);
        float result = evaluatePostfix(postfixExpr);
        printf("Result: %f\n\n", result);
        clear();
        PrintSC();
        printf("Enter an expression you want to evaluate or Ctrl+Z to exit: ");
        memset(infixExpr,0,256);
        memset(postfixExpr,0,256);
    }
      if(!(EnableColor-'0')){delMe();}
    return 0;
}