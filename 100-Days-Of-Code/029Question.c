/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int n, data, k, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
            head = temp = newNode;
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    if (head == NULL || k == 0)
        return 0;

    int len = 1;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }

    k = k % len;
    if (k == 0)
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }
    temp->next = head;

    int steps = len - k;
    temp = head;
    for (i = 1; i < steps; i++)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}