/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x)
{
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int isQueueEmpty()
{
    return front > rear;
}

int isStackEmpty()
{
    return top == -1;
}

int main()
{
    int n, x;

    scanf("%d", &n);

    // Input queue
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    while (!isQueueEmpty())
    {
        push(dequeue());
    }

    // Step 2: Stack → Queue
    front = 0;
    rear = -1;
    while (!isStackEmpty())
    {
        enqueue(pop());
    }

    // Output reversed queue
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}