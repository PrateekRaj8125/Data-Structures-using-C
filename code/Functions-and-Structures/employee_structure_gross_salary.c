/*Write a C program using structure and array of structures to store employee details such as:

Employee ID
Name
Designation
Basic Salary
HRA (%)
DA (%)

Calculate and display the gross salary of the employee.*/
#include<stdio.h>
#include<string.h>
struct Employee
{
 char name[100], designation[100],emp_id[100];
 float basic_salary, hra, da;
}employee;
void main()
{
    printf("Enter Employee Information:\n");
    printf("---------------------------\n");
    printf("Enter Employee ID:");
    getchar();
    scanf("%s",&employee.emp_id);
    printf("Enter Employee name:");
    getchar();
    scanf("%s",&employee.name);
    printf("Enter Designation:");
    getchar();
    scanf("%s",&employee.designation);
    printf("Enter Basic Salary:");
    scanf("%f",&employee.basic_salary);
    printf("Enter Hra percentage:");
    scanf("%f",&employee.hra);
    printf("Enter Da percentage:");
    scanf("%f",&employee.da);
    float hra,da,gross_salary;
    hra=employee.hra/100*employee.basic_salary;
    da=employee.da/100*employee.basic_salary;
    gross_salary=employee.basic_salary+hra+da;
    printf("\nEmployee Information Slip\n");
    printf("-------------------------\n");
    printf("Employee ID:%s\n",employee.emp_id);
    printf("Name:%s\n",employee.name);
    printf("Designation:%s\n",employee.designation);
    printf("Basic Salary:%f\n",employee.basic_salary);
    printf("Home Rent Allowance:%f\n",hra);
    printf("Dearness Allowance:%f\n",da);
    printf("Gross Salary:123456%f\n",gross_salary);
}