#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insertatbeginning(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = NULL;
    }
    head = newnode;
}
void insertatend(int data)
{
    if (head == NULL)
    {
        insertatbeginning(data);
        return;
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->data = data;
    newnode->next = NULL;
    temp->next = newnode;
    newnode->prev = temp;
}
void insertatpos(int data, int pos)
{
    if (pos == 0)
    {
        insertatbeginning(data);
        return;
    }
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (pos < 0 || pos > count)
    {
        printf("Invalid position");
        return;
    }
    if (pos == count)
    {
        insertatend(data);
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node *temp1 = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp1 = temp1->next;
    }
    newnode->next = temp1->next;
    newnode->prev = temp1;
    temp1->next = newnode;
}
void deleteatbeginning()
{
    struct Node *temp = head;

    head = head->next;
    head->prev = NULL;
    free(temp);
}
void deleteatend()
{
    struct Node *temp = head;
    struct Node *temp1 = NULL;

    while (temp->next != NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    temp->prev = NULL;
    free(temp);
}
void deleteatpos(int pos)
{
    struct Node *temp = head;
    int count = 0;
    if (pos == 0)
    {
        deleteatbeginning();
        return;
    }
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (count - 1 == pos)
    {
        deleteatend();
        return;
    }
    struct Node *temp1 = head;
    for (int i = 0; i < pos; i++)
    {
        temp1 = temp1->next;
    }
    if (temp1 == NULL)
    {
        printf("Invalid Position");
        return;
    }
    temp1->prev->next = temp1->next;
    temp1->next->prev = temp1->prev;
    free(temp1);
}
void display()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
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
            insertatpos(data, pos);
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
        }
    }
    return 0;
}