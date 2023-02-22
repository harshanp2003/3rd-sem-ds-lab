#include<stdio.h>     //all fns done
#include<stdlib.h>
int n,i;
void read(int a[])
{
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int a[])
{
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void insert(int a[],int pos,int val)
{
    //int val;
    //printf("Enter the value\n"); scanf("%d",&val);
    if(pos>=0 && pos<=n)
    {
        for(i=n-1;i>=pos;i--)
       {
        a[i+1]=a[i];
       }
       a[pos]=val;
       (n)++;
       display(a);printf("\n");
    }
    else
       printf("Invalid position\n");
}
void delete(int a[],int pos)
{
    if(pos>=0 && pos<=n-1)
    {
        for(i=pos;i<=n-1;i++)
       {
        a[i]=a[i+1];
       }
       
       (n)--;
    }
    else
       printf("Invalid position\n");
}
void search(int a[],int key)
{
    int f;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            f=1;
            break;
        }
    }
    (f==1)?printf("Keyfound\n"):printf("Key not found\n");
}
void searchbypos(int a[],int pos)
{
    printf("%d is the value at %d position",a[pos],pos);
}
void insertbykey(int a[],int key)
{
    int f;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
        printf("Key is already present\n");
    }
    else
    {
        a[n++]=key;
    }
}
void deletebykey(int a[],int key)
{
    int f,ci;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            f=1;
            ci=i;    //current position of i
            break;
        }
    }
    if(f==1)
    {
        printf("Key is present so deleting it\n");
        for(i=ci;i<=n-1;i++)
        {
            a[i]=a[i+1];
        }
        (n)--;
    }
    else
    {
        printf("Key not present so no deletion\n");
    }
}
void insertbyorder(int a[])
{
    int count=0,ele,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    display(a);printf("\n");
    printf("Enter the element\n");
    scanf("%d",&ele);
    for(i=0;i<n;i++)
    {
        if(ele>a[i])
           count++;
        
    }
    
    insert(a,count,ele);
    
    display(a);printf("\n");
}
void reverse(int a[])
{
    int b[100],j;
    for(i=0,j=n-1;i<n,j>=0;i++,j--)
    {
        b[i]=a[j];
    }
    display(b);printf("\n");
}
void main()
{
    int val,key,ch,a[100],pos;
    while(1)
    {
        printf("1.Read\n2.Display\n3.Insert\n4.Delete\n5.Search by key\n6.Search by pos\n7.insertbykey\n8.deletebykey\n9.insertbyorder\n10.reverse\n");
        printf("Enter the choice\n");  scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the value of n\n");
                   scanf("%d",&n);
                   read(a);
                   break;
            case 2:printf("Displaying Array\n");
                   display(a);
                   printf("\n");
                   break;
            case 3:printf("Enter the position\n");
                   scanf("%d",&pos);
                   printf("Enter the value\n");
                   scanf("%d",&val);
                   insert(a,pos,val);
                   break;
            case 4:printf("Enter the position to be deleted\n");
                   scanf("%d",&pos);
                   delete(a,pos);
                   break;
            case 5:printf("Enter the key\n");
                   scanf("%d",&key);
                   search(a,key);
                   break;
            case 6:printf("Enter the position\n");
                   scanf("%d",&pos);
                   searchbypos(a,pos);
                   break;
            case 7:printf("Enter the key\n");
                   scanf("%d",&key);
                   insertbykey(a,key);
                   break;
            case 8:printf("Enter the key\n");
                   scanf("%d",&key);
                   deletebykey(a,key);
                   break;
            case 9:printf("Inserting By order\n");
                   insertbyorder(a);
                   break;
            case 10:printf("Reversing the array contents\n");
                    reverse(a);
                    break;
            default:printf("invalid choice\n");
                    exit(0);
            
        }
    }
}
