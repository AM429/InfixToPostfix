#include "stack.h"
#include <stdio.h> 

void printByte(unsigned char x){
	unsigned char i, mask=0x80;
	for(i=0;i<8;i++,mask>>=1) if (mask&x) printf("1"); else printf("0");
	printf(" "); 
}

void printBytesBigEndian(unsigned char *pt, int n){
	n--;int i =n;
	while(i>=0) printf("%02x ",*(pt+i--));
	printf(": ");
	while(n>=0)printByte(*(pt+n--));printf("\n");
	
}

void traceOperations(float a,float b, char op){
	printf("Operations performed %f %c %f \n",b,op,a);
}

void StackDump(Stack* s, int iter) {
    printf("\n------------------Stack Dump----------------------at loop %d\n",iter);
    for (int i=0;i<s->top;i++){printf("float: %.20f\tchar: %c\t",s->items[i].fData,s->items[i].cData);printBytesBigEndian((unsigned char *)&s->items[i],sizeof(Item));}
    }