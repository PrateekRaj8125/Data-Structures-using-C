/*Write a C program to implement a circular queue using linked list.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
int isEmpty() {
    return (front == NULL);
}
void insert() {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
        newNode->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("Inserted %d in the queue.\n", value);
}
void delete() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = front;
    if (front == rear) {
        printf("Deleted %d from the queue.\n", front->data);
        front = rear = NULL;
    } else {
        printf("Deleted %d from the queue.\n", front->data);
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

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
    } while (temp != front);
    printf("\n");
}

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
