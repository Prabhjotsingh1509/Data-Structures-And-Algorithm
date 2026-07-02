#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};
struct Graph
{
    int numvertices;
    struct Node **adjLists;
    int *vertices;
};
struct Node *createNode(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->vertex = data;
    new->next = NULL;
    return new;
}
struct Graph *creategraph(int vertices[], int n)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numvertices = n;
    graph->vertices = vertices;
    graph->adjLists = (struct Node **)malloc(n * sizeof(struct Node *));

    for (int i = 0; i < n; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}
int getIndex(struct Graph *graph, int value)
{
    for (int i = 0; i < graph->numvertices; i++)
    {
        if (graph->vertices[i] == value)
        {
            return i;
        }
    }
    return -1;
}
void addEdge(struct Graph *graph, int srcValue, int destValue)
{
    int src = getIndex(graph, srcValue);
    int dest = getIndex(graph, destValue);

    if (src == -1 || dest == -1)
    {
        printf("Invalid vertex\n");
        return;
    }
    // add edge src to dest
    struct Node *new = createNode(dest);
    new->next = graph->adjLists[src];
    graph->adjLists[src] = new;

    // add dest to src
    new = createNode(src);
    new->next = graph->adjLists[dest];
    graph->adjLists[dest] = new;
}
void printGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->numvertices; v++)
    {
        struct Node *temp = graph->adjLists[v];
        printf("%d->", graph->vertices[v]);

        while (temp != NULL)
        {
            printf("%d ", graph->vertices[temp->vertex]);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int vertices[] = {10, 20, 30, 40, 50};
    int n = 5;
    struct Graph *graph = creategraph(vertices, n);

    addEdge(graph, 10, 20);
    addEdge(graph, 10, 50);
    addEdge(graph, 20, 30);
    addEdge(graph, 20, 40);
    addEdge(graph, 20, 50);
    addEdge(graph, 30, 40);
    addEdge(graph, 40, 50);
    printGraph(graph);
}