/*Problem: Create and Traverse Singly Linked List

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
void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head = NULL;
    struct Node *newnode;
    struct Node *temp;
    int n, nums;

    printf("Enter the number of element you want to enter:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct Node));
        printf("Enter the number you want to enter:");
        scanf("%d", &nums);

        newnode->data = nums;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    traversal(head);
    return 0;
}