/*Write a C program to implement deque operations using array.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the deque

// Deque structure
typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Function to initialize the deque
void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

// Function to check if the deque is full
int isFull(Deque *dq) {
    return dq->size == MAX;
}

// Function to check if the deque is empty
int isEmpty(Deque *dq) {
    return dq->size == 0;
}

// Function to insert an element at the front
void insertFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert %d at the front.\n", value);
        return;
    }
    
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0; // Initial case when deque is empty
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX; // Circular decrement
    }
    
    dq->arr[dq->front] = value;
    dq->size++;
    printf("Inserted %d at the front.\n", value);
}

// Function to insert an element at the rear
void insertRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert %d at the rear.\n", value);
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0; // Initial case when deque is empty
    } else {
        dq->rear = (dq->rear + 1) % MAX; // Circular increment
    }

    dq->arr[dq->rear] = value;
    dq->size++;
    printf("Inserted %d at the rear.\n", value);
}

// Function to delete an element from the front
void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from the front.\n");
        return;
    }

    printf("Deleted %d from the front.\n", dq->arr[dq->front]);

    if (dq->front == dq->rear) { // Only one element was present
        dq->front = dq->rear = -1; // Reset the deque to empty state
    } else {
        dq->front = (dq->front + 1) % MAX; // Circular increment
    }

    dq->size--;
}

// Function to delete an element from the rear
void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from the rear.\n");
        return;
    }

    printf("Deleted %d from the rear.\n", dq->arr[dq->rear]);

    if (dq->front == dq->rear) { // Only one element was present
        dq->front = dq->rear = -1; // Reset the deque to empty state
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX; // Circular decrement
    }

    dq->size--;
}

// Function to display the contents of the deque
void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    for (int count = 0; count < dq->size; count++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX; // Circular increment to display all elements
    }
    printf("\n");
}

// Main function to demonstrate the operations on deque
int main() {
    Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertFront(&dq, 1);
    display(&dq); // Deque: 1 5 10 20

    deleteFront(&dq);
    display(&dq); // Deque: 5 10 20

    deleteRear(&dq);
    display(&dq); // Deque: 5 10

    insertRear(&dq, 30);
    insertFront(&dq, 40);
    display(&dq); // Deque: 40 5 10 30

    return 0;
}
