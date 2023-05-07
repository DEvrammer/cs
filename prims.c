#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES]; 
int parent[MAX_VERTICES]; 
int key[MAX_VERTICES]; 

int minKey(int n, int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int n) {
    int mstSet[MAX_VERTICES];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n-1; count++) {
        int u = minKey(n, key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
}


int main() {
    int n, m; 
    int u, v, w; 

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    
    printf("Enter the edges and their weights (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u-1][v-1] = w;
        graph[v-1][u-1] = w; 
    }

   
    primMST(n);

    
    printf("\nEdges in the MST:\n");
    for (int i = 1; i < n; i++) {
        printf("%d -> %d\t", parent[i]+1, i+1);
    }

    return 0;
}
