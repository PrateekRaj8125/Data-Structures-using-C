/*Write a menu driven program to perform the following operations on a queue
I) Print the middle element present in queue.
II) Print the second largest element present in the queue*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for queue
struct Queue {
    int items[MAX];
    int front, rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

// Function to enqueue an element
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
    printf("%d enqueued to the queue\n", value);
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return INT_MIN;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return item;
}

// Function to display the queue
void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

// Function to print the middle element of the queue
void printMiddleElement(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No middle element.\n");
        return;
    }
    int middleIndex = (q->front + q->rear) / 2;
    printf("Middle element in the queue: %d\n", q->items[middleIndex]);
}

// Function to find the second largest element in the queue
void printSecondLargestElement(struct Queue* q) {
    if (isEmpty(q) || (q->rear - q->front) < 1) {
        printf("Queue does not have enough elements to find the second largest!\n");
        return;
    }
    
    int largest = INT_MIN, secondLargest = INT_MIN;

    // Traverse the queue to find the largest and second largest elements
    for (int i = q->front; i <= q->rear; i++) {
        if (q->items[i] > largest) {
            secondLargest = largest;
            largest = q->items[i];
        } else if (q->items[i] > secondLargest && q->items[i] != largest) {
            secondLargest = q->items[i];
        }
    }

    if (secondLargest == INT_MIN)
        printf("All elements are the same or not enough distinct elements to find second largest!\n");
    else
        printf("Second largest element in the queue: %d\n", secondLargest);
}

// Main program with a menu-driven approach
int main() {
    struct Queue q;
    initQueue(&q);
    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Print Middle Element\n");
        printf("5. Print Second Largest Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != INT_MIN)
                    printf("Dequeued element: %d\n", value);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printMiddleElement(&q);
                break;
            case 5:
                printSecondLargestElement(&q);
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
