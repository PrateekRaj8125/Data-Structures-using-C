/*Write a C program to evaluate an infix expression using stacks.*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100


void pushOperand(int operandStack[], int *top, int value);
int popOperand(int operandStack[], int *top);
void pushOperator(char operatorStack[], int *top, char operator);
char popOperator(char operatorStack[], int *top);


int precedence(char operator);
int applyOperator(char operator, int operand1, int operand2);
void evaluateTop(int operandStack[], int *operandTop, char operatorStack[], int *operatorTop);

int main() {
    char infix[MAX];
    int operandStack[MAX], operandTop = -1;
    char operatorStack[MAX], operatorTop = -1;

    printf("Enter an infix expression: ");
    gets(infix); 

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isdigit(c)) {
            int num = 0;
            while (isdigit(infix[i])) {
                num = num * 10 + (infix[i] - '0');
                i++;
            }
            i--; 
            pushOperand(operandStack, &operandTop, num);
        }
        else if (c == '(') {
            pushOperator(operatorStack, &operatorTop, c);
        }
        else if (c == ')') {
            while (operatorStack[operatorTop] != '(') {
                evaluateTop(operandStack, &operandTop, operatorStack, &operatorTop);
            }
            popOperator(operatorStack, &operatorTop);  // Pop the '('
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (operatorTop != -1 && precedence(operatorStack[operatorTop]) >= precedence(c)) {
                evaluateTop(operandStack, &operandTop, operatorStack, &operatorTop);
            }
            pushOperator(operatorStack, &operatorTop, c);
        }
    }

    while (operatorTop != -1) {
        evaluateTop(operandStack, &operandTop, operatorStack, &operatorTop);
    }

    printf("The result of the expression is: %d\n", operandStack[operandTop]);

    return 0;
}

void pushOperand(int operandStack[], int *top, int value) {
    operandStack[++(*top)] = value;
}

int popOperand(int operandStack[], int *top) {
    return operandStack[(*top)--];
}

void pushOperator(char operatorStack[], int *top, char operator) {
    operatorStack[++(*top)] = operator;
}

char popOperator(char operatorStack[], int *top) {
    return operatorStack[(*top)--];
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

int applyOperator(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': {
            int result = 1;
            for (int i = 0; i < operand2; i++) {
                result *= operand1;
            }
            return result;
        }
        default: return 0;
    }
}

void evaluateTop(int operandStack[], int *operandTop, char operatorStack[], int *operatorTop) {
    int operand2 = popOperand(operandStack, operandTop);
    int operand1 = popOperand(operandStack, operandTop);
    char operator = popOperator(operatorStack, operatorTop);
    int result = applyOperator(operator, operand1, operand2);
    pushOperand(operandStack, operandTop, result);
}
