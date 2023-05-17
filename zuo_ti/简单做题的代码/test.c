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
        {"中华大学", -1, {1, 2, -1}},
        {"计算机学院", 0, {3, 4, 5}},
        {"电信学院", 0, {6, 7, -1}},
        {"计算机科学", 1, {8, 9, 10}},
        {"信息安全", 1, {11, 12, -1}},
        {"物联网", 1, {13, -1, -1}},
        {"计科1班", 3, {14, -1, -1}},
        {"计科2班", 3, {15, -1, -1}},
        {"计科3班", 3, {16, -1, -1}},
        {"信安1班", 4, {17, -1, -1}},
        {"信安2班", 4, {18, -1, -1}},
        {"物联班", 5, {19, -1, -1}},
        {"电子信息类", 2, {20, 21, 22}},
        {"信息工程", 2, {23, 24, -1}},
        {"电信1班", 6, {25, -1, -1}},
        {"电信2班", 6, {26, -1, -1}},
        {"电信3班", 6, {27, -1, -1}},
        {"信息1班", 7, {28, -1, -1}},
        {"信息2班", 7, {29, -1, -1}},
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
    print(nodes, 0, 0); // 根节点的索引为 0，初始缩进层级为 0

    return 0;

}

void print_padding(int level) {
    for (int i = 0; i < level; i++) {
        printf(" "); // 每一级缩进两个空格
    }
}

void print_vertical_line(int level) {
    for (int i = 0; i < level; i++) {
        if (i == level - 1) {
            printf("|--");
        }
        else {
            printf(" "); // 每一级缩进三个空格
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