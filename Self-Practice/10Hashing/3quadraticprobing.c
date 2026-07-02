#include <stdio.h>
#define SIZE 10

int hashtable[SIZE];

int init()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = -1;
    }
}
int hashfunction(int key)
{
    return key % SIZE;
}
void insert(int key)
{
    int index;
    int i = 0;

    while (i < SIZE)
    {
        index = (hashfunction(key) + i * i) % SIZE;

        if (hashtable[index] == -1)
        {
            hashtable[index] = key;
            return;
        }
        i++;
    }
    printf("key not found");
}
void deletekey(int key)
{
    int index;
    int i = 0;
    while (i < SIZE)
    {
        index = (hashfunction(key) + i * i) % SIZE;
        if (hashtable[index] == key)
        {
            hashtable[index] = -1;
        }
        i++;
    }
}
void search(int key)
{
    int index;
    int i = 0;

    while (i < SIZE)
    {
        index = (hashfunction(key) + i * i) % SIZE;
        if (hashtable[index] == key)
        {
            printf("found %d at %d", key, i);
            return;
        }
        i++;
    }
}
void display()
{
    for (int i = 0; i < SIZE; i++)
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
    insert(10);
    insert(100);
    insert(200);
    display();
    deletekey(100);
    display();
}