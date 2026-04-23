/*Write a C program to input two numbers and determine the largest and smallest values using functions.

Use call by value to find the maximum number.
Use call by address to find the minimum number.
*/
#include<stdio.h>
int isMax(int ,int);
int isMin(int * ,int *);
void main()
{
    int n1,n2,max,min;
    printf("Enter 1st no.:");
    scanf("%d",&n1);
    printf("Enter 2nd no.:");
    scanf("%d",&n2);
    max=isMax(n1,n2);
    min=isMin(&n1,&n2);
    printf("The greatest no.:%d\n",max);
    printf("The smallest no.:%d\n",min);
}
int isMax(int a, int b)
{
    if(a>b)
    return a;
    else 
    return b;
}
int isMin (int *a ,int*b)
{
 if (*a<*b)
 return *a;
 else 
 return *b;
}