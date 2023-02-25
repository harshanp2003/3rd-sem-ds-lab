#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int top;
    int size;
    int a[100];
    
};


int F(char sym)
{
    switch(sym)
    {
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 4;
        case '^':
        case '$':return 5;
        case '(':return 0;
        case '#':return -1;
        default: return 8;
        
    }
}
int G(char sym)
{
    switch(sym)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 3;
        case '^':
        case '$':return 6;
        case '(':return 9;
        case ')':return 0;
       
        default: return 7;
    }
}
void topo(char in[],char po[])
{
   
    int i,j;
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->a[++sp->top]='#';
   // printf("%c",sp->a[sp->top]);
    char sym;
    j=0;
    for(i=0;i<strlen(in);i++)
    {
        
        sym=in[i];
        while(F(sp->a[sp->top]) >G(sym) )
        {
            po[j++]=sp->a[sp->top--];
        }
        if(F(sp->a[sp->top])!=G(sym))
        sp->a[++sp->top]=sym;
        else
        sp->top--;
    }
    
    while((sp->a[sp->top])!='#')
    {
        po[j++]=sp->a[sp->top--];
    }
    po[j]='\0';
}
void main()
{
    char in[20];
    char po[20];
    printf("Enter a valid expression\n");
    scanf("%s",in);
    topo(in,po);
    printf("The postfix expression\n");
    printf("%s",po);
}
