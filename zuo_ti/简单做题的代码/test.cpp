#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 定义图中顶点数量
#define VERTICES 5

// 定义地点信息结构体
typedef struct {
    int id;
    char name[20];
} Location;

// 函数声明
void printCampusMap();
void findShortestPath(int source, int destination, int graph[VERTICES][VERTICES]);
int minDistance(int dist[], int sptSet[]);

// 地点信息数组
Location locations[VERTICES] = {
    {0, "图书馆"},
    {1, "教学楼"},
    {2, "食堂"},
    {3, "宿舍"},
    {4, "体育馆"}
};

// 邻接矩阵表示图
int graph[VERTICES][VERTICES] = {
    {0, 10, 20, 0, 0},
    {10, 0, 0, 50, 10},
    {20, 0, 0, 20, 0},
    {0, 50, 20, 0, 0},
    {0, 10, 0, 0, 0}
};

int main() {
    int choice;
    int source, destination;

    while (1) {
        printf("\n校园导航图系统\n");
        printf("1. 查看学校平面图\n");
        printf("2. 查看地点信息\n");
        printf("3. 查找两点间最短路径\n");
        printf("4. 退出程序\n");
        printf("请选择操作（1-4）: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printCampusMap();
            break;
        case 2:
            printf("地点列表：\n");
            for (int i = 0; i < VERTICES; i++) {
                printf("%d: %s\n", locations[i].id, locations[i].name);
            }
            break;
        case 3:
            printf("请输入出发地点ID: ");
            scanf("%d", &source);
            printf("请输入目的地ID: ");
            scanf("%d", &destination);
            findShortestPath(source, destination, graph);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("输入错误，请重新输入。\n");
            break;
        }
    }
    return 0;
}

void printCampusMap() {
    printf("学校平面图（数字表示地点ID）：\n\n");
    printf("  0---1---4\n");
    printf("  |       |\n");
    printf("  2-------3\n\n");
}

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
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < VERTICES; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}