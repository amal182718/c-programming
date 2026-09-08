#include <stdio.h>

#define MAX 20   // Maximum number of vertices

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX];

// Function to add element to queue
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

// Function to remove element from queue
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Perform BFS on graph
void BFS(int adj[MAX][MAX], int n, int start) {
    int i, current;

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d: ", start);

    while (front <= rear) {
        current = dequeue();
        printf("%d ", current);

        // Visit all adjacent vertices
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int adj[MAX][MAX];
    int n, start;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    BFS(adj, n, start);

    return 0;
}
