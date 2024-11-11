#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Circular Queue structure
typedef struct {
    Node* front;
    Node* rear;
} CircularQueue;

// Function to initialize the queue
void initQueue(CircularQueue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue* q) {
    return q->front == NULL;
}

// Function to insert an element in the queue
void insert(CircularQueue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
        newNode->next = newNode; // Point back to itself (circular)
    } else {
        newNode->next = q->front; // New node points to front
        q->rear->next = newNode;  // Old rear points to new node
        q->rear = newNode;        // New node becomes the new rear
    }

    printf("Inserted %d into the queue.\n", value);
}

// Function to delete an element from the queue
void delete(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot delete.\n");
        return;
    }

    Node* temp = q->front;

    // Case 1: Only one element in the queue
    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } 
    // Case 2: More than one element in the queue
    else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }

    printf("Deleted %d from the queue.\n", temp->data);
    free(temp);
}

// Function to display the elements in the queue
void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    Node* temp = q->front;
    printf("Queue elements: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front); // Loop until we circle back to the front

    printf("\n");
}

// Main function with menu-driven options
int main() {
    CircularQueue q;
    initQueue(&q);

    int choice, value;

    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&q, value);
                break;
            case 2:
                delete(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                if (isEmpty(&q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
