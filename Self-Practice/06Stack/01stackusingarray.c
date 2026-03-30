/*Write a C- Program to implement a stack data structure using an array
The Program should support the following questions:

1. Push
2. Pop
3. Peek
4. Display
5. Check Overflow and UnderFlow
The stack size should be fixed using a constant value*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int stack[SIZE];
int top = -1;

void push(int data);
void pop();
void peek();
void display();
int main()
{
    int data, n;

    while (1)
    {
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice");
        }
    }
}
void push(int data)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = data;
}
void pop()
{
    if (top == -1)
    {
        printf("Underflow");
        return;
    }
    top--;
    printf("Top most get deleted");
}
void peek()
{
    if (top == -1)
    {
        printf("Underflow");
        return;
    }
    printf("%d", stack[top]);
}
void display()
{
    if (top == -1)
    {
        printf("Underflow");
        return;
    }
    int n = top, i;
    printf("Stack Elements are:\n");
    for (i = n; i >= 0; i--)
    {
        printf("%d\t", stack[i]);
    }
}