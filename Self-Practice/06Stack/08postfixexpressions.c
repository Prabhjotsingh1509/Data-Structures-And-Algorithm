/*
Q9. Postfix Expression Evaluation
Evaluate a postfix expression.
Input: "23*54*+9-"
Output: 17
*/
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define SIZE 100
int stack[SIZE];
int top = -1;
void push(int ch)
{
    if (top == SIZE - 1)
    {
        printf("Stack overflow");
        return;
    }
    top++;
    stack[top] = ch;
}
int pop()
{
    if (top == -1)
    {
        printf("List is empty");
        return -1;
    }
    return stack[top--];
}
int main()
{
    char str[SIZE];
    printf("Enter the postifix expressions:");
    scanf("%s", str);
    int i = 0;
    while (str[i] != '\0')
    {
        char ch = str[i];
        if (isdigit(str[i]) == 1)
        {
            push(str[i] - '0');
        }
        else
        {
            int a = pop();
            int b = pop();

            switch (ch)
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b / a);
                break;
            case '^':
                push(pow(b, a));
                break;
            }
        }
        i++;
    }
    printf("%d", pop());
}
