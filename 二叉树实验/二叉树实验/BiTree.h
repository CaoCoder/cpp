#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

// ��������㶨��

typedef struct BiNode {
    BiNode()
    {};
    char data;  // �������
    BiNode* lChild;  // ���������ָ��
    BiNode* rChild;  // ���������ָ��
    BiNode(int d) {
        data = d;
        lChild = NULL;
        rChild = NULL;
    }
} BiNode, * BiTree;