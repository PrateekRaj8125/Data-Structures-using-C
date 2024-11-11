// WAP to reverse the sequence elements in a double linked list.
#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to append a new node at the end of the doubly linked list
void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *headRef;

    // If the linked list is empty, set the new node as the head
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    // Traverse to the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node
    last->next = newNode;
    newNode->prev = last;
}

// Function to reverse the doubly linked list
void reverse(struct Node** headRef) {
    struct Node* current = *headRef;
    struct Node* temp = NULL;

    // Traverse the list and swap next and prev for each node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // After the loop, temp is at the new head. Update headRef
    if (temp != NULL) {
        *headRef = temp->prev;
    }
}

// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to test the reversal of the list
int main() {
    struct Node* head = NULL;

    // Append some elements to the list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("Original list:\n");
    printList(head);

    // Reverse the list
    reverse(&head);

    printf("Reversed list:\n");
    printList(head);

    return 0;
}
