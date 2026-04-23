/*Write a C program to add two distances(feet-inch system) entered by user. To solve this
program,make a structure. Pass two structure variable (containing distance in feet and inch) to
add() function by reference and display the result in main function without returning it.*/
#include<stdio.h>
struct dist
{
    int ft,in;
}d1,d2;
void add(int,int,int,int);
void main()
{
    printf("Enter distance 1:\n");
    printf("Feet:");
    scanf("%d",&d1.ft);
    printf("Inch:");
    scanf("%d",&d1.in);
    printf("Enter distance 2:\n");
    printf("Feet:");
    scanf("%d",&d2.ft);
    printf("Inch:");
    scanf("%d",&d2.in);
    add(d1.ft,d1.in,d2.ft,d2.in);
}
void add(int d1_ft,int d1_in,int d2_ft,int d2_in)
{
    int tft,tin;
    tft=d1_ft+d2_ft;
    tin=d1_in+d2_in;
    if(tin>=12)
    {
        tft+=((int)(tin/12));
        tin%=12;
    }
    printf("Total distance:%d feet %d inch",tft,tin);
}