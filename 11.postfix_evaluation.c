#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct stack
{
    int top;
    int size;
    int *A;
}stack;
void push(stack *st,int data)
{
    if(st->top==st->size-1)
    {
        printf("Reallocating\n");
        st->A=realloc(st->A,2*sizeof(int)*st->size);
    }
    else
      st->A[++st->top]=data;
}
int pop(stack *st)
{
    return st->A[(st->top)--];
}
int prec(char a) //check if its operator or not
{
    if(a=='^' || a=='$') return 3;
    if(a=='*' || a=='/') return 2;
    if(a=='+' || a=='-') return 1;
    else return 0;
}
int operate(int op1, int op2, char a){
    switch(a){
        case '+': return op2+op1;
        case '-': return op2-op1;
        case '*': return op2*op1;
        case '/': return op2/op1;
        case '^': 
        case '$': return pow(op2,op1);
    }
}
void posteval(char exp[],int size)
{
    stack *st=malloc(sizeof(struct stack));
    st->top=-1;
    st->size=size;
    st->A=malloc(sizeof(int)*st->size);
    int i,d,op1,op2;
    char a;
    for(i=0;i<size;i++)
    {
        a=exp[i];
        if(prec(a)==0)
        {
            d=a-'0';
            push(st,d);
        }
        else if(prec(a)>0)
        {
            op1=pop(st);
            op2=pop(st);
            push(st,operate(op1,op2,a));
        }
    }
    printf("Postfix Evaluation is %d",st->A[st->top]);
}
void main()
{
    char exp[50];
    printf("Enter the expression\n");
    scanf("%s",exp);
    posteval(exp,strlen(exp));
}
