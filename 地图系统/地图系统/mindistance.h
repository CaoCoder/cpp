#pragma once
#include "location.h"

int minDistance(int dist[], int sptSet[]);

// 地点信息数组
struct Location locations[VERTICES] = {
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