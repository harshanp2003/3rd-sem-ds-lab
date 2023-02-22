/*Trees*/
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
               printf(" %d  ",r->data);
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
int main()
{
    struct root *r=malloc(sizeof(struct root));
    int data,ch;
    printf("Enter the value of root node\n");
    scanf("%d",&r->data);
    
    printf("1.Build tree\n2.Preorder\n3.Inorder\n4.Postorder\n");
    
    while(1)
    {
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
       default:printf("Invalid choice\n");
               break;
    }
    }
    
}
