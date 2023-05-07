#include <stdio.h>

#define MAX_VERTICES 100

int adj[MAX_VERTICES][MAX_VERTICES]; 


void print_indegree(int n) {
    int indegree[MAX_VERTICES] = {0}; 

    
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    
    printf("Indegree of all vertices:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: %d\n", i+1, indegree[i]);
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
            adj[i][j] = 0;
        }
    }

    
    printf("Enter the pair of connected vertices(u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u-1][v-1] = 1; 
    }

    
    printf("\nAdjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

   
    print_indegree(n);

    return 0;
}
