#include<stdio.h>
#include<stdlib.h>
struct Q
{
    int f;
    int size;
    int r;
    int *A;
};
void create(struct Q *q)
{
   // int size1;
    printf("Enter the size\n");
    scanf("%d",&q->size);
    q->A=malloc(sizeof(int)*q->size);
     q->f=0;
    q->r=-1;
}

void delr(struct Q *q)
{
    if(q->r==-1)
    {
        printf("Deletion not possible\n");
        return;
    }
    int x;
    x=q->A[q->r--];
 
    printf("%d is the deleted element\n",x);
}
void insertf(struct Q *q,int data)
{ 
   if(q->f==0)
   {
        printf("Insertion not possible\n");
       return;
   }
  // if(q->f!=0)els
   else
   {
       q->A[--q->f]=data;
       return;
   }
  
   
}
void enqu(struct Q *q,int data)
{
 
    if(q->r==q->size-1)
    {
       printf("Overflow\n");
       printf("Reallocating memory dynamically\n");
       int *t=realloc(q->A,2*q->size*sizeof(int));
       q->r=q->size-1;
       q->size=2*q->size;
       q->A=t;
    }
    
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
    struct Q *q=malloc(sizeof(struct Q));
   
   /* printf("Enter the value of n\n");
    scanf("%d",&q.size);*/
    while(1)
    {
        printf("0.Create\n1.Insertf\n2.Insertrear\n3.Deletefront\n4.Display\n5.Exit\n6.deleterear\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:create(q);
                   break;
            case 1: printf("Enter the value of n\n");
                    scanf("%d",&n);
                    insertf(q,n);
                    break;
            case 2: printf("Enter n\n");
                    scanf("%d",&n);
                    enqu(q,n);
                    break;
            case 3:deque(q);
                   break;
            case 4:display(q);
                   break;
            case 5:exit(0);
            case 6: delr(q);
                    break;
                
            default:printf("Invalid Choice\n");
                    break;
        }
    }
}
