#include <stdio.h>
#define MAX 20

struct Edge
{
    int src, dest, weight;
};

struct Edge Edges[MAX];
int parent[MAX];
int rank[MAX];

int find(int v)
{
    while (parent[v] != v)
    {
        v = parent[v];
    }

    return v;
}
void unionSet(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB)
    {
        if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
        }
        else if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
        }
        else
        {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
}
int main()
{
    int v, e;

    printf("Enter number of vertices:");
    scanf("%d", &v);

    printf("Enter number of edges:");
    scanf("%d", &e);

    for (int i = 0; i < e; i++)
    {
        printf("Enter source destination Weight:");
        scanf("%d%d%d", &Edges[i].src, &Edges[i].dest, &Edges[i].weight);
    }
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    // sort edges by weight

    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (Edges[j].weight > Edges[j + 1].weight)
            {
                struct Edge temp = Edges[j];
                Edges[j] = Edges[j + 1];
                Edges[j + 1] = temp;
            }
        }
    }

    printf("\nMinnimum Spanning Tree:");

    int count = 0;

    for (int i = 0; i < e && count < v - 1; i++)
    {
        int s = Edges[i].src;
        int d = Edges[i].dest;
        int w = Edges[i].weight;

        if (find(s) != find(d))
        {
            printf("%d - %d (%d)\n", s, d, w);
            unionSet(s, d);
            count++;
        }
    }
    return 0;
}