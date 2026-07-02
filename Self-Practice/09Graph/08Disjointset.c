#include <stdio.h>

#define MAX 100

int parent[MAX];
int rank[MAX];

// create sets
void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// find with path compression
int find(int v)
{
    if (parent[v] != v)
        parent[v] = find(parent[v]);

    return parent[v];
}

// union by rank
void unionSet(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB)
    {
        if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
        }
        else if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
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
    int n = 5;

    makeSet(n);

    unionSet(0, 1);
    unionSet(1, 2);
    unionSet(3, 4);

    printf("Find(0) = %d\n", find(0));
    printf("Find(2) = %d\n", find(1));
    printf("Find(4) = %d\n", find(2));

    return 0;
}