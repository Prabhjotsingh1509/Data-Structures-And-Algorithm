/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head1 = NULL, *head2 = NULL, *temp, *newNode;
    int n, m, data, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head1 == NULL)
            head1 = temp = newNode;
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &data);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head2 == NULL)
            head2 = temp = newNode;
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    int len1 = 0, len2 = 0;
    struct Node *ptr1 = head1, *ptr2 = head2;

    while (ptr1 != NULL)
    {
        len1++;
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL)
    {
        len2++;
        ptr2 = ptr2->next;
    }

    ptr1 = head1;
    ptr2 = head2;

    int diff = (len1 > len2) ? len1 - len2 : len2 - len1;

    if (len1 > len2)
        for (i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    else
        for (i = 0; i < diff; i++)
            ptr2 = ptr2->next;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data == ptr2->data)
        {
            printf("%d", ptr1->data);
            return 0;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection");
    return 0;
}