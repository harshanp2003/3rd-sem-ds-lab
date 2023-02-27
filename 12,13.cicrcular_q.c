#include<stdio.h>
#include<stdlib.h>
int count = 0;
typedef struct queue
{
    int f,r,n,*a;
}q;

void create(q *q)
{
    printf("Enter the size of the queue:");
    scanf("%d",&q->n);
    q->a=malloc(sizeof(int)*q->n);
    q->f=0;
    q->r=-1;
}

void insert_rear(q *q,int k)
{
    if(q->r%q->n==(q->n)-1 && q->f%q->n==0)
    {
        
        printf("Queue full\n");
    }
    else
    {
      // q->r++;
        q->r=(q->r+1)%q->n;
        q->a[q->r]=k;
        count++;
    }
}

void delete_front(q *q)
{
    if(count == 0)
    {
        printf("Queue empty\n");
        q->f=0; q->r=-1;
    }
    else
    {
        printf("The deleted element is: %d\n",q->a[q->f]);
        //q->f++;
        q->f=(q->f+1)%q->n;
        count--;
    }
}

void display(q *q)
{
    if(count == 0)
    {
        printf("Queue is empty\n");
        q->f=0; q->r=-1;
    }
    else
    {
       int j=q->f;
       for(int i=1; i<=count; i++){
           printf("%d ",q->a[j]);
           j = (j+1)%q->n;
       }
    }
    printf("\n");
}

int main()
{
    q *q=malloc(sizeof(q));
   
    int ch,k;
    while(1)
    {
        printf("0.create\n1.Insert rear\n2.Delete front\n3.Display\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:create(q);
                   break;
            case 1: printf("Enter the key:");
                    scanf("%d",&k);
                    insert_rear(q,k);
                    break;
            case 2: delete_front(q);
                    break;
            case 3: display(q);
                    break;
            default: exit(0);
        }
    }
}
