#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES]; 
int visited[MAX_VERTICES]; 
int queue[MAX_VERTICES]; 
int front = -1, rear = -1; 

void enqueue(int vertex) {
    if (rear == MAX_VERTICES-1) {
        printf("Queue overflow\n");
        exit(1);
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        exit(1);
    }
    int vertex = queue[front];
    front++;
    return vertex;
}

void bfs(int n, int start) {
    visited[start] = 1;
    enqueue(start);

    while (front != -1) {
        int vertex = dequeue();
        printf("%d ", vertex+1);

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int n, m; 
    int u, v; 

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u-1][v-1] = 1;
        graph[v-1][u-1] = 1; 
    }

    
    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("BFS traversal starting from vertex %d: ", start);
    bfs(n, start-1);
    printf("\n");

    return 0;
}
