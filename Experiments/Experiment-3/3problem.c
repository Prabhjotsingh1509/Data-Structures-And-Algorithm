/*Write a C program to convert a given Infix expression into Postfix expressions using Stack
The program should:
Accept a valid infix expressions fromthe user
Use Stack operations to manage Operators
Follow operator precendence rules
Display the corresponding postfix expressions

Consider operators: +,-,*,/,^ and parenthesis()

*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

// Pop function
char pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

// Function to check precedence
int precedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char item;
    char x;

    push('(');
    strcat(infix, ")");

    for (i = 0; infix[i] != '\0'; i++)
    {
        item = infix[i];

        // If operand, add to postfix
        if (isalnum(item))
        {
            postfix[j++] = item;
        }
        // If left parenthesis, push to stack
        else if (item == '(')
        {
            push(item);
        }
        // If operator
        else if (item == '+' || item == '-' || item == '*' || item == '/' || item == '^')
        {
            while (precedence(stack[top]) >= precedence(item))
            {
                postfix[j++] = pop();
            }
            push(item);
        }
        // If right parenthesis
        else if (item == ')')
        {
            while ((x = pop()) != '(')
            {
                postfix[j++] = x;
            }
        }
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter a valid Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
