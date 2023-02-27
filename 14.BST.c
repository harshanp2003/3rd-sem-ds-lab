#include<stdio.h>
#include<stdlib.h>
struct root
{
    struct root *rlink;
    struct root *llink;
    int data;
};
void insert(struct root *r,int data)
{
    if(data<r->data && r->llink==NULL)
    {
        struct root *temp=malloc(sizeof(struct root));
        temp->data=data;
        temp->rlink=NULL;
        temp->llink=NULL;
        r->llink=temp;
        return;
    }
    if(data>r->data && r->rlink==NULL)
    {
        struct root *temp=malloc(sizeof(struct root));
        temp->data=data;
        temp->rlink=NULL;
        temp->llink=NULL;
        r->rlink=temp;
        return;
    }
    if(data<r->data)
       insert(r->llink,data);
    if(data>r->data)
        insert(r->rlink,data);
}
void ord(struct root *r,int ch)
{
    if(r==NULL)
         return;
    if(r->llink==NULL && r->rlink==NULL)
    {
        printf("%d",r->data);
        return;
    }
    switch(ch)
    {
        case 1:printf(" %d ",r->data);
               ord(r->llink,1);
               ord(r->rlink,1);
               
               break;
        case 2:ord(r->llink,2);
               printf(" %d ",r->data);
               ord(r->rlink,2);
               break;
        case 3:ord(r->llink,3);
               ord(r->rlink,3);
               printf(" %d ",r->data);
               break;
        default:printf("Invalid Choice\n");
                break;
    }
}
struct root * search(struct root *r,int key)
{
    
    if(r==NULL)
    {
        printf("Key not found\n");
        return NULL;
    }
       
    if(key==r->data)
    {
        printf("Key found : value is= %d \n",key);
        return r;
    }
    
    if(key<r->data)
    { 
         if(r->llink!=NULL &&  r->llink->data==key )printf("parent node value : %d \n",r->data); 
                   
        return search(r->llink,key);
      
    }
    if(key>r->data)
    {
         if( r->rlink!=NULL &&  r->rlink->data==key) printf("parent node value : %d \n",r->data);
                 
         return search(r->rlink,key);
    }
    
    
}  
int totalnodes(struct root *r)
{
    if(r==NULL)
        return 0;
    
    int l=totalnodes(r->llink);
    int rt=totalnodes(r->rlink);
    return 1+l+rt;
}
int height(struct root *r)
{
    if(r==NULL || (r->rlink==NULL && r->llink==NULL) )
       return 0;
    else
    {
        int lh=height(r->llink);
        int rh=height(r->rlink);
      if(lh>rh)
          return (lh+1);
      else
        return (rh+1);
    }
    
}
int main()
{
    struct root *r=malloc(sizeof(struct root));
    int key,f,data,ch;
    printf("Enter the value of root node\n");
    scanf("%d",&r->data);
    while(1)
  {
        printf("\n1.Build tree\n2.Preorder\n3.Inorder\n4.Postorder\n5.search\n6.totalnodes\n7.height\n8.exit");
        printf("\nEnter choice\n");
        scanf("%d",&ch);
        switch(ch)
    {
        case 1:printf("Enter data to be inserted\n");
               scanf("%d",&data);
               insert(r,data);
               break;
       case 2:printf("Preorder is\n");
              ord(r,1);
              break;
       case 3:printf("Inorder is \n");
              ord(r,2);
              break;
       case 4:printf("POst order is\n");
              ord(r,3);
              break;
        
        case 5:printf("Enter key\n");
               scanf("%d",&key);
               search(r,key);
               break;
        case 6:printf("%d is total no of node\n",totalnodes(r));
               break;
        case 7:printf("total height is %d \n",height(r));
               break;
        case 8:exit(0);
       default:printf("Invalid choice\n");
               break;
    }
  }
    
}
