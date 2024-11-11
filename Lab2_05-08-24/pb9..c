/*Write a program to create a structure student with data-members name,age and marks,use
the function getdetail()to accept the values from the user and return the structure through
function.*/
#include <stdio.h>

// Define a structure Student
struct Student {
    char name[50];
    int age;
    float marks;
};

// Function to get details from the user and return a structure
struct Student getDetail() {
    struct Student s;

    printf("Enter name: ");
    fgets(s.name, sizeof(s.name), stdin);

    printf("Enter age: ");
    scanf("%d", &s.age);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    // To remove the newline character left by fgets
    int len = strlen(s.name);
    if (len > 0 && s.name[len-1] == '\n') {
        s.name[len-1] = '\0';
    }

    return s;
}

int main() {
    struct Student student;

    // Get the student details
    student = getDetail();

    // Display the student details
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Marks: %.2f\n", student.marks);

    return 0;
}
