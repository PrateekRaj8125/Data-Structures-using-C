/*Write a menu driven program to implement queue operations such as Insert,
Delete, Display,
whether queue is empty etc by using linked list.*/
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;
int isEmpty() 
{
    return (front == NULL);
}
void insert() 
{
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) 
    {
        front = rear = newNode;
        printf("Inserted %d in the queue.\n", value);
        return;
    }
    rear->next = newNode;
    rear = newNode;
    printf("Inserted %d in the queue.\n", value);
}
void delete() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }
    struct node* temp = front;
    printf("Deleted %d from the queue.\n", front->data);
    front = front->next;
    if (front == NULL) 
    {
        rear = NULL;
    }
    free(temp);
}
void display() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty.\n");
        return;
    }
    struct node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() 
{
    int choice;

    while (1) 
    {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Check if queue is empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
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
                if (isEmpty()) 
                {
                    printf("Queue is empty.\n");
                } 
                else 
                {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}