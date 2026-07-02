#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int visited[4] = {0};
int front = 0, rear = 0;
void BFS(int graph[4][4], int start)
{
    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS traversal");
    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < 4; i++)
        {
            if (graph[node][i] && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
int main()
{
    int graph[4][4] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 1},
    };

    BFS(graph, 0);
}