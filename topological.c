#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES]; 
int visited[MAX_VERTICES]; 
int topo_order[MAX_VERTICES]; 
int n; 

void dfs(int v, int *index) {
    visited[v] = 1;

    for (int u = 0; u < n; u++) {
        if (graph[v][u] && !visited[u]) {
            dfs(u, index);
        }
    }

    topo_order[--(*index)] = v;
}

void topologicalSort() {
    int index = n;
    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            dfs(v, &index);
        }
    }
}

int main() {
    int m; 
    int u, v; 

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u-1][v-1] = 1;
    }

    
    topologicalSort();

    
    printf("Topological order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", topo_order[i]+1);
    }
    printf("\n");

    return 0;
}
