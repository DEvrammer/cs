#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES]; 
int visited[MAX_VERTICES]; 

void dfs(int v, int n) {
    visited[v] = 1; 
    printf("%d ", v);

    
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i, n);
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

   
    printf("\nDFS Traversal:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }

    return 0;
}
