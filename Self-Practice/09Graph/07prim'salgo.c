#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct PQ
{
    int vertex;
    int weight;
    int parent;
};

struct PQ pq[MAX];
int size = 0;
struct Node
{
    int data;
    int weight;
    struct Node *next;
};
struct Node *createNode(int data, int weight)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->weight = weight;
    new->next = NULL;
    return new;
}
int getindex(int vertices[], int value, int n)
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
int addedge(struct Node *adj[], int vertices[], int src, int dest, int n, int weight)
{
    int s = getindex(vertices, src, n);
    int d = getindex(vertices, dest, n);

    struct Node *new = createNode(s, weight);
    new->next = adj[d];
    adj[d] = new;

    new = createNode(d, weight);
    new->next = adj[s];
    adj[s] = new;
}
void enpq(int vertex, int weight, int parent)
{
    int i = size - 1;

    while (i >= 0 && pq[i].weight > weight)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1].vertex = vertex;
    pq[i + 1].weight = weight;
    pq[i + 1].parent = parent;

    size++;
}
void depq(int *vertex, int *weight, int *parent)
{
    *vertex = pq[0].vertex;
    *weight = pq[0].weight;
    *parent = pq[0].parent;

    for (int i = 1; i < size; i++)
    {
        pq[i - 1] = pq[i];
    }

    size--;
}
int isempty()
{
    return size == 0;
}
int prim(struct Node *adj[], int vertices[], int n)
{
    int visited[5] = {0};
    int mstcost = 0;

    enpq(0, 0, -1);
    while (!isempty())
    {
        int u, w, parent;
        depq(&u, &w, &parent);

        if (visited[u] == 1)
            continue;
        mstcost += w;
        visited[u] = 1;
        if (parent != -1)
        {
            printf("%d - %d (%d)\n", vertices[parent], vertices[u], w);
        }

        struct Node *temp = adj[u];
        while (temp != NULL)
        {
            if (visited[temp->data] == 0)
            {
                enpq(temp->data, temp->weight, u);
            }
            temp = temp->next;
        }
    }
    return mstcost;
}
int main()
{
    struct Node *adj[5];
    int vertices[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++)
    {
        adj[i] = NULL;
    }

    addedge(adj, vertices, 10, 20, 5, 25);
    addedge(adj, vertices, 10, 50, 5, 1);
    addedge(adj, vertices, 20, 40, 5, 20);
    addedge(adj, vertices, 40, 30, 5, 10);
    addedge(adj, vertices, 40, 50, 5, 1);

    int mstcost = prim(adj, vertices, 5);
    printf("%d", mstcost);
    return 0;
}