#include<stdio.h>
#include<stdlib.h>
struct Q
{
    int f;
    int size;
    int r;
    int A[100];
};
void enqu(struct Q *q,int data)
{
 //  printf("Hi");
    if(q->r==q->size-1)
       printf("Overflow\n");
    else
       q->A[++(q->r)]=data;
}
void deque(struct Q *q)
{
    int x;
     if(q->f > q->r)
     {
          printf("Deletion not possible\n");
          q->f=0;q->r=-1;
     }
       
     else
        {
            x=q->A[q->f++];
            printf("Deleted element is %d \n",x);
        }
    
    
}
void display(struct Q *q)
{
    int i;
    for(i=q->f;i<=q->r;i++)
    {
        printf("%d ",q->A[i]);
    }
    printf("\n");
}
void main()
{
    int n,ch;
    struct Q q;
    q.f=0;
    q.r=-1;
    printf("Enter the value of n\n");
    scanf("%d",&q.size);
    while(1)
    {
        printf("2.Insert\n3.Delete\n4.Display\n5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 2: printf("Enter n\n");
                    scanf("%d",&n);
                    enqu(&q,n);
                    break;
            case 3:deque(&q);
                   break;
            case 4:display(&q);
                   break;
            case 5:exit(0);
                
            default:printf("Invalid Choice\n");
                    break;
        }
    }
}
