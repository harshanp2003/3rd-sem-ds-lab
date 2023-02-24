#include <stdio.h>// circular single
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
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
         first->next=NULL;
         l=first;
         for(i=2;i<=n;i++)
       {
        scanf("%d",&data);
        tp=malloc(sizeof(struct node));
        tp->data=data;
        tp->next=NULL;
        l->next=tp;
        l=tp;
       }
       l->next=first;
       return first;
      
}
int  search(struct node *first,int key)
{
    struct node *p;
    int f,count=0;
   
    
    p=first;
   do
    {
        if(p->data==key)
        {
            f=1;
            
            break;
        }
        p=p->next;
        count++;
    } while(p!=first);
    if(f==1)
       printf("Key Present\n");
    else
       printf("Key absent\n");
     printf("%d is the position\n",count+1);
       return count;
}
int  display(struct node *first)
{
    struct node *p;
    int count=0;
      p=first;
   do
   {
       
        printf("%d ",p->data);
        p=p->next;
        count++;
        
      
   }while(p!=first);
   printf("\nCount is %d\n",count);
   return count;
}
struct node* insert(struct node *first,int pos,int data)
{
    int i;
    struct node *l,*tp1;
  
    
    if(pos==1)
    {
        tp1=malloc(sizeof(struct node));
    tp1->data=data;
    
    for(l=first;l->next!=first;l=l->next)
    { }
    l->next=tp1;
    tp1->next=first;
    first=tp1;
    return first;
    }
    else 
    {
        l=first;
        /*for(i=1;i<pos-1;i++)
        {
            l=l->next;
        }*/
        while(pos!=2)
        {
            l=l->next;
            pos--;
        }
        tp1=malloc(sizeof(struct node));
        tp1->data=data;
        tp1->next=l->next;
        l->next=tp1;
        return first;
    }
}
struct node * delete(struct node *first,int pos)
{
    int x,i,data;
    struct node *p,*q,*a;
    
    
     if(pos==1)
     {
         p=first;
         q=first;
       for(p=first;p->next!=first;p=p->next)
        { }
        first=first->next;
        p->next=first;
        
      x=q->data;
      printf("\n%d is the deleted data \n",x);
      free(q);
      return first;
     }
      else
     {
         p=first;
         a=NULL;
         for(i=0;i<pos-1;i++)
        {
            a=p;
            p=p->next;
        }
        a->next=p->next;
        x=p->data;
        free(p);
       
        return first;
     }
}
struct node *deletebykey(struct node *first,int key)
{
    int count;
    count=search(first,key);
    first=delete(first,count+1);
}

int main()
{
    int key,data,pos,count,ch;
    
    while(1)
    {
         printf("1.Create\n2.Display\n3.search\n4.insert\n5.delete\n6.exit\n");
         printf("Enter choice\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:first=create(first);
                    break;
             case 2:count=display(first);
                    break;
             case 3: printf("Enter key\n");
                    scanf("%d",&key);
                    search(first,key);
                     break;
             case 4: printf("\nEnter the position to be inserted\n");
                     scanf("%d",&pos);
                     printf("Enter the data\n");
                     scanf("%d",&data);
                     first=insert(first,pos,data);
                     break;
             case 5:printf("Enter key\n");
                    scanf("%d",&key);
                    first=deletebykey(first,key);
                    break;
             case 6:exit(0);
             default:printf("Invalid Choice\n");
                     break;
            
         }
    }
}
