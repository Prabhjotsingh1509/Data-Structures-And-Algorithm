#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int q1[SIZE], q2[SIZE];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

// queue implementation
int isempty1()
{
    return front1 == -1;
}
int isempty2()
{
    return front2 == -1;
}
void enqueue1(int data)
{
    if (rear1 == SIZE - 1)
    {
        printf("Queue is full");
        return;
    }
    if (front1 == -1)
    {
        front1 = 0;
    }
    rear1++;
    q1[rear1] = data;
}

void enqueue2(int data)
{
    if (rear2 == SIZE - 1)
    {
        printf("Queue is full");
        return;
    }
    if (front2 == -1)
    {
        front2 = 0;
    }
    rear2++;
    q2[rear2] = data;
}
void dequeue1()
{
    if (isempty1())
    {
        printf("List is empty");
        return;
    }
    front1++;
    if (front1 > rear1)
    {
        front1 = rear1 = -1;
    }
}
void dequeue2()
{
    if (isempty2())
    {
        printf("List is empty");
        return;
    }
    front2++;
    if (front2 > rear2)
    {
        front2 = rear2 = -1;
    }
}
// -------Stack Operation--------
void push(int data)
{
    while (!isempty1())
    {
        enqueue2(q1[front1]);
        dequeue1();
    }
    enqueue1(data);
    while (!isempty2())
    {
        enqueue1(q2[front2]);
        dequeue2();
    }
}
void pop()
{
    if (isempty1())
    {
        printf("Stack is empty");
        return;
    }
    dequeue1();
}
void peek()
{
    if (front1 == -1)
    {
        printf("list is empty");
        return;
    }
    printf("%d", q1[front1]);
}
void display()
{
    if (front1 == -1)
    {
        printf("List is empty");
    }
    int i;
    for (i = front1; i <= rear1; i++)
    {
        printf("%d\t", q1[i]);
    }
}
int main()
{
    int n, data;
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
            printf("invalid case");
            break;
        }
    }
}