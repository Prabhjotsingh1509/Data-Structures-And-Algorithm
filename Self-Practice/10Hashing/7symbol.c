#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10

struct Symbol
{
    char name[50];
    char type[20];
    int value;
    struct Symbol *next;
};

struct Symbol *hashtable[TABLE_SIZE];

int hashfunction(char *name)
{
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++)
        sum += name[i];

    return sum % TABLE_SIZE;
}

void insert(char *name, char *type, int value)
{
    int index = hashfunction(name);

    struct Symbol *new = (struct Symbol *)malloc(sizeof(struct Symbol));

    strcpy(new->name, name);
    strcpy(new->type, type);
    new->value = value;
    new->next = NULL;

    new->next = hashtable[index];
    hashtable[index] = new;
}

void search(char *name)
{
    int index = hashfunction(name);
    struct Symbol *temp = hashtable[index];

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("Name: %s\n", temp->name);
            printf("Type: %s\n", temp->type);
            printf("Value: %d\n", temp->value);
            return;
        }
        temp = temp->next;
    }

    printf("Symbol not found\n");
}

void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct Symbol *temp = hashtable[i];

        printf("%d -> ", i);

        while (temp != NULL)
        {
            printf("(%s, %s, %d) -> ", temp->name, temp->type, temp->value);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    insert("x", "int", 10);
    insert("y", "int", 20);
    insert("z", "float", 30);

    display();

    printf("\nSearching symbol:\n");
    search("y");

    return 0;
}