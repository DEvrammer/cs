#include <stdio.h>

#define MAX_VERTICES 100

int adj[MAX_VERTICES][MAX_VERTICES]; 

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

   
    printf("Enter the pair of connected vertices (v1 v2):\n");
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

    return 0;
}
