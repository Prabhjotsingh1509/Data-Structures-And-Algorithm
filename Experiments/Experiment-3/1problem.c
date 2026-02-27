/* Write a C- Program to implement a stack data structure using an array
The Program should support the following questions:

1. Push
2. Pop
3. Peek
4. Display
5. Check Overflow and UnderFlow
The stack size should be fixed usinga constant value*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

void push_Prabhjot(int data);
void pop_Prabhjot();
void Peek_Prabhjot();
void Display_Prabhjot();

int main()
{

    int n, data;
    while (1)
    {

        printf("------Operations----------\n1. Push an Element\n2.Pop an Element\n3.Peek an Element\n4.Display an Element\n5.Exit\n");
        printf("Enter the choice");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter the number you want to push\n");
            scanf("%d", &data);
            push_Prabhjot(data);
            break;
        case 2:
            pop_Prabhjot();
            break;
        case 3:
            Peek_Prabhjot();
            break;
        case 4:
            Display_Prabhjot();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid Choice");
            break;
        }
    }
}
void push_Prabhjot(int data)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }

    top++;
    stack[top] = data;
    printf("%d pushed successfully\n", data);
}
void pop_Prabhjot()
{
    if (top == -1)
    {
        printf("Stack Underflow and Stop");
        return;
    }
    printf("Stack Poped Successfully");
    top--;
}
void Peek_Prabhjot()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Top Element is: %d\n", stack[top]);
}
void Display_Prabhjot()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack Elements are:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}