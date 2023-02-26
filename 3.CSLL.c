#include <stdio.h>// circular single updated for only 3 fns
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
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
void search(struct node *first)
{
    struct node *p;
    int f,key;
    printf("Enter key\n");
    scanf("%d",&key);
    
    p=first;
   do
    {
        if(p->data==key)
        {
            f=1;
            break;
        }
        p=p->next;
    } while(p!=first);
    if(f==1)
       printf("Key Present\n");
    else
       printf("Key absent\n");
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
   //  printf("Enter the position to be inserted\n");
    //scanf("%d",&pos);
    
    if(pos==1)
    {
        tp1=malloc(sizeof(struct node));
    tp1->data=data;
    //tp1->next=first;
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
        for(i=1;i<pos-1;i++)
        {
            l=l->next;
        }
        tp1=malloc(sizeof(struct node));
        tp1->data=data;
        tp1->next=l->next;
        l->next=tp1;
        return first;
    }
}
struct node * delete(struct node *first)
{
    int x,i,pos,data;
    struct node *p,*q,*a;
     printf("\nEnter the position to be deleted\n");
    scanf("%d",&pos);
    
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
      //display(first);
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
        //display(first);
        return first;
     }
}
struct node *sort(struct node *first,int count)   //done
{
    struct node *q,*p;
    int swp,i,j;
     for(i=0;i<count-1;i++)
      {
          p=first;
          q=first->next;
          for(j=0;j<count-1-i;j++)
          {
              if((p->data) > (q->data))
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
struct node *insertbyorder(struct node *first,int data)
{
   // first=sort(first)
   int count=0;
   struct node *p;
   p=first;
   do
   {
      
       if(data> p->data && p->next!=first)
       {
           count++;
           p=p->next;
       }
       else
       {
           if(p->next==first)
                count++;
           first=insert(first,count+1,data);
           break;
       }
   }while(p!=first);
   return first;
}
int main()
{
    int data,pos,count,ch;
    
    while(1)
    {
         printf("1.Create\n2.Display\n3.search\n4.insertbyorder\n5.delete\n");
         printf("Enter choice\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:first=create(first);
                  break;
             case 2:count=display(first);
                    break;
             case 3:search(first);
                    break;
             case 4: //printf("\nEnter the position to be inserted\n");
                     //scanf("%d",&pos);
                     printf("Enter the data\n");
                     scanf("%d",&data);
                     
                     first=sort(first,count);
                     first=insert(first,n,data);
                     first=sort(first,count+1);
                    // first=insertbyorder(first,data);
                     break;
             case 5:first=delete(first);
                    break;
            case 6:first=sort(first,count);
                   break;
            default:exit(0);
         }
    }
}
