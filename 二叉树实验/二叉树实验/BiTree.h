#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

// 二叉树结点定义

typedef struct BiNode {
    BiNode()
    {};
    char data;  // 结点数据
    BiNode* lChild;  // 左子树结点指针
    BiNode* rChild;  // 右子树结点指针
    BiNode(int d) {
        data = d;
        lChild = NULL;
        rChild = NULL;
    }
} BiNode, * BiTree;