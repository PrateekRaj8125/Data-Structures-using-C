/*2. Write a menu driven program to perform the following operations in a stack linked list by
using suitable user defined functions for each case.
a) Check if the stack is empty
b) Display the contents of stack
c) Push
d) pop
Verify &amp; validate each function from main method.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};


int isEmpty(struct Node* top) {
    return top == NULL;
}


void push(struct Node** top, int value) {
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

   
    if (!newNode) {
        printf("Heap overflow! Unable to push.\n");
        return;
    }

    newNode->data = value;  
    newNode->next = *top;   
    *top = newNode;        
    printf("%d has been pushed onto the stack.\n", value);
}

int pop(struct Node** top) {
    
    if (isEmpty(*top)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1;
    }

    struct Node* temp = *top;
    int poppedValue = temp->data;  
    *top = (*top)->next;           
    free(temp);                    
    return poppedValue;
}

void displayStack(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;  
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
                displayStack(top);
                break;

            case 3:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;

            case 4:
                value = pop(&top);
                if (value != -1) {
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
