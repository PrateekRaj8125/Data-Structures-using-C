/*Write a program to create a structure Employee which has three data-members emp.id, name, and doj
where doj is an object of the structure Date(nested structure).*/
#include <stdio.h>

// Define a structure for Date
struct Date {
    int day;
    int month;
    int year;
};

// Define a structure for Employee, which includes a Date structure
struct Employee {
    int emp_id;
    char name[50];
    struct Date doj;  // Nested structure
};

int main() {
    struct Employee emp;

    // Get Employee details from the user
    printf("Enter Employee ID: ");
    scanf("%d", &emp.emp_id);

    printf("Enter Employee Name: ");
    getchar();  // To consume the newline left by previous input
    fgets(emp.name, sizeof(emp.name), stdin);

    printf("Enter Date of Joining (DD MM YYYY): ");
    scanf("%d %d %d", &emp.doj.day, &emp.doj.month, &emp.doj.year);

    // To remove the newline character left by fgets
    int len = strlen(emp.name);
    if (len > 0 && emp.name[len-1] == '\n') {
        emp.name[len-1] = '\0';
    }

    // Display Employee details
    printf("\nEmployee Details:\n");
    printf("Employee ID: %d\n", emp.emp_id);
    printf("Name: %s\n", emp.name);
    printf("Date of Joining: %02d-%02d-%04d\n", emp.doj.day, emp.doj.month, emp.doj.year);

    return 0;
}
