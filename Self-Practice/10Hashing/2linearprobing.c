#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int hashtable[TABLE_SIZE];
void init()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable[i] = -1;
    }
}
int hashfunction(int key)
{
    return key % TABLE_SIZE;
}
void insert(int key)
{
    int index = hashfunction(key);
    int i = 0;
    while (i < TABLE_SIZE)
    {
        index = (hashfunction(key) + i) % TABLE_SIZE;

        if (hashtable[index] == -1)
        {
            hashtable[index] = key;
            printf("%d inserted at %d index\n", key, index);
            return;
        }
        i++;
    }
}
void deletekey(int key)
{
    int index;
    int i = 0;
    while (i < TABLE_SIZE)
    {
        index = (hashfunction(key) + i) % TABLE_SIZE;

        if (hashtable[index] == key)
        {
            hashtable[index] = -1;
            printf("Deleted:%d\n", key);
            return;
        }
        i++;
    }
    printf("key not found");
}
void search(int key)
{
    int i = 0;
    int index;

    while (i < TABLE_SIZE)
    {
        index = (hashfunction(key) + i) % TABLE_SIZE;

        if (hashtable[index] == -1)
        {
            printf("Key not found\n");
            return;
        }

        if (hashtable[index] == key)
        {
            printf("Key %d found at index %d\n", key, index);
            return;
        }

        i++;
    }

    printf("Key not found\n");
}
void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("%d->", i);
        if (hashtable[i] == -1)
        {
            printf("Empty\n");
        }
        else
        {
            printf("%d\n", hashtable[i]);
        }
    }
}
int main()
{
    init();
    insert(15);
    insert(25);
    search(25);
    // deletekey(25);
    display();
}