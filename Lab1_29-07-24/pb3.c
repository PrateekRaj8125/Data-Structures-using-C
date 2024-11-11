//WAP to find the sum of digits of a four digit number using recursive function—
#include<stdio.h>
int sumOfDigits(int);
void main()
{   
    int n;
    printf("Enter a Four digit no.:");
    scanf("%d",&n);
    int sum;
    sum=sumOfDigits(n);
    printf("Sum of Digits:%d",sum);
}
int sumOfDigits(int n)
{
    if (n!=0)
    return ((n%10)+sumOfDigits(n/10));
    else
    return n;
}