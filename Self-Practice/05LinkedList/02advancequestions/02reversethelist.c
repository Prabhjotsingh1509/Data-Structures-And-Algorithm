// Reverse a singly linked list.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *createNode(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
int main()
{
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    struct Node *curr = head, *next, *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }
    head = prev;
    while (prev != NULL)
    {
        printf("%d\t", prev->data);
        prev = prev->next;
    }
}