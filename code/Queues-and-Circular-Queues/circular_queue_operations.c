/*Write a C program to implement and demonstrate circular queue operations using linked list.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular queue
struct Node {
    int data;
    struct Node* next;
};

// Front and rear pointers for the circular queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return (front == NULL);
}

// Function to insert an element into the circular queue
void insert() {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        // First node in the queue, points to itself
        front = newNode;
        rear = newNode;
        newNode->next = front;
    } else {
        // Insert new node at the end and make it circular
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("Inserted %d in the queue.\n", value);
}

// Function to delete an element from the circular queue
void delete() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = front;
    if (front == rear) {
        // If there's only one element in the queue
        printf("Deleted %d from the queue.\n", front->data);
        front = rear = NULL;
    } else {
        // Remove the front element and update the front pointer
        printf("Deleted %d from the queue.\n", front->data);
        front = front->next;
        rear->next = front; // Maintain circular structure
    }

    free(temp);
}

// Function to display the elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);  // Stop when the circular structure brings us back to the front
    printf("\n");
}

// Menu driven program
int main() {
    int choice;

    while (1) {
        printf("\nCircular Queue Operations (Linked List):\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Check if queue is empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
