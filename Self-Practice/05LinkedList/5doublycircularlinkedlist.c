#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *createNode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void insertatbeginning(int data)
{
    struct Node *newnode = createNode(data);
    if (head == NULL)
    {
        newnode->prev = newnode;
        newnode->next = newnode;
        head = newnode;
        return;
    }
    struct Node *last = head->prev;

    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;
    head->prev = newnode;

    head = newnode;
}
void insertatend(int data)
{
    if (head == NULL)
    {
        insertatbeginning(data);
        return;
    }
    struct Node *newnode = createNode(data);
    struct Node *last = head->prev;
    newnode->next = head;
    head->prev = newnode;

    last->next = newnode;
    newnode->prev = last;
}
void insertatpos(int pos, int data)
{
    int count = 0;
    if (head == NULL || pos == 0)
    {
        insertatbeginning(data);
        return;
    }
    struct Node *temp = head;
    struct Node *newnode = createNode(data);
    for (int i = 0; i < pos - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }
    if (temp->next == head)
    {
        insertatend(data);
        return;
    }

    newnode->prev = temp;
    newnode->next = temp->next;

    temp->next->prev = newnode;
    temp->next = newnode;
}
void deleteatbeginning()
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct Node *last = head->prev;
    if (last == head)
    {
        head = NULL;
        return;
    }
    struct Node *temp = head;

    head = head->next;

    head->prev = last;
    last->next = head;

    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
    return;
}
void deleteatend()
{
    struct Node *last = head->prev;
    if (head == NULL)
    {
        printf("list is empty");
        return;
    }
    if (last == head)
    {
        deleteatbeginning();
        return;
    }
    last->prev->next = head;
    head->prev = last->prev;

    last->next = NULL;
    last->prev = NULL;
    free(last);
}
void deleteatpos(int pos)
{
    if (head == NULL || pos < 0)
    {
        printf("invalid Function");
        return;
    }
    if (pos == 0)
    {
        deleteatbeginning();
        return;
    }
    struct Node *temp = head;
    for (int i = 0; i < pos && temp->next != head; i++)
    {
        temp = temp->next;
    }
    if (temp->next == head)
    {
        deleteatend();
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    temp->prev = NULL;
    temp->next = NULL;
    free(temp);
}
void display()
{
    if (head == NULL)
    {
        printf("LIST IS EMPTY");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int main()
{
    int n, data, pos;
    while (1)
    {
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            scanf("%d", &data);
            insertatbeginning(data);
            break;
        case 2:
            scanf("%d", &data);
            insertatend(data);
            break;
        case 3:
            scanf("%d", &pos);
            scanf("%d", &data);
            insertatpos(pos, data);
            break;
        case 4:
            deleteatbeginning();
            break;
        case 5:
            deleteatend();
            break;
        case 6:
            scanf("%d", &pos);
            deleteatpos(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid Option\n");
            break;
        }
    }
}