/*Write a C program to perform linear search on an array using dynamic memory allocation.*/
#include<stdio.h>
#include<stdlib.h>
void search(int *,int,int);
void main()
{
    int ctr,n,*num;
    printf("Enter total no. of elements:");
    scanf("%d",&ctr);
    num=(int *)malloc(ctr*sizeof(int));
    for(int i=0;i<ctr;i++)
    {
        printf("Enter element %d:",(i+1));
        scanf("%d",&num[i]);
    }
    printf("\nEnter element to be searched:");
    scanf("%d",&n);
    search(num,ctr,n);
}
void search(int *arr,int ctr,int n)
{
        for(int i=0;i<ctr;i++)
        {
            if(*(arr+i)==n)
            {
            printf("The element %d is found in position %d\n",n,(i+1));
            exit(0);
        }
        }
        printf("The element entered is not present in the array\n");
}