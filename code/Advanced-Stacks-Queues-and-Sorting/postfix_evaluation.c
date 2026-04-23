/*Write a C program to evaluate a postfix expression using stack.*/
#include <stdio.h>
#include <ctype.h>  // for isdigit() function
#include <stdlib.h> // for atoi() and exit() function

#define MAX 100 // Maximum size of stack

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

// Function to evaluate postfix expression
int evaluatePostfix(char *exp) {
    Stack s;
    initStack(&s);

    for (int i = 0; exp[i] != '\0'; i++) {
        // If the character is a digit, push it to the stack
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0'); // Convert char to int and push to stack
        }
        // If the character is an operator, pop two operands, perform the operation, and push the result back
        else {
            int op2 = pop(&s);
            int op1 = pop(&s);
            switch (exp[i]) {
                case '+':
                    push(&s, op1 + op2);
                    break;
                case '-':
                    push(&s, op1 - op2);
                    break;
                case '*':
                    push(&s, op1 * op2);
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    push(&s, op1 / op2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
        }
    }

    // The final result will be on the top of the stack
    return pop(&s);
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    
    int result = evaluatePostfix(exp);
    printf("Result of postfix expression: %d\n", result);

    return 0;
}
