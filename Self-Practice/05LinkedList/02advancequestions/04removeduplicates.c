// Remove duplicate elements from an unsorted linked list.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int hash[SIZE] = {0};
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *removeduplicates()
{
    struct Node *temp = head;
    // while (temp->next != NULL && temp != NULL)
    // {
    //     struct Node *prev = temp;
    //     while (prev != NULL && prev->next != NULL)
    //     {
    //         if (prev->next->data == temp->data)
    //         {
    //             struct Node *dup = prev->next;
    //             prev->next = dup->next;
    //             free(dup);
    //         }
    //         else
    //         {
    //             prev = prev->next;
    //         }
    //     }
    //     temp = temp->next;
    // }
    struct Node *prev = NULL;
    while (temp != NULL)
    {
        if (hash[temp->data] == 1)
        {

            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        }
        else
        {
            hash[temp->data] = 1;
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
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
    second->data = 11;
    second->next = third;

    // terminate the list at the third node
    third->data = 56;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = NULL;

    head = removeduplicates();
    display();
}