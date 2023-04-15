#pragma once
#include "location.h"

int minDistance(int dist[], int sptSet[]);

// �ص���Ϣ����
struct Location locations[VERTICES] = {
    {0, "ͼ���"},
    {1, "��ѧ¥"},
    {2, "ʳ��"},
    {3, "����"},
    {4, "������"}
};

// �ڽӾ����ʾͼ
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