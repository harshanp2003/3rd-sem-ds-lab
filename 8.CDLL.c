#include <stdio.h> // initailly display first then go for insert by order functtion insert at random position and sort it then display
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*first;
int n;
struct node *create(struct node *first)
{
    struct node *l,*tp;
    int data,i;
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
struct node *insert(struct node *first,int pos,int data)
{
    struct node *l,*tp1;
    int i;
    
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
void search(struct node *first,int pos)
{
    struct node *l;
    int pos1=pos,f,count=0;
    l=first;
    do
    {
        
        l=l->next;
        count++;
    }while(l!=first && (count+1)!=pos);
     printf("%d is the data at positon %d\n",l->data,pos1);
    
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
        first->prev=l;
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
 struct node *sort(struct node *first,int count)
{
    int j,i,swp;
    struct node *p,*q;
    for(i=0;i<count-1;i++)
      {
          p=first;
          q=first->next;
          for(j=0;j<count-1-i;j++)
          {
              if((q->data) < (p->data))
              {
                  swp=q->data;
                  q->data=p->data;
                  p->data=swp;
              }
              p=q;
              q=q->next;
          }
      }
      return first;
}
 int main()
{
    int data,key,pos,count,ch;
  
   
   while(1)
   {
       printf("1.Create\n2.display\n3.search\n4.insertbyorder\n5.delete\n6.exit\n");
       printf("Enter choice\n");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:first=create(first);
                  break;
           case 2:count=display(first);
                  break;
           case 3:printf("Enter position\n");
                  scanf("%d",&pos);
                  search(first,pos);
                  break;
            case 4:printf("Enter data\n");
                   scanf("%d",&data);
                   first=insert(first,n,data);
                   first=sort(first,count+1);
                   break;
            case 5:first=delete(first);
                   break;
            case 6:exit(0);
            default:printf("Invalid choice\n");
       }
   }
}
