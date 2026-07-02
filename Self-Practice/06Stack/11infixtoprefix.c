/*Infix to Postfix Conversion

Convert an infix expression into postfix.

Input: A + B * C
Output:+B*AC
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
char stack[SIZE];
int top = -1;
int isoperand(char ch)
{
    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(char ch)
{
    if (top == SIZE - 1)
    {
        printf("stack overflow");
        return;
    }
    top++;
    stack[top] = ch;
}
char pop()
{
    if (top == -1)
    {
        printf("Stack is empty");
        return '\0';
    }
    char ch = stack[top];
    top--;
    return ch;
}
int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int prec(char ch)
{
    if (ch == '^')
    {
        return 4;
    }
    else if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char str[SIZE];
    int i = 0;
    int j = 0;
    char pos[SIZE];
    printf("Enter the infix expression");
    scanf("%s", str);
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end)
    {

        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    for (int k = 0; str[k] != '\0'; k++)
    {
        if (str[k] == '(')
            str[k] = ')';
        else if (str[k] == ')')
            str[k] = '(';
    }
    // printf("%s", str);
    while (str[i] != '\0')
    {
        if (isoperand(str[i]) == 1)
        {
            pos[j++] = str[i];
        }
        else if (str[i] == '(')
        {
            push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (stack[top] != '(')
            {
                pos[j++] = pop();
            }
            pop();
        }
        else
        {
            while (!isempty() && prec(str[i]) < prec(stack[top]))
            {
                pos[j++] = pop();
            }
            push(str[i]);
        }
        i++;
    }
    while (!isempty())
    {
        pos[j++] = pop();
    }
    pos[j] = '\0';
    strrev(pos);
    printf("%s", pos);
    return 0;
}