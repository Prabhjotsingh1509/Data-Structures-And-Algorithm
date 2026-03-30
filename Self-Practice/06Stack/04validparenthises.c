/*Q4. Valid Parentheses

Given a string containing (), {}, [], determine if it is valid.

Input: "({[]})"
Output: Valid*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

char stack[SIZE];
int top = -1;
void push(char ch)
{
    if (top == SIZE - 1)
    {
        printf("Stack overflow");
        return;
    }
    top++;
    stack[top] = ch;
}
char pop()
{
    char ch = stack[top];
    top--;
    return ch;
}
int ismatching(char open, char close)
{
    return ((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'));
}
int main()
{
    char str[100];
    printf("Enter parenthesis:");
    scanf("%s", str);

    int i = 0;
    while (str[i] != '\0')
    {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else
        {
            if (top == -1)
            {
                printf("invalid");
                return 0;
            }
            else
            {
                char popped;

                popped = pop();

                if (!ismatching(popped, ch))
                {
                    printf("invalid");
                    return 0;
                }
            }
        }
        i++;
    }
    printf("Valid");
    return 0;
}