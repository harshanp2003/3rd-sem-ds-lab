#include<stdio.h>
#include<stdlib.h>
int n,size;
struct student
{
    int regno;
    char name[30];
    int marks[3];
    float average;
};

void read(struct student *sp)
{
    int i,j;
    printf("Enter the number of student : ");
    scanf("%d",&n);
    if(n>size)
    {
      printf("Insufficent space\n");
      printf("Allocating memory Dynamically\n");
      sp=(struct student*)realloc(sp,size*2);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the Reg no  and Name of the student %d\n",i+1);
        scanf("%d%s",&(sp+i)->regno,(sp+i)->name);
        printf("enter the marks of the student in  three tests\n");
        for(j=0;j<3;j++)
        {
            scanf("%d",&(sp+i)->marks[j]);
        }
    }
}

void disp(struct student *sp)
{
    int i,j;
    if(n==0)
    {
        printf("list empty\n");
        return;
    }
    printf("regno\tname\t\ttestT1\t\ttestT2\t\ttestT3\t\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\t",(sp+i)->regno,(sp+i)->name);
        for(j=0;j<3;j++)
        {
          printf("\t%d\t",(sp+i)->marks[j]);
        }
    printf("\n");
    }
}

void average(struct student *sp)
{
    int i,j,k,temp,sum[n];
    if(n==0)
    {
        printf("list empty\n");
        return;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<3-j-i;k++)
            {
            if((sp+i)->marks[k]>(sp+i)->marks[k+1])
            {
                temp=(sp+i)->marks[k];
                (sp+i)->marks[k]=(sp+i)->marks[k+1];
                (sp+i)->marks[k+1]=temp;
            }
            }
        }
    }
    for(i=0;i<n;i++)
    {
    sum[i]=(sp+i)->marks[1]+(sp+i)->marks[2];
    printf("Average of best of the two subject marks of student %d is %f\n",i+1,((float)(sum[i]/2.0)));
    }
}

void main()
{
    struct student *sp;
    printf("Enter the size : ");
    scanf("%d",&size);
    sp=(struct student*)malloc(size*sizeof(struct student));
    int ch;
    while(1)
    {
        
        printf("1.read\n2.dislay\n3.average\n4.Exit\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: read(sp);
                    break;
            case 2: disp(sp);
                    break;
            case 3: average(sp);
                    break;
            case 4: free(sp);
                     sp=NULL;
                     exit(0);
            default: printf("Invalid Input\n");     
        }
    
    }
}
