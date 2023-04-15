#include "mindistance.h"
#include "location.h"
void findShortestPath(int source, int destination, int graph[VERTICES][VERTICES]);
void findShortestPath(int source, int destination, int graph[VERTICES][VERTICES]) {
    int dist[VERTICES];
    int sptSet[VERTICES];
    int parent[VERTICES];

    for (int i = 0; i < VERTICES; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < VERTICES - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < VERTICES; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("最短路径为：\n");
    int path[VERTICES];
    int path_index = 0;

    for (int i = destination; i != -1; i = parent[i]) {
        path[path_index++] = i;
    }

    for (int i = path_index - 1; i > 0; i--) {
        printf("%s -> ", locations[path[i]].name);
    }
    printf("%s\n", locations[path[0]].name);

    int distance = dist[destination];
    printf("总距离: %d\n", distance);
}
