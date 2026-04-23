/*Write a C program to check whether a given number is a prime number using a function.*/
#include<stdio.h>
int isPrime(int);
void main()
{
    int n;
    printf("Enter a no.:");
    scanf("%d",&n);
    if(isPrime(n))
    printf("%d is a prime no.\n",n);
    else 
    printf("%d is not a prime no.\n",n);
}
int isPrime(int x)
{
    int ctr, fctr=0;
    for(ctr=1;ctr<=x;ctr++)
    {
        if(x%ctr==0)
        fctr++;
    }
    if(fctr==2)
    return 1;
    else 
    return 0;
}