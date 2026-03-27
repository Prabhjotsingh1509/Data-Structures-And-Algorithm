#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void display()
{
    struct Node *ptr = head;

    if (ptr == NULL)
    {
        printf("list is empty");
        return;
    }
    if (ptr == NULL)
    {
        printf("Empty List");
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void insertatbeginning(int data)
{
    struct Node *new = malloc(sizeof(struct Node));

    new->data = data;
    new->next = head;
    head = new;
}
void insertatpos(int pos, int data)
{
    struct Node *temp = head;
    struct Node *new = malloc(sizeof(struct Node));
    if (pos == 0)
    {
        insertatbeginning(data);
        return;
    }
    if (pos < 1)
    {
        printf("invalid Condition");
        return;
    }
    int i = 0;
    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("Invalid Position\n");
        return;
    }
    new->data = data;
    new->next = temp->next;
    temp->next = new;
}
void insertatend(int data)
{
    struct Node *temp = head;
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    if (head == NULL)
    {
        new->next = NULL;
        head = new;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->next = NULL;
}
void deleteatbeginning()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    head = head->next;
    temp->next = NULL;

    free(temp);
}
void deletebypos(int pos)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    if (pos == 0)
    {
        deleteatbeginning();
        return;
    }
    if (pos < 0)
    {
        printf("Invalid Position");
        return;
    }
    int i = 0;
    while (i < pos && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("position invalid");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void deleteatend()
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
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
            scanf("%d", &pos);
            insertatpos(pos, data);
            break;
        case 3:
            scanf("%d", &data);
            insertatend(data);
            break;
        case 4:
            deleteatbeginning();
            break;
        case 5:
            deleteatend();
            break;
        case 6:
            scanf("%d", &pos);
            deletebypos(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        }
    }
}