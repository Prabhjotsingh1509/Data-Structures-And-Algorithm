#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

struct Node
{
    int data;
    struct Node *next;
};

struct Node *hashtable[TABLE_SIZE];

int hashfunction(int key)
{
    return key % TABLE_SIZE;
}
void insert(int key)
{
    int index = hashfunction(key);
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->data = key;
    new->next = NULL;
    if (hashtable[index] == NULL)
    {
        hashtable[index] = new;
    }
    else
    {
        new->next = hashtable[index];
        hashtable[index] = new;
    }
}
void deletekey(int key)
{
    int index = hashfunction(key);
    struct Node *temp = hashtable[index];
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (prev == NULL)
            {
                hashtable[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("key deleted:%d\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct Node *temp = hashtable[i];
        printf("%d ->", i);
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void search(int key)
{
    int index = hashfunction(key);
    struct Node *temp = hashtable[index];

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        temp = temp->next;
    }

    printf("Key %d not found\n", key);
}
int main()
{
    insert(21);
    insert(22);
    insert(31);
    insert(32);
    insert(33);
    display();
    deletekey(31);
    display();
}