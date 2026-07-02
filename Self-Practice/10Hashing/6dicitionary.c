#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct Node
{
    char key[50];
    char value[100];
    struct Node *next;
};

struct Node *hashtable[TABLE_SIZE];

int hashfunction(char *key)
{
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++)
        sum += key[i];

    return sum % TABLE_SIZE;
}

void insert(char *key, char *value)
{
    int index = hashfunction(key);

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    strcpy(new->key, key);
    // new->key = key;
    strcpy(new->value, value);
    new->next = NULL;

    new->next = hashtable[index];
    hashtable[index] = new;
}

void search(char *key)
{
    int index = hashfunction(key);
    struct Node *temp = hashtable[index];

    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            printf("Meaning: %s\n", temp->value);
            return;
        }
        temp = temp->next;
    }

    printf("Word not found\n");
}

void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct Node *temp = hashtable[i];

        printf("%d -> ", i);

        while (temp != NULL)
        {
            printf("(%s : %s) -> ", temp->key, temp->value);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    insert("apple", "a fruit");
    insert("book", "collection of pages");
    insert("car", "a vehicle");

    display();

    printf("\nSearch result:\n");
    search("book");

    return 0;
}