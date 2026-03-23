// Check whether a linked list has a loop.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

struct Node *detectLoop()
{
    struct Node *slow = head;
    struct Node *fast = head;

    bool result = false;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            result = true;
            break;
        }
    }
    if (result == true)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;
}
int main()
{
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // Allocate the memory here
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // terminate the list at the third node
    third->data = 56;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = fifth;

    fifth->data = 15;
    fifth->next = third;

    struct Node *detected = detectLoop();
    if (detected != NULL)
    {
        printf("%d", detected->data);
    }
    else
    {
        printf("NO loop present");
    }
    return 0;
}