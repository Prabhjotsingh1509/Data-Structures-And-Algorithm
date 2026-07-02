#include <stdio.h>
#define SIZE 10
int visited[5] = {0};
int stack[SIZE];
int top = -1;

void DFS(int graph[4][4], int start)
{
    stack[++top] = start;
    visited[start] = 1;

    while (top != -1)
    {
        int node = stack[top--];
        printf("%d ", node);

        for (int i = 0; i < 4; i++)
        {
            if (graph[node][i] && visited[i] == 0)
            {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }
}
int main()
{
    int graph[4][4] =
        {
            {0, 1, 0, 1},
            {1, 0, 1, 0},
            {0, 1, 0, 0},
            {1, 0, 0, 1},
        };

    DFS(graph, 0);
}