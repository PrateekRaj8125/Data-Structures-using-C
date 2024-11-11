/*Write a C program to check whether a number is palindrome or not using recursion.*/
#include<stdio.h>
void main()
{
    int n;
    printf("Enter a no.:");
    scanf("%d",&n);
    if(n==reverse(n,0))
    printf("%d is a palindrome no.\n",n);
    else
    printf("%d is not a palindrome no.\n",n);
}
int reverse(int n,int d)
{
    if(n>0)
    {
        d=d*10+n%10;
        return(reverse(n/10,d));
    }
    else
    return d;
}