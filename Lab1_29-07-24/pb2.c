//Write a program in C to show the simple structure of a function
#include<stdio.h>
int isTrue(int);
void main()
{
    int n;
    printf("Enter a no.:");
    scanf("%d",&n);
    if(isTrue(n))
    printf("%d is greater than 0\n",n);
    else 
    printf("%d is equal to or less than 0\n",n);
}
int isTrue(int a)
{
    if(a>0)
    return 1;
    else 
    return 0;
}