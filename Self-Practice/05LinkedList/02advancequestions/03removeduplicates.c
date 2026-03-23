// Remove duplicate elements from a sorted linked list.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *removeduplicates()
{
    struct Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data == temp->data)
        {
            struct Node *dup = temp->next;
            temp->next = dup->next;
            free(dup);
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate the memory here
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 7;
    second->next = third;

    // terminate the list at the third node
    third->data = 11;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = NULL;

    head = removeduplicates();
    display();
}