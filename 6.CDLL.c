#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*first;
struct node *create(struct node *first)
{
    struct node *l,*tp;
    int n,data,i;
     printf("Enter the no of nodes\n");
    scanf("%d",&n);
    printf("Enter the data for the 1st node\n");
    scanf("%d",&data);
    first=malloc(sizeof(struct node));
    first->data=data;
     first->prev=NULL;
    first->next=NULL;
    l=first;
    for(i=2;i<=n;i++)
    {
        scanf("%d",&data);
        tp=malloc(sizeof(struct node));
        tp->data=data;
        tp->prev=l;
        
        tp->next=NULL;
        l->next=tp;
        l=tp;
    }
    l->next=first;
    first->prev=l;
}
struct node *insertfront(struct node *first)
{
    struct node *l,*tp1;
    int i,data,pos=1;
    printf("Enter the data\n");
    scanf("%d",&data);
    if(pos==1)
    {
        tp1=malloc(sizeof(struct node));
        tp1->data=data;
        tp1->next=first;
       
        for(l=first;l->next!=first;l=l->next)
        { }
        l->next=tp1;
         tp1->prev=l;
        first=tp1;
        return first;
    }
}
struct node *insertrear(struct node *first)
{
     struct node *l,*tp1;
    int i,data,pos=1;
    printf("Enter the data\n");
    scanf("%d",&data);
    tp1=malloc(sizeof(struct node));
    tp1->data=data;
    l=first;
    for(;l->next!=first;l=l->next)
    {}
    tp1->next=l->next;
    l->next=tp1;
    return first;
}
struct node *insert(struct node *first)
{
    struct node *l,*tp1;
    int i,data,pos;
     printf("Enter the position to be inserted\n");
    scanf("%d",&pos);
    printf("Enter the data\n");
    scanf("%d",&data);
    if(pos==1)
    {
        tp1=malloc(sizeof(struct node));
        tp1->data=data;
        tp1->next=first;
       
        for(l=first;l->next!=first;l=l->next)
        { }
        l->next=tp1;
         tp1->prev=l;
        first=tp1;
        return first;
    }
    else 
    {
        l=first;
        
        while(pos!=2)
        {
            l=l->next;
            pos--;
        }
        tp1=malloc(sizeof(struct node));
        tp1->data=data;
        tp1->next=l->next;
         tp1->prev=l;
        l->next=tp1;
        return first;
    }
}
int  display(struct node *first)
{
    struct node *a;
    int count=0;
     a=first;
    do
    {
        printf("%d ",a->data);
        a=a->next;
        count++;
    }while(a!=first);
    printf("\n%d no of nodes present\n ",count);
    return count;
    
}
void search(struct node *first,int key)
{
    struct node *l;
    int f,count=0;
    l=first;
    do
    {
        if(key==l->data)
        {
            f=1;
            break;
        }
        l=l->next;
    }while(l!=first);
    if(f==1)
   printf("Key present \n");
 
   else
  printf("Key absent\n");
}
struct node *delete(struct node *first)
 {
     int i,x,pos;
     struct node *l,*p,*q,*a;
     printf("Enter the position to be deleted\n");
    scanf("%d",&pos);
    if(pos==1)
     {
         p=first;
      first=first->next;
      for(l=first;l->next!=p;l=l->next)
      {}
       l->next=first;
      x=p->data;
      free(p);
      printf("Deleted data is : %d\n",x);
      return first;
     }
     else
     {
         a=first;
         q=NULL;
         for(i=0;i<pos-1;i++)
        {
            q=a;
            a=a->next;
        }
        q->next=a->next;
        a->next->prev=q;
        
        x=a->data;
            printf("Deleted data is : %d\n",x);
        free(a);
        return first;
     } 
 }
 
 int main()
{
    int key,pos,count,ch;
  
   
   while(1)
   {
       printf("1.Create\n2.display\n3.search\n4.insert\n5.delete\n6.exit\n7.insertfront\n8.insertrear\n");
       printf("Enter choice\n");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:first=create(first);
                  break;
           case 2:count=display(first);
                  break;
           case 3:printf("Enter key\n");
                  scanf("%d",&key);
                  search(first,key);
                  break;
            case 4:first=insert(first);
                   break;
            case 5:first=delete(first);
                   break;
            case 6:exit(0);
            case 7:first=insertfront(first);
                   break;
            case 8:first=insertrear(first);
                   break;
            default:printf("Invalid choice\n");
       }
   }
}
