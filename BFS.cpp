#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];    // Visited array
int queue[MAX];      // Queue for BFS
int front = -1, rear = -1;

// Function to add edge
void addEdge(int src, int dest) {
    adj[src][dest] = 1;
    adj[dest][src] = 1; // For undirected graph
}

// Enqueue function
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    } else {
        return queue[front++];
    }
}

// BFS function
void bfs(int start, int vertices) {
    int i, vertex;

    // Reset visited array
    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    // Reset queue
    front = rear = -1;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d: ", start);

    while ((vertex = dequeue()) != -1) {
        printf("%d ", vertex);

        for (i = 0; i < vertices; i++) {
            if (adj[vertex][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges;
    int src, dest, start;

    printf("Enter number of vertices (<= %d): ", MAX);
    scanf("%d", &vertices);

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    bfs(start, vertices);

    return 0;
}
