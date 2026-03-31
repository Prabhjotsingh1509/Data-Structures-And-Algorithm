// Wap to insert element in queue using linkedlist
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;

    // If queue is empty
    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Inserted: %d\n", data);
}
void dequeue()
{
    if (front == NULL)
    {
        printf("List is empty");
        return;
    }
    struct Node *temp = front;

    front = front->next;
    free(temp);
}
void display()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Enqueue\n2. Display\n3. Delete\n4.Exit\n");
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