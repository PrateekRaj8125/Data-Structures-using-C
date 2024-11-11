#include <stdio.h>
#include <stdlib.h>

#define MAX 32 // Assuming 32-bit integer

// Stack structure
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// Function to print binary representation using a stack
void printBinaryUsingStack(int n) {
    Stack s;
    initStack(&s);

    if (n == 0) {
        printf("0"); // Special case for 0
        return;
    }

    // Push remainders onto the stack
    while (n > 0) {
        int remainder = n % 2;
        push(&s, remainder);
        n = n / 2;
    }

    // Pop and print the stack contents (binary digits)
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
}

int main() {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("Binary representation of %d is: ", n);
    printBinaryUsingStack(n);

    printf("\n");
    return 0;
}
