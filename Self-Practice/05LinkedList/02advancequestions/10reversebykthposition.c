// Reverse a linked list in groups of size K.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *reverseK(struct Node *head, int k)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;
    int count = 0;

    // Step 1: Reverse first k nodes
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 2: Recursively reverse remaining list
    if (next != NULL)
    {
        head->next = reverseK(next, k);
    }

    // Step 3: Return new head
    return prev;
}
void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
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
    second->data = 6;
    second->next = third;

    // terminate the list at the third node
    third->data = 3;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = NULL;
    int k;
    scanf("%d", &k);
    head = reverseK(head, k);
    display();
}