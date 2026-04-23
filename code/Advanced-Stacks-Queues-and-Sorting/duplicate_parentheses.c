/*Write a C program to check for duplicate parentheses in an expression using stack.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum size of stack

// Stack structure
typedef struct {
    char data[MAX];
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
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// Function to check the top of the stack without popping
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0'; // Return null character if stack is empty
    }
    return s->data[s->top];
}

// Function to find duplicate parentheses in the expression
int findDuplicateParentheses(char *exp) {
    Stack s;
    initStack(&s);

    for (int i = 0; exp[i] != '\0'; i++) {
        // If the character is a closing parenthesis
        if (exp[i] == ')') {
            int count = 0;
            // Check elements inside the parentheses
            while (peek(&s) != '(') {
                pop(&s);
                count++;
            }
            // Pop the opening parenthesis '('
            pop(&s);

            // If there are no elements or only one element between parentheses, it's duplicate
            if (count <= 1) {
                return 1; // Duplicate parentheses found
            }
        }
        // Otherwise, push the character onto the stack
        else {
            push(&s, exp[i]);
        }
    }

    // No duplicate parentheses found
    return 0;
}

int main() {
    char exp[MAX];

    printf("Enter an expression: ");
    scanf("%s", exp);

    if (findDuplicateParentheses(exp)) {
        printf("Duplicate parentheses found!\n");
    } else {
        printf("No duplicate parentheses found.\n");
    }

    return 0;
}
