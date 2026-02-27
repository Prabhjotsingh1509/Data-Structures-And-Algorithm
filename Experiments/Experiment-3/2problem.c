/* Write a C- Program to implement a stack data structure using an Linked List
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

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;
int count = 0;

void push_Prabhjot(int data);
void pop_Prabhjot();
void Peek_Prabhjot();
void Display_Prabhjot();

int main()
{
    int choice, data;

    while (1)
    {

        printf("------Operations----------\n1. Push an Element\n2.Pop an Element\n3.Peek an Element\n4.Display an Element\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
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
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
void push_Prabhjot(int data)
{
    if (count == SIZE)
    {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Heap Overflow! Memory not available\n");
        return;
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;

    count++;

    printf("%d pushed successfully\n", data);
}
void pop_Prabhjot()
{
    if (top == NULL)
    {
        printf("Stack Underflow! Cannot pop\n");
        return;
    }

    struct Node *temp = top;
    printf("%d popped successfully\n", temp->data);

    top = top->next;
    free(temp);

    count--;
}
void Peek_Prabhjot()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Top Element is: %d\n", top->data);
}
