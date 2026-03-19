// This program includes the basic operation on the singly circular list.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *createNode(int data)
{
    struct Node *newnode = malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void insertatbeginning(int data)
{
    struct Node *newnode = createNode(data);
    // If List is empty
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}
void insertatend(int data)
{
    struct Node *newnode = createNode(data);
    if (head == NULL)
    {
        insertatbeginning(data);
        return;
    }
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newnode->next = head;
    temp->next = newnode;
}
void insertatpos(int pos, int data)
{
    if (head == NULL && pos < 0)
    {
        printf("Invalid Position\n");
        return;
    }
    if (pos == 0)
    {
        insertatbeginning(data);
        return;
    }
    struct Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            printf("invalid position\n");
            return;
        }
    }
    struct Node *newnode = createNode(data);

    newnode->next = temp->next;
    temp->next = newnode;
}
void deleteatstart()
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    struct Node *temp1 = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    temp1->next = NULL;
    free(temp1);
}
void deleteatend()
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *curr = head;
    struct Node *prev = NULL;
    while (curr->next != head)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = head;
    free(curr);
}
void deleteatpos(int pos)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    if (pos == 0)
    {
        deleteatstart();
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    for (int i = 0; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
        if (temp == head)
        {
            printf("invalid position");
            return;
        }
    }
    prev->next = temp->next;
    free(temp);
}
void display()
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int main()
{
    int data, n, pos;
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
            deleteatstart();
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
            printf("invalid position");
        }
    }
}