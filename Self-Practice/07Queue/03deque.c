#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *rear = NULL;
struct Node *front = NULL;

void push_back(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;

    if (rear == NULL)
    {
        new->prev = NULL;
        front = rear = new;
        return;
    }
    rear->next = new;
    new->prev = rear;
    rear = new;
}
void push_front(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->prev = NULL;
    if (rear == NULL)
    {
        new->next = NULL;
        front = rear = new;
        return;
    }
    new->next = front;
    front->prev = new;
    front = new;
    return;
}
void pop_front()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
}
void pop_back()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        struct Node *temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        free(temp);
    }
}
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;

    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
int main()
{
    printf("----Display Menu---\n1.push_front\n2.push_back\n3.pop_front\n4.pop_back\n5.display\n6.exit");
    int n, data;
    while (1)
    {
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            scanf("%d", &data);
            push_front(data);
            break;
        case 2:
            scanf("%d", &data);
            push_back(data);
            break;
        case 3:
            pop_front();
            break;
        case 4:
            pop_back();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid option");
        }
    }
}