/*Create a structure named Student with fields: name, age, and total marks.
Write a C program to:

Input data for two students
Display their details
Calculate and display the average of total marks*/
#include<stdio.h>
struct student
{
    char name[100];
    int age, total_marks;
}Student[2];
void main()
{
    float average;
    for(int i=0;i<2;i++)
    {
        printf("Enter information of Student %d\n",(i+1));
        printf("Enter Name:");
        scanf("%s",&Student[i].name);
        printf("Enter age:");
        scanf("%d",&Student[i].age);
        printf("Enter Total Marks:");
        scanf("%d",&Student[i].total_marks);
    }
    average=(Student[0].total_marks+Student[1].total_marks)/2;
    for(int i=0;i<2;i++)
    {
        printf("\nStudent %d Information Slip\n",(i+1));
        printf("---------------------------\n");
        printf("Name:%s\n",Student[i].name);
        printf("Age:%d\n",Student[i].age);
        printf("Total Marks:%d\n",Student[i].total_marks);
    }
    printf("\nAverage Total Marks:%f",average);
}