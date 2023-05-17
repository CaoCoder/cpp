#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct node {
    char name[50];
    int parent;
    int children[3];
} Node;

void print(Node* nodes, int index, int level);
void print_padding(int level);
void print_vertical_line(int level);

int main() {
    Node nodes[MAX_NODES] = {
        {"�л���ѧ", -1, {1, 2, -1}},
        {"�����ѧԺ", 0, {3, 4, 5}},
        {"����ѧԺ", 0, {6, 7, -1}},
        {"�������ѧ", 1, {8, 9, 10}},
        {"��Ϣ��ȫ", 1, {11, 12, -1}},
        {"������", 1, {13, -1, -1}},
        {"�ƿ�1��", 3, {14, -1, -1}},
        {"�ƿ�2��", 3, {15, -1, -1}},
        {"�ƿ�3��", 3, {16, -1, -1}},
        {"�Ű�1��", 4, {17, -1, -1}},
        {"�Ű�2��", 4, {18, -1, -1}},
        {"������", 5, {19, -1, -1}},
        {"������Ϣ��", 2, {20, 21, 22}},
        {"��Ϣ����", 2, {23, 24, -1}},
        {"����1��", 6, {25, -1, -1}},
        {"����2��", 6, {26, -1, -1}},
        {"����3��", 6, {27, -1, -1}},
        {"��Ϣ1��", 7, {28, -1, -1}},
        {"��Ϣ2��", 7, {29, -1, -1}},
        {"32", 8, {-1, -1, -1}},
        {"35", 9, {-1, -1, -1}},
        {"33", 10, {-1, -1, -1}},
        {"36", 11, {-1, -1, -1}},
        {"38", 12, {-1, -1, -1}},
        {"38", 13, {-1, -1, -1}},
        {"40", 20, {-1, -1, -1}},
        {"38", 21, {-1, -1, -1}},
        {"42", 22, {-1, -1, -1}},
        {"38", 23, {-1, -1, -1}},
        {"35", 24, {-1, -1, -1}},
    };
    print(nodes, 0, 0); // ���ڵ������Ϊ 0����ʼ�����㼶Ϊ 0

    return 0;

}

void print_padding(int level) {
    for (int i = 0; i < level; i++) {
        printf(" "); // ÿһ�����������ո�
    }
}

void print_vertical_line(int level) {
    for (int i = 0; i < level; i++) {
        if (i == level - 1) {
            printf("|--");
        }
        else {
            printf(" "); // ÿһ�����������ո�
        }
    }
}

void print(Node* nodes, int index, int level) {
    print_padding(level);
    printf("%s\n", nodes[index].name); for (int i = 0; i < 3 && nodes[index].children[i] != -1; i++) {
        print_vertical_line(level);
        print(nodes, nodes[index].children[i], level + 1);
    }
}