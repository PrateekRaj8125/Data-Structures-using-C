/*Write a C program to find the reverse of a number using recursion.*/
#include<stdio.h>
void main()
{
    int n;
    printf("Enter a No.:");
    scanf("%d",&n);
    printf("Reverse of %d is:%d\n",n,(reverse(n,0)));
}
int reverse(int n, int rn)
{
    if(n!=0)
    {
        rn=rn*10+n%10;
        return(reverse((n/10),rn));
    }
    else return rn;
}