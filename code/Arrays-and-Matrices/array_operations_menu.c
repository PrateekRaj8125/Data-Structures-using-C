/*1.WAP to create a 1-D array of n elements and perform the following menu based operations
using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array*/
#include<stdio.h>
#include<stdlib.h>
void insertElement(int[],int);
void deleteElement(int[],int);
void linearSearch(int[],int);
void traversal(int[],int);
void main()
{
    int n;
    printf("Enter no. of elements to be entered:");
    scanf("%d",&n);
    int array[n],counter;
    for(counter=0;counter<n;counter++)
    {
        printf("Enter element %d:",(counter+1));
        scanf("%d",&array[counter]);
    }
    int ch;
    printf("Operations Available:\n");
    printf("--------------------\n");
    printf("1. Insert a given element at specific position.\n");
    printf("2. Delete an element from a specific position of the array.\n");
    printf("3. Linear search to search an element\n");
    printf("4. Traversal of the array\n");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
    insertElement(array,n);
    break;
    case 2:
    deleteElement(array,n);
    break;
    case 3:
    linearSearch(array,n);
    break;
    case 4:
    traversal(array,n);
    break;
    default:
    printf("\nThe choice entered is wrong, please try again\n");
    }
}
void insertElement(int array[],int n)
{
    int p,nv;
    printf("Enter new value to be inserted:");
    scanf("%d",&nv);
    printf("Enter position the value is to be entered:");
    scanf("%d",&p);
    if(p<=n)
    {
        int newArray[n+1];
        for(int counter=n;counter>=p-1;counter++)
        {
            if(counter==p-1)
            newArray[counter]=nv;
            else
            newArray[counter]=array[counter-1];
        }
        for(int counter=p-2;counter>=0;counter++)
        {
            newArray[counter]=array[counter];
        }
        printf("New Array:\n");
        for(int counter=0;counter<=n;counter++)
        {
            printf("%d\n",newArray[counter]);
        }
    }
    else
    printf("The position Entered is not present in array\n");
}
void deleteElement(int array[],int n)
{
    int p,nv;
    printf("Enter the position element to be deleted:");
    scanf("%d",&nv);
    for (int counter=0;counter<n;counter++)
    {
        if((counter+1)==nv)
        {
            p=counter;
            break;
        }
    }
    for(int counter=p;counter<n;counter++)
    {
        array[counter]=array[(counter+1)];       
    }
    array[(n-1)]=0;
    printf("New Array:\n");
    for(int counter=0;counter<n-1;counter++)
    printf("%d\n",array[counter]);
}
void linearSearch(int array[],int n)
{
    int nv,p;
    printf("Enter no. to be searched:");
    scanf("%d",&nv);
    for(int counter=0;counter<n;counter++)
    {
        if(array[counter]==nv)
        {
            p=counter +1;
            break;
        }
    }
    printf("%d is found in position %d\n",nv,p);
}
void traversal(int array[],int n)
{
    printf("Element\tValue\n");
    for (int counter=0;counter<n;counter++)
    {
        printf("%d\t%d\n",(counter+1),array[counter]);
    }
}