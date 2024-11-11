/*Write a menu driven program to perform the following operations in a stack using array by
using suitable user defined functions for each case.
a) Check if the stack is empty
b) Display the contents of stack
c) Push
d) Pop
Verify &amp; validate each function from main method.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  
void push(int stack[], int *top, int value);
int pop(int stack[], int *top);
int isEmpty(int top);
void displayStack(int stack[], int top);

int main() {
    int stack[MAX];
    int top = -1;
    int choice, value;

    while (1) {
        
        printf("\nMenu:");
        printf("\n1. Check if stack is empty");
        printf("\n2. Display stack");
        printf("\n3. Push");
        printf("\n4. Pop");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isEmpty(top)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;

            case 2:
                displayStack(stack, top);
                break;

            case 3:
                if (top == MAX - 1) {
                    printf("Stack overflow! Cannot push more elements.\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(stack, &top, value);
                }
                break;

            case 4:
                if (isEmpty(top)) {
                    printf("Stack underflow! Cannot pop from an empty stack.\n");
                } else {
                    value = pop(stack, &top);
                    printf("Popped value: %d\n", value);
                }
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void push(int stack[], int *top, int value) {
    (*top)++;
    stack[*top] = value;
    printf("%d has been pushed onto the stack.\n", value);
}

int pop(int stack[], int *top) {
    int poppedValue = stack[*top];
    (*top)--;
    return poppedValue;
}

int isEmpty(int top) {
    return top == -1;
}

void displayStack(int stack[], int top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
