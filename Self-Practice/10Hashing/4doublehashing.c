#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int hashtable[SIZE];

void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = -1;
    }
}

int hash1(int key)
{
    return key % SIZE;
}
int hash2(int key)
{
    return 7 - (key % 7);
}
void insert(int key)
{
    int i = 0;
    int index;

    while (i < SIZE)
    {
        index = (hash1(key) + i * hash2(key)) % SIZE;

        if (hashtable[index] == -1)
        {
            hashtable[index] = key;
            printf("inserted %d at index %d\n", key, index);
            return;
        }
        i++;
    }
    printf("Hashtable is full");
}
void search(int key)
{
    int index;
    int i = 0;

    while (i < SIZE)
    {
        index = (hash1(key) + i * hash2(key)) % SIZE;
        if (hashtable[index] == key)
        {
            printf("key %d found at %d index", key, index);
            return;
        }
        if (hashtable[index] == -1)
        {
            printf("key not found");
            return;
        }
        i++;
    }
}
void deletekey(int key)
{
    int index;
    int i = 0;

    while (i < SIZE)
    {
        index = (hash1(key) + i * hash2(key)) % SIZE;
        if (hashtable[index] == key)
        {
            hashtable[index] = -1;
            printf("key %d deleted at %d index", key, index);
            return;
        }
        if (hashtable[index] == -1)
        {
            printf("key not found");
            return;
        }
        i++;
    }
}
void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashtable[i] == -1)
        {
            printf("%d->EMPTY\n", i);
        }
        else
        {
            printf("%d->%d\n", i, hashtable[i]);
        }
    }
}
int main()
{
    init();
    insert(20);
    insert(40);
    insert(70);
    display();
}