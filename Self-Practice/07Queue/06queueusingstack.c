#include <stdio.h>
#define MAX 100

typedef struct
{
    int stack1[MAX];
    int stack2[MAX];
    int top1;
    int top2;
} Queue;

// Initialize queue
void init(Queue *q)
{
    q->top1 = -1;
    q->top2 = -1;
}

// Push into stack1
void push1(Queue *q, int x)
{
    q->stack1[++q->top1] = x;
}

// Push into stack2
void push2(Queue *q, int x)
{
    q->stack2[++q->top2] = x;
}

// Pop from stack1
int pop1(Queue *q)
{
    return q->stack1[q->top1--];
}

// Pop from stack2
int pop2(Queue *q)
{
    return q->stack2[q->top2--];
}

// Enqueue (costly)
void enqueue(Queue *q, int x)
{
    while (q->top1 != -1)
    {
        push2(q, pop1(q));
    }

    push1(q, x);

    while (q->top2 != -1)
    {
        push1(q, pop2(q));
    }

    printf("Inserted: %d\n", x);
}

// Dequeue (efficient)
void dequeue(Queue *q)
{
    if (q->top1 == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Deleted: %d\n", pop1(q));
}

// Display
void display(Queue *q)
{
    if (q->top1 == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->top1; i >= 0; i--)
        printf("%d ", q->stack1[i]);

    printf("\n");
}

int main()
{
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);

    display(&q);

    return 0;
}