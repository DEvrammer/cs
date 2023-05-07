#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100


struct node {
    int vertex;
    struct node* next;
};


struct node* adjList[MAX_VERTICES];


void addEdge(int u, int v) {
    
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;

   
    newNode = (struct node*) malloc(sizeof(struct node));
    newNode->vertex = u;
    newNode->next = adjList[v];
    adjList[v] = newNode;
}


void displayAdjList(int n) {
    printf("Adjacency List:\n");
    for (int i = 0; i < n; i++) {
        struct node* temp = adjList[i];
        printf("Vertex %d: ", i+1);
        while (temp != NULL) {
            printf("%d -> ", temp->vertex + 1);
            temp = temp->next;
        }
        printf("NULL\n");
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
        adjList[i] = NULL;
    }

    
    printf("Enter the connected pair of vertices (v1 v2):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u-1, v-1); 
    }

   
    displayAdjList(n);

    return 0;
}
