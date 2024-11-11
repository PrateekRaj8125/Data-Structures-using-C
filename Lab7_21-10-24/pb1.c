/*LE7.1 Write a menu driven program to implement queue operations such as Insert,
Delete, Display,
whether queue is empty etc by using array.*/
#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void display();
int isEmpty();
int isFull();
int queue[100],front=-1,rear=-1;
void main()
{
    while(1)
    {
    int choice;
        printf("\nQueue Operations:\n");
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
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
int isEmpty() {
    return (front == -1);
}
int isFull() {
    return (rear == 100 - 1);
}
void insert() {
    int element;
    if (isFull()) 
    {
        printf("Queue is full. Cannot insert element.\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &element);

    if (isEmpty()) 
    {
        front = 0;
    }

    rear++;
    queue[rear] = element;
    printf("Inserted %d in the queue.\n", element);
}
void delete() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty. Cannot delete element.\n");
        return;
    }

    printf("Deleted %d from the queue.\n", queue[front]);
    if (front == rear) 
    {
        front = rear = -1;
    } else 
    {
        front++;
    }
}
void display() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}