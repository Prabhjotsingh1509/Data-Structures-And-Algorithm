#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int Queue[SIZE];
int front = -1;
int rear = -1;

int stack[SIZE];
int top = -1;

struct Node
{
    int vertex;
    struct Node *next;
};
struct Graph
{
    int numvertices;
    struct Node **adjLists;
    int *visited;
};
int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty");
        return 0;
    }
    int s = Queue[front];
    front++;
    if (front > rear)
    {
        front = rear = -1;
    }
    return s;
}
void enqueue(int data)
{
    if (rear == SIZE - 1)
    {
        printf("Overflow");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    Queue[rear] = data;
}
int isempty()
{
    return front == -1;
}
struct Node *createNode(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->vertex = data;
    new->next = NULL;
    return new;
}
struct Graph *creategraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numvertices = vertices;

    graph->adjLists = (struct Node **)malloc(vertices * sizeof(struct Node *));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < graph->numvertices; i++)
    {
        graph->visited[i] = 0;
    }
    return graph;
}
void addEdge(struct Graph *graph, int src, int dest)
{
    // add edge src to dest
    struct Node *new = createNode(dest);
    new->next = graph->adjLists[src];
    graph->adjLists[src] = new;

    // add dest to src
    new = createNode(src);
    new->next = graph->adjLists[dest];
    graph->adjLists[dest] = new;
}
void BFS(int start, struct Graph *graph)
{
    enqueue(start);
    // visited[start] = 0;
    graph->visited[start] = 1;

    while (!isempty())
    {
        int s = dequeue();
        printf("%d ", s);

        struct Node *temp = graph->adjLists[s];

        while (temp != NULL)
        {
            if (!graph->visited[temp->vertex])
            {
                graph->visited[temp->vertex] = 1;
                enqueue(temp->vertex);
            }
            temp = temp->next;
        }
    }
}
void push(int data)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = data;
}
int pop()
{
    if (top == -1)
    {
        printf("Underflow");
        return 0;
    }
    int s = stack[top];
    top--;
    return s;
}
int isemptys()
{
    return top == -1;
}
void DFS(struct Graph *graph, int start)
{
    printf("\n");
    push(start);
    graph->visited[start] = 1;
    while (!isemptys())
    {
        int s = pop();
        printf("%d ", s);
        struct Node *temp = graph->adjLists[s];

        while (temp != NULL)
        {
            if (!graph->visited[temp->vertex])
            {
                graph->visited[temp->vertex] = 1;
                push(temp->vertex);
            }
            temp = temp->next;
        }
    }
}

void printGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->numvertices; v++)
    {
        struct Node *temp = graph->adjLists[v];
        printf("%d->", v);

        while (temp != NULL)
        {
            printf("%d,", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    struct Graph *graph = creategraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    BFS(0, graph);
    for (int i = 0; i < 5; i++)
    {
        graph->visited[i] = 0;
    }
    DFS(graph, 0);
}