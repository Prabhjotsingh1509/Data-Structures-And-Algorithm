#include <stdio.h>
#include <stdlib.h>

int size = 5;
int count = 0;
int *hashtable;

int hashfunction(int key)
{
    return key % size;
}

void rehash()
{
    int oldsize = size;
    int *oldtable = hashtable;

    size = size * 2; // increase table size
    hashtable = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        hashtable[i] = -1;

    count = 0;

    for (int i = 0; i < oldsize; i++)
    {
        if (oldtable[i] != -1)
        {
            int j = 0;

            int key = oldtable[i];
            int index;
            while (j < size)
            {
                index = (hashfunction(key) + j) % size;
                if (hashtable[index] == -1)
                {
                    hashtable[index] = key;
                    count++;
                    break;
                }
                j++;
            }
        }
    }
    free(oldtable);
}

void insert(int key)
{
    float loadfactor = (float)count / size;

    if (loadfactor >= 0.7)
    {
        printf("Rehashing...\n");
        rehash();
    }

    int index;
    int i = 0;
    while (i < size)
    {
        index = (hashfunction(key) + i) % size;
        if (hashtable[index] == -1)
        {
            hashtable[index] = key;
            count++;
            return;
        }
        i++;
    }
}

void display()
{
    for (int i = 0; i < size; i++)
    {
        if (hashtable[i] == -1)
            printf("%d -> EMPTY\n", i);
        else
            printf("%d -> %d\n", i, hashtable[i]);
    }
}

int main()
{
    hashtable = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        hashtable[i] = -1;

    insert(10);
    insert(20);
    insert(22);
    insert(30);
    insert(40);
    insert(50);

    display();

    return 0;
}