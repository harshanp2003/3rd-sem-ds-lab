#include<stdio.h>
#include<stdlib.h>
struct Q
{
    int count;
    int f;
    int size;
    int r;
    int *A;
};
void Create(struct Q *q)
{
   // int size1;
    printf("Enter the size\n");
    scanf("%d",&q->size);
    q->A=malloc(sizeof(int)*q->size);
}
void enqu(struct Q *q,int data)
{
    
    if(q->count==q->size)
       printf("Overflow\n");
    else
       {
         q->r=(q->r+1)%q->size;  
         q->A[(q->r)]=data;
          q->count++;
       }  
}
void deque(struct Q *q)
{
    int x;
     if(q->count==0)
     {
          printf("Deletion not possible\n");
          q->f=0;q->r=0;
     }
       
     else
        {
            
             q->f=(q->f+1)%q->size;
            printf("Deleted element is %d \n",q->A[q->f]);
              
            
            q->count--;
        }
    
    
}
void display(struct Q *q)
{
    int i;
    for(i=1;i<=q->count;i++)
    {
         q->f=(q->f+1)%q->size;
        printf("%d ",q->A[q->f]);
        
       
    }
    
    printf("\n");
}
void main()
{
    int n,ch;
    struct Q q;
    q.f=0;
    q.r=0;
    q.count=0;
    /*printf("Enter the value of n\n");
    scanf("%d",&q.size);*/
    while(1)
    {
        printf("1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1: Create(&q);
                    break;
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
