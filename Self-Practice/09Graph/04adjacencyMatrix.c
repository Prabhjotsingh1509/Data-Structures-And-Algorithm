#include <stdio.h>
#include <stdlib.h>

int getIndex(int vertices[], int n, int value)
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
void addedge(int edges, int *vertices, int n, int **matrix)
{
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);

        int s = getIndex(vertices, n, src);
        int d = getIndex(vertices, n, dest);

        if (s == -1 || d == -2)
        {
            printf("Invalid");
            continue;
        }

        matrix[s][d] = 1;
        matrix[d][s] = 1;
    }
}
int main()
{
    int n;

    printf("Enter number of vertices:");
    scanf("%d", &n);

    int vertices[n];

    printf("enter the vertex values:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vertices[i]);
    }

    int **matrix = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    int edges;
    printf("Enter the number of edges:");
    scanf("%d", &edges);
    addedge(edges, vertices, n, matrix);
    printf("\nAdjacency Matrix\n   ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vertices[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d  ", vertices[i]);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}