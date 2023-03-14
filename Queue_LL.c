#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;


typedef struct Queue{
    Node* f;
    Node* r;
    int count;
}Queue;

void display(Queue* q)
{
if(q->f==NULL || q->r==NULL) {
        printf("Queue empty\n");
        return;
    }
Node * temp=q->f;
printf("Number of elementq in Queue: %d\n Queue iq: ", q->count);
while(temp!=NULL)
{
    printf("%d ",temp->data);
    temp=temp->next;
}
printf("\n");
}

void enqueue(Queue* q, int data)
{
    Node* newnode= (Node *)malloc(sizeof(Node));
    newnode->data=data;
    if(q->r==NULL)
    {
        q->f=q->r=newnode;
    newnode->next=NULL;
    }
    else
    {
        q->r->next=newnode;
       newnode->next=NULL;
       q->r=newnode;
    }
    q->count++;
    display(q);
}

void dequeue(Queue* q)
{
    if(q->f==NULL || q->r==NULL) {
        printf("Queue empty\n");
        return;
    }
    Node* temp=q->f;
    q->f=q->f->next;
    free(temp);
    q->count--;
    display(q);
}


void main()
{
    Queue* q= (Queue *)malloc(sizeof(Queue));
    q->f=NULL;
    q->r=NULL;
    q->count=0;
    int ch,K;
    while(1)
    {
        printf("Enter the choice\n1.enqueue\n2.dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            printf("Enter the data you want to enqueue\n");
            scanf("%d",&K);
            enqueue(q, K);
            break;

            case 2:
            dequeue(q);
            break;

            case 3:
            display(q);
            break;

            case 4: exit(0);
        }
    }
}
