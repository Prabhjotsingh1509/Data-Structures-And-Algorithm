#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *adj[5]; // adjacency list

struct Node *createNode(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    return new;
}
int getIndex(int vertices[], int value, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (vertices[i] == value)
        {
            return i;
        }
    }
    return -1;
}
void addEdge(int vertices[], int srcValue, int destValue, int n)
{
    int src = getIndex(vertices, srcValue, n);
    int dest = getIndex(vertices, destValue, n);

    struct Node *new = createNode(dest);
    new->next = adj[src];
    adj[src] = new;

    new = createNode(src);
    new->next = adj[dest];
    adj[dest] = new;
}

void printGraph(int vertices[], int n)
{
    for (int i = 0; i < n; i++)
    {
        struct Node *temp = adj[i];
        printf("%d -> ", vertices[i]);

        while (temp)
        {
            printf("%d ", vertices[temp->data]);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int vertices[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++)
        adj[i] = NULL;

    addEdge(vertices, 10, 20, 5);
    addEdge(vertices, 10, 50, 5);
    addEdge(vertices, 20, 30, 5);
    addEdge(vertices, 20, 40, 5);
    addEdge(vertices, 20, 50, 5);
    addEdge(vertices, 30, 40, 5);
    addEdge(vertices, 40, 50, 5);

    printGraph(vertices, 5);
}