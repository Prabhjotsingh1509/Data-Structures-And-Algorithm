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

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x)
{
    queue[++rear] = x;
}

// Dequeue
int dequeue()
{
    return queue[front++];
}

// Push (stack)
void push(int x)
{
    stack[++top] = x;
}

// Pop (stack)
int pop()
{
    return stack[top--];
}

int main()
{
    int n;
    scanf("%d", &n);

    // Input queue
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    for (int i = 0; i < n; i++)
    {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Stack → Queue
    while (top != -1)
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