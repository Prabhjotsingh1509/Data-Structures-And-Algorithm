/*Write a C- Program to implement a stack data structure using linked list
The Program should support the following questions:

1. Push
2. Pop
3. Peek
4. Display
5. Check Overflow and UnderFlow
The stack size should be fixed using a constant value*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;
int count = 0;

struct Node *push(int data)
{
    if (top == count)
    {
        printf("stackoverflow");
        return;
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = top;
    newnode = top;
    count++;
    printf("Stack is pushed");
    return top;
}
struct Node *pop()
{
    if (count == 0)
    {
        printf("Empty Stack");
        return top;
    }
    struct Node *temp = top;
    top = top->next;
    count--;
    printf("popped sucessfully:%d", temp->data);
    free(temp);
    return top;
}
void peek()
{
    if (top == NULL)
    {
        printf("Stack Underflow");
        return;
    }
    printf("printf top element is: %d\n", top->data);
}
void display()
{
    struct Node *temp = top;
    printf("The data of the stack is ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
    }
}
int main()
{
    int n, data;

    while (1)
    {
        switch (n)
        {
            scanf("%d", &n);
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
            break;
        default:
            printf("Invalid case enter");
        }
    }
}