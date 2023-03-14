 #include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int size;
    int *s;
    
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
         printf("Reallocating\n");
         st->s=realloc(st->s,2*st->size*sizeof(int));
          st->top++;
        st->s[st->top]=x;
    }
   
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}
void Create(struct stack *st)
{
    int size;
    printf("Enter the size\n");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(sizeof(int)*st->size);
}
void Display(struct stack *st)
{
    int i;
    for(i=0;i<=st->top;i++)
    {
        printf("%d ",st->s[i]);
    }
    printf("\n");
}
int main()
{
    struct stack *st;
    st=malloc(sizeof(struct stack));
    
     int index,r,ch,n;
     while(1)
     {
         printf("0.Create\n1.Push\n2.Display\n3.Pop\n4.exit\n");
         printf("Enter your choice\n ");
         scanf("%d",&ch);
         switch(ch)
         {
             case 0:
                    Create(st);
                    break;
             case 1:
                    printf("Enter the element\n");
                    scanf("%d",&n);
                    Push(st,n);
                    break;
            case 2:
                    Display(st);
                    break;
            case 3:
                   Pop(st);
                   break;
            case 4:
                   exit(0);
                   break;
           
         }
     }
}    
