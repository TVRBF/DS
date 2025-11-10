#include <stdio.h>

#define MAX 10   // Maximum number of vertices

int adj[MAX][MAX];     // Adjacency matrix
int visited[MAX];      // Visited array

// Depth First Search function
void dfs(int vertex, int totalVertices) {
    printf("%d ", vertex);   // Print the current vertex
    visited[vertex] = 1;     // Mark as visited

    // Explore all adjacent vertices
    for (int i = 0; i < totalVertices; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i, totalVertices);
        }
    }
}

int main() {
    int vertices, edges;
    int src, dest, start;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }

    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Input edges
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;
        adj[dest][src] = 1;   // For undirected graph
    }

    // Input starting vertex
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    // Initialize visited array
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    // Perform DFS
    printf("DFS Traversal starting from vertex %d: ", start);
    dfs(start, vertices);
    printf("\n");

    return 0;
}
