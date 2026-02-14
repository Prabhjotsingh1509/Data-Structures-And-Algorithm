// Singly linked list
// Insert begin -> new.next=head;head=new
// Insert end-> move pos-1->adjust two links
// Insert Pos -> move pos-1->adjust 2 links
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtPosition(int data, int pos);
void print();

int main()
{
    head = NULL;
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);
    insertAtEnd(40);
    insertAtPosition(50, 7);
    print();
    return 0;
}

void insertAtBeginning(int data)
{
    struct Node *new = malloc(sizeof(struct Node));
    if (new == NULL)
    {
        printf("memory not allocated");
        return;
    }
    new->data = data;
    new->next = head;

    head = new;
}

void insertAtEnd(int data)
{
    struct Node *new = malloc(sizeof(struct Node));
    if (new == NULL)
    {
        printf("memory not allocated");
        return;
    }
    new->data = data;
    new->next = NULL;

    if (head == NULL)
    {
        head = new;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new;
}
void insertAtPosition(int data, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position ");
        return;
    }
    if (pos == 1)
    {
        insertAtBeginning(data);
        return;
    }
    struct Node *new = malloc(sizeof(struct Node));
    if (new == NULL)
    {
        printf("memory not allocated");
        return;
    }
    new->data = data;

    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {

        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("position out of range");
        return;
    }
    new->next = temp->next;
    temp->next = new;
}
void print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}