#include <stdio.h> //inserting at any random position and then sorting and displaying
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
    int pos1=pos,f,key,count=0;
     if(pos==1)
        {
            printf("%d is the data at position 1\n",first->data);
            return;
        }
        l=first;
        do
        {
            l=l->next;
            count++;
        }  while(l!=first && (count+1)!=pos );
        printf("%d is the data at positon %d\n",l->data,pos);
}
struct node *deletebykey(struct node *first)
{
    struct node *p,*q;
    int i,count=0,f=0,x,key;
    p=first;
   q=NULL;
   printf("Enter key\n");
   scanf("%d",&key);
   do
   {
       if(p->data==key)
       {
           f=1;
           break;
       }
       p=p->next;
       count++;
   }while(p!=first);
   if(f!=1)
   {
       printf("Key not present\n");
       return first;
   }
 
   if(f==1)
   {
       p=first;
       q=first;
       printf("Key present\n");
       if(key==first->data)
       {
           
           for(q=first;q->next!=first;q=q->next)
           {}
           first=first->next;
           q->next=first;
           first->prev=q;
           x=p->data;
           printf("%d is deleted data\n",x);
           free(p);
           return first;
           
       }
       else
       {
           p=first;
           q=NULL;
           for(i=1;i<=count;i++)
          {
              q=p;
               p=p->next;
           }
           q->next=p->next;
           p->next->prev=q;
           x=p->data;
           printf("%d is deleted data\n",x);
           
           free(p);
           return first;
       }
       
       
   }
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

 int main()
{
    int data,pos,count,ch;
  
   
   while(1)
   {
       printf("1.Create\n2.display\n3.search\n4.insertbyorder\n5.deletebykey\n6.exit\n");
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
            case 5:first=deletebykey(first);
                   break;
            case 6:exit(0);
            default:printf("Invalid choice\n");
       }
   }
}
