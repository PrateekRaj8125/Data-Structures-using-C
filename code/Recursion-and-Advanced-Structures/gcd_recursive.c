/*Write a C program to find the GCD (HCF) of two numbers using recursion.*/
#include<stdio.h>
int gcd(int,int,int);
void main()
{
    int n1,n2;
    printf("Enter 1st no.:");
    scanf("%d",&n1);
    printf("Enter 2nd no.:");
    scanf("%d",&n2);
    int min=n1>n2?n1:n2;
    int hcf=gcd(min,n1,n2);
    printf("HCF of %d and %d is:%d\n",n1,n2,hcf);
}
int gcd(int n,int n1,int n2)
{
    if((n1%n==0)&&(n2%n==0))
    return n;
    else
    {
        n--;
        return(gcd(n,n1,n2));
    }
}