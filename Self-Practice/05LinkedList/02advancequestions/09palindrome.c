// Check if a linked list is a palindrome.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5
int stack[SIZE] = {0};
int top = -1;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

bool pald()
{
    struct Node *curr = head;
    while (curr != NULL)
    {
        top++;
        stack[top] = curr->data;
        curr = curr->next;
    }
    curr = head;
    while (top > -1)
    {
        if (curr->data != stack[top])
        {
            return false;
        }
        top--;
        curr = curr->next;
    }
    return true;
}
int main()
{
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 56;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = fifth;

    fifth->data = 7;
    fifth->next = NULL;
    printf("%d", pald());
}