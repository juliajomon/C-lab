#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int top = -1;
int Stack[MAX_SIZE];
int item;

void push(int item) {
    if (top == MAX_SIZE - 1)
        printf("full");
    else
        Stack[++top] = item;
}

int pop() {
    if (top == -1) {
        return 0;
    } else
        return Stack[top--];
}

int peek() {
    if (top == -1) {
        return 0;
    } else
        return Stack[top];
}

int isOperand(char symbol) {
    return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z');
}

int precedence(char symbol) {
    if (symbol == '^') /* exponent operator, highest precedence*/
    {
        return (3);
    } else if (symbol == '*' || symbol == '/') {
        return (2);
    } else if (symbol == '+' || symbol == '-') {
        return (1);
    } else {
        return (-1);
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char symbol;
    i = j = 0;

    while (infix[i] != '\0') {
        symbol = infix[i];

        if (isOperand(symbol)) {
            postfix[j] = symbol;
            j++;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (peek() != '(' && top != -1) {
                postfix[j] = pop();
                j++;
            }

            if (top != -1 && peek() != '(') {
                printf("Invalid expression: Unmatched parentheses\n");
                exit(1);
            } else {
                pop(); // Discard the '('
            }
        } else {
            while (precedence(symbol) <= precedence(peek()) && top != -1) {
                postfix[j] = pop();
                j++;
            }
            push(symbol);
        }

        i++;
    }

    while (top != -1) {
        if (peek() == '(') {
            printf("Invalid expression: Unmatched parentheses\n");
            exit(1);
        }
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[50], postfix[50];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
