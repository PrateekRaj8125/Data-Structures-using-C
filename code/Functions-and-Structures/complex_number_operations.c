/*Write a menu-driven C program using a structure to represent complex numbers and perform:

1. Addition of two complex numbers (call by value)
2. Multiplication of two complex numbers (call by address)*/
#include<stdio.h>
void addition(float, float, float, float);
void multiplication(float *, float *, float *, float *);
struct complex
{
    float real, imaginary;
}n1,n2;
void main()
{
    printf("Enter First No.:\n");
    printf("Real Part:");
    scanf("%f",&n1.real);
    printf("Imaginary Part:");
    scanf("%f",&n1.imaginary);
    printf("Enter Second No.:\n");
    printf("Real Part:");
    scanf("%f",&n2.real);
    printf("Imaginary Part:");
    scanf("%f",&n2.imaginary);
    addition(n1.real,n1.imaginary,n2.real,n2.imaginary);
    multiplication(&n1.real,&n1.imaginary,&n2.real,&n2.imaginary);
}
void addition(float real_n1,float imaginary_n1, float real_n2,float imaginary_n2)
{
    printf("Addition of Two Complex Nos.:%f+%fi",(real_n1+real_n2),(imaginary_n1+imaginary_n2));
}
void multiplication(float *real_n1,float *imaginary_n1, float *real_n2, float *imaginary_n2)
{
    printf("\nMultiplication of Two Complex Nos.:%f+%fi",(((*real_n1)*(*real_n2))-((*imaginary_n1)*(*imaginary_n2))),(((*real_n1)*(*imaginary_n2))+((*real_n2)*(*imaginary_n1))));
}