#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct item
{
    int data;
    int priority;
};
struct item pq[SIZE];
int n = 0;

void insert(int data, int priority)
{
    int i;

    if (n == SIZE)
    {
        printf("Priority Queue is full");
        return;
    }

    i = n - 1;
    while (i >= 0 && pq[i].priority > priority)
    {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1].data = data;
    pq[i + 1].priority = priority;
    n++;
}

void delete()
{
    if (n == 0)
    {
        printf("Priority Queue is empty");
        return;
    }

    printf("Deleted element : %d\n", pq[0].data);

    for (int i = 1; i < n; i++)
    {
        pq[i - 1] = pq[i];
    }
    n--;
}
void display()
{
    if (n == 0)
    {
        printf("Queue is empty");
        return;
    }

    printf("Data\tPriority\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\n", pq[i].data, pq[i].priority);
    }
}
int main()
{
    insert(100, 3);
    insert(200, 1);
    insert(300, 2);
    display();

    delete();

    display();

    return 0;
}