/*Perform following operations using function on the single linked list using menu
driven program:
i. search an element in the list
ii. sort the list in ascending order
iii. reverse the list*/
#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to search for an element in the list
void searchElement(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        current = current->next;
        position++;
    }

    printf("Element %d not found in the list.\n", key);
}

// Function to sort the list in ascending order
void sortList(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;  // List is empty or has only one element
    }

    struct Node* current;
    struct Node* index;
    int temp;

    for (current = *head; current != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }

    printf("List sorted in ascending order.\n");
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }

    *head = prev;  // Update head to new first node
    printf("List has been reversed.\n");
}

// Function to traverse the linked list and print the nodes
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Traversing the linked list:\n");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to execute the program
int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at the end\n");
        printf("2. Search for an element\n");
        printf("3. Sort the list in ascending order\n");
        printf("4. Reverse the list\n");
        printf("5. Traverse the linked list\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &key);
                searchElement(head, key);
                break;
            case 3:
                sortList(&head);
                break;
            case 4:
                reverseList(&head);
                break;
            case 5:
                traverse(head);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
