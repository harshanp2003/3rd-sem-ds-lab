#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int size;
    int s[5];
    
};
void Pop(struct stack *st )
{
    int y;
    if(st->top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        y=st->s[st->top];
        st->top--;
        printf("\n%d is the popped element\n",y);
    }
}
void Push(struct stack *st,int x)
{
   // st->top=-1;
   
    if(st->top==st->size-1)
    {
         printf("Stack Overflow\n");
    }
   
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

void Display(struct stack *st)
{
    int i;
    for(i=0;i<=st->top;i++)
    {
        printf("%d ",st->s[i]);
    }
}
int main()
{
    struct stack st;
     st.top=-1;
     printf("Enter the stack size\n");
     scanf("%d",&st.size);
     int index,r,ch,n;
     while(1)
     {
         printf("\n1.Push\n2.Display\n3.Pop\n4.exit\n");
         printf("Enter your choice\n ");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:
                    printf("\nEnter the element\n");
                    scanf("%d",&n);
                    Push(&st,n);
                    break;
            case 2:
                    Display(&st);
                    break;
            case 3:
                   Pop(&st);
                   break;
            case 4:
                   exit(0);
                   break;
           
         }
     }
}      
