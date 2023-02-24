#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;
struct node * create()
{
    int i,n,data;
    struct node *tp,*l;
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
        printf("Enter data for node %d : ",i);
        scanf("%d",&data);
        tp=malloc(sizeof(struct node));
        tp->data=data;
        tp->next=NULL;
        l->next=tp;
        l=tp;
    }
    return first;
}
int display(struct node *l)   //done
{
    int count=0;
    while(l!=NULL)
    {
        
        printf("%d ",l->data);
        l=l->next;
        count++;
    }
    printf("\n%d no of nodes are present\n",count);
    return count;
   
}
int  search(struct node *l)    //done
{
    int count=0,f,key,pos;
      printf("\nEnter the key\n");
      scanf("%d",&key);
  
     while(l!=NULL)
    {
        if(key==l->data)
        {
            f=1;
            pos=count;
            break;
        }
        count++;
        l=l->next;
    }
   if(f==1)
   {
       printf("\nKey present \n");
       return pos+1;        //pos+1 coz 1based position is used for  deleting
   }
   
   else
   {
     printf("Key absent\n");
     return -1;
   }
   
  // return count;
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
struct node *insert(struct node *first) //done
{
    int data,pos,i;
    struct node *tp1,*l;
    printf("Enter the data to be insrted\n");
    scanf("%d",&data);
    printf("Enter the position to be inserted\n");
    scanf("%d",&pos);
    if(pos==1)
    {
        tp1=malloc(sizeof(struct node));
        tp1->data=data;
        tp1->next=first;
        first=tp1;
        l=first;
      return l;
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
        l->next=tp1;
        return first;
    } 
}
struct node *delete(struct node *first,int pos) //done
{
    struct node *a,*p;
    int i,x;  
     if(pos==1)
     {
         p=first;
      first=first->next;
      x=p->data;
      free(p);
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
struct node *reverse(struct node *first)
{
    struct node *q,*r,*p;
     r=NULL,q=NULL,p=first;
     while(p!=NULL)
     {
         r=q;
         q=p;
         p=p->next;
         q->next=r;
     }
     return q;
}
struct node * copy(struct node *first)
{
    struct node *cpv,*temp=first,*temp2;
    cpv=malloc(sizeof(struct node));
    cpv->data=first->data;
    cpv->next=NULL;
    temp=cpv;
    first=first->next;
    while(first!=NULL) 
    {
        temp2=malloc(sizeof(struct node));
        temp2->data=first->data;
        temp2->next=NULL;
        temp->next=temp2;
        temp=temp2;
        first=first->next;
    }
    first=cpv;
    return first;
}
struct node *deletebykey(struct node *first)
{
    int count;
    count=search(first);
    if(count==-1)
    {
        return first;
    }
    else
    {
        first=delete(first,count);
        return first;
    }
    
}
int main()
{
    int ch,pos,count=0;
   // struct node *tp,*tp1,*q,*p,*a,*r;
   //create();
   while(1)
   {
       printf("1.Create\n2.Display\n3.Search\n4.Insert\n5.Delete\n6.Reverse\n7.Ordered list\n8.Copy\n9.Deletebykey\n10.exit\n");
       printf("Enter the choice\n");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:first=create();
                  break;
           case 2:count=display(first);
                  break;
           case 3 :search(first);
                  break;
           case 4:first=insert(first);
                  break;
           case 5 :printf("Enter the position to be deleted\n");
                   scanf("%d",&pos);
                   first=delete(first,pos);
                   break;
           case 6 :first=reverse(first);
                   break;
           case 7:first=sort(first,count);
                  break;
           case 8:first=copy(first);
                  break;
           case 9:first=deletebykey(first);
                  break;
           case 10:exit(0);
           
           default:printf("Invalid Choice\n");
                    break;        
       }
   }  
}
