/*Write a C program to find the nth Fibonacci term using recursion.*/
int fibonacci(int n,int n1,int n2)
{
    if(n!=1)
    {
        n2+=n1;
        n1=n2-n1;
        n--;
        return(fibonacci(n,n1,n2));
    }
    else
    return n1;
}
void main()
{
    int n,n1=0,n2=1,dn;
    printf("Enter nth term:");
    scanf("%d",&n);
    dn=fibonacci(n,n1,n2);
    printf("The nth term of fibonacci series is:%d\n",dn);
}