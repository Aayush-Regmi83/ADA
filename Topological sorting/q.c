#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;
int V;

// Enqueue function
void enqueue(int x)
{
    queue[++rear] = x;
}

// Dequeue function
int dequeue()
{
    return queue[front++];
}

// Topological Sort using Kahn's Algorithm
void topologicalSort()
{
    int i, j, count = 0;

    // Initialize indegree array
    for (i = 0; i < V; i++)
    {
        indegree[i] = 0;
    }

    // Calculate indegree of each vertex
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (adj[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    // Insert vertices with indegree 0 into queue
    for (i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            enqueue(i);
        }
    }

    printf("\nTopological Order: ");

    // Process queue
    while (front <= rear)
    {
        int u = dequeue();
        printf("%d ", u);
        count++;

        for (j = 0; j < V; j++)
        {
            if (adj[u][j] == 1)
            {
                indegree[j]--;

                if (indegree[j] == 0)
                {
                    enqueue(j);
                }
            }
        }
    }

    // Check for cycle
    if (count != V)
    {
        printf("\nGraph contains a cycle!");
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();

    return 0;
}