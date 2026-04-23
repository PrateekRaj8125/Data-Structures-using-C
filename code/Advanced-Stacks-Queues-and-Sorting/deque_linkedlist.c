/*Write a C program to implement deque using doubly linked list.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Deque structure
typedef struct {
    Node* front;
    Node* rear;
} Deque;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize the deque
void initDeque(Deque* dq) {
    dq->front = NULL;
    dq->rear = NULL;
}

// Function to check if deque is empty
int isEmpty(Deque* dq) {
    return dq->front == NULL;
}

// Function to insert an element at the front of the deque
void insertFront(Deque* dq, int value) {
    Node* newNode = createNode(value);

    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }

    printf("Inserted %d at the front.\n", value);
}

// Function to insert an element at the rear of the deque
void insertRear(Deque* dq, int value) {
    Node* newNode = createNode(value);

    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }

    printf("Inserted %d at the rear.\n", value);
}

// Function to delete an element from the front of the deque
void deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from the front.\n");
        return;
    }

    Node* temp = dq->front;

    // Case 1: Only one element in the deque
    if (dq->front == dq->rear) {
        dq->front = dq->rear = NULL;
    }
    // Case 2: More than one element in the deque
    else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }

    printf("Deleted %d from the front.\n", temp->data);
    free(temp);
}

// Function to delete an element from the rear of the deque
void deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from the rear.\n");
        return;
    }

    Node* temp = dq->rear;

    // Case 1: Only one element in the deque
    if (dq->front == dq->rear) {
        dq->front = dq->rear = NULL;
    }
    // Case 2: More than one element in the deque
    else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }

    printf("Deleted %d from the rear.\n", temp->data);
    free(temp);
}

// Function to display the deque from front to rear
void displayDeque(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }

    Node* temp = dq->front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate the operations on deque
int main() {
    Deque dq;
    initDeque(&dq);

    int choice, value;

    do {
        printf("\n--- Double-Ended Queue Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter the value to insert at the rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                displayDeque(&dq);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
