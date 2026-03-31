// Wap to insert element in queue using static memory
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = data;

    printf("Inserted: %d\n", data);
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }
    front++;

    if (front > rear)
    {
        front = rear = -1;
    }
    return;
}
void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Insert\n2. Display\n3. Delete\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            display();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            return 0;
        }
    }
}