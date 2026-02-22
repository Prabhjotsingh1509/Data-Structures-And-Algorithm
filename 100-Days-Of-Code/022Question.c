/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int CountNodes(struct Node *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
        count++;
    }
    return count;
}
int main()
{
    struct Node *head = NULL;
    struct Node *newnode;
    struct Node *temp;
    int n, nums;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct Node));
        scanf("%d", &nums);

        newnode->data = nums;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    printf("%d", CountNodes(head));

    return 0;
}