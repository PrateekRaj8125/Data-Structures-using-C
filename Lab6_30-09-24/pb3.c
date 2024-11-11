//3.WAP to convert an infix expression into its equivalent postfix notation.
#include <stdio.h>
#include <ctype.h>  
#include <stdlib.h> 

#define MAX 100    
void push(char stack[], int *top, char c);
char pop(char stack[], int *top);
int precedence(char operator);
int isOperator(char c);
void infixToPostfix(char infix[], char postfix[]);

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    gets(infix);  

    infixToPostfix(infix, postfix);

    printf("The postfix expression is: %s\n", postfix);

    return 0;
}


void push(char stack[], int *top, char c) {
    if (*top == MAX - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++(*top)] = c;
}


char pop(char stack[], int *top) {
    if (*top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[(*top)--];
}


int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;  
        default:
            return 0;  
    }
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX];
    int top = -1;  
    int i = 0, j = 0;  

    while (infix[i] != '\0') {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(stack, &top, c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop(stack, &top);
            }
            pop(stack, &top);  
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, c);
        }

        i++;
    }

    while (top != -1) {
        postfix[j++] = pop(stack, &top);
    }

    postfix[j] = '\0';  
}
