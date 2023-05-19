#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 20

struct Edge {
    int source, destination, weight;
};

struct Graph {
    int numVertices, numEdges;
    struct Edge edges[MAX_EDGES];
};

struct Subset {
    int parent;
    int rank;
};

struct Graph* createGraph(int numVertices, int numEdges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    return graph;
}

int find(struct Subset subsets[], int vertex) {
    if (subsets[vertex].parent != vertex)
        subsets[vertex].parent = find(subsets, subsets[vertex].parent);
    return subsets[vertex].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int xRoot = find(subsets, x);
    int yRoot = find(subsets, y);

    if (xRoot != yRoot) {
        if (subsets[xRoot].rank < subsets[yRoot].rank)
            subsets[xRoot].parent = yRoot;
        else if (subsets[xRoot].rank > subsets[yRoot].rank)
            subsets[yRoot].parent = xRoot;
        else {
            subsets[yRoot].parent = xRoot;
            subsets[xRoot].rank++;
        }
    }
}

int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

void kruskalMST(struct Graph* graph) {
    int numVertices = graph->numVertices;
    struct Edge result[numVertices];
    int i, j = 0;

    qsort(graph->edges, graph->numEdges, sizeof(graph->edges[0]), compareEdges);

    struct Subset* subsets = (struct Subset*)malloc(numVertices * sizeof(struct Subset));
    for (i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < graph->numEdges && j < numVertices - 1; i++) {
        struct Edge nextEdge = graph->edges[i];

        int x = find(subsets, nextEdge.source);
        int y = find(subsets, nextEdge.destination);

        if (x != y) {
            result[j++] = nextEdge;
            unionSets(subsets, x, y);
            printf("%d -- %d \tWeight: %d\n", nextEdge.source, nextEdge.destination, nextEdge.weight);
        }
    }

    free(subsets);
}

int main() {
    int numVertices, numEdges, i;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    struct Graph* graph = createGraph(numVertices, numEdges);

    printf("Enter the details of each edge (source, destination, weight):\n");
    for (i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &graph->edges[i].source, &graph->edges[i].destination, &graph->edges[i].weight);
    }

    kruskalMST(graph);

    return 0;
}
