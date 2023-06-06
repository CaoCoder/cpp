#define _CRT_SECURE_NO_WARNINGS 1

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

// 从文件中读取数据到数组
bool ReadFileToArray(char fileName[], char strLine[100][3], int& nArrLen) {
    FILE* pFile;  // 定义文件指针
    char str[1000];  // 存放读出一行文本的字符串
    pFile = fopen(fileName, "r");
    if (!pFile) {
        cout << "二叉树数据文件打开失败！" << endl;
        return false;
    }
    // 读取第一行，判断二叉树标识BinaryTree是否正确
    if (fgets(str, 1000, pFile) != NULL) {
        if (strcmp(str, "BinaryTree\n") != 0) {
            cout << "打开的文件格式错误！" << endl;
            fclose(pFile);
            return false;
        }
    }
    nArrLen = 0;
    while (fscanf(pFile, "%c %c %c\n", &strLine[nArrLen][0], &strLine[nArrLen][1], &strLine[nArrLen][2]) != EOF) {
        // 循环读取结点行数据，存入数组，结点总数加1
        nArrLen++;
    }
    fclose(pFile);
    return true;
}

// 从数组数据按先序次序创建二叉树
bool CreateBiTreeFromFile(BiTree& pBT, char strLine[100][3], int nLen, int& nRow) {
    if ((nRow >= nLen) || (nLen == 0))
        return false;  // 数据已经处理完毕，或者没有数据，退出
    // 根据数组数据递归创建二叉树
    pBT = new BiNode;  // 建立根结点
    pBT->data = strLine[nRow][0];
    pBT->lChild = NULL;
    pBT->rChild = NULL;
    int nRowNext = nRow;  // 保留本次递归的行号
    if (strLine[nRowNext][1] == '1') {
        // 当前结点有左子树，读下一行数据，递归调用创建左子树。
        nRow++;  // 行号加1
        CreateBiTreeFromFile(pBT->lChild, strLine, nLen, nRow);
    }
    if (strLine[nRowNext][2] == '1') {
        // 当前结点有右子树，读下一行数数，递归调用创建右子树。
        nRow++;  // 行号加1
        CreateBiTreeFromFile(pBT->rChild, strLine, nLen, nRow);
    }
    return true;
}

// 销毁二叉树
void DestroyBiTree(BiTree pBT) {
    if (pBT) {
        DestroyBiTree(pBT->lChild);  // 递归销毁左子树
        DestroyBiTree(pBT->rChild);  // 递归销毁右子树
        delete pBT;  // 释放当前根结点
    }
}

// 先序遍历二叉树
void PreOrderTraverse(BiTree pBT) {
    if (pBT) {
        cout << pBT->data << " ";  // 输出当前结点数据
        PreOrderTraverse(pBT->lChild);  // 递归遍历左子树
        PreOrderTraverse(pBT->rChild);  // 递归遍历右子树
    }
}


void InOrderTraverse(BiTree pBT, int level) {
    if (pBT) {
        InOrderTraverse(pBT->lChild, level + 1);  // 递归遍历左子树
        cout << "结点值：" << pBT->data << "，层次数：" << level << endl;  // 输出结点值和层次数
        InOrderTraverse(pBT->rChild, level + 1);  // 递归遍历右子树
    }
}

void CountLeafAndOneDegree(BiTree pBT, int& nLeafNum, int& nOneDegreeNum) {
    if (pBT) {
        if (pBT->lChild == NULL && pBT->rChild == NULL) {
            nLeafNum++;  // 叶子结点计数加1
        }
        else if (pBT->lChild == NULL || pBT->rChild == NULL) {
            nOneDegreeNum++;  // 1度结点计数加1
        }
        CountLeafAndOneDegree(pBT->lChild, nLeafNum, nOneDegreeNum);  // 递归遍历左子树
        CountLeafAndOneDegree(pBT->rChild, nLeafNum, nOneDegreeNum);  // 递归遍历右子树
    }
}

void FindNodeInfo(BiTree pBT, char x) {
    if (pBT) {
        if (pBT->lChild && pBT->lChild->data == x) {
            cout << "父节点：" << pBT->data << endl;
            if (pBT->rChild) {
                cout << "右兄弟：" << pBT->rChild->data << endl;
            }
            else {
                cout << "无右兄弟" << endl;
            }
            if (pBT->lChild->lChild) {
                cout << "左孩子：" << pBT->lChild->lChild->data << endl;
            }
            else {
                cout << "无左孩子" << endl;
            }
            if (pBT->lChild->rChild) {
                cout << "右孩子：" << pBT->lChild->rChild->data << endl;
            }
            else {
                cout << "无右孩子" << endl;
            }
        }
        else if (pBT->rChild && pBT->rChild->data == x) {
            cout << "父节点：" << pBT->data << endl;
            if (pBT->lChild) {
                cout << "左兄弟：" << pBT->lChild->data << endl;
            }
            else {
                cout << "无左兄弟" << endl;
            }
            if (pBT->rChild->lChild) {
                cout << "左孩子：" << pBT->rChild->lChild->data << endl;
            }
            else {
                cout << "无左孩子" << endl;
            }
            if (pBT->rChild->rChild) {
                cout << "右孩子：" << pBT->rChild->rChild->data << endl;
            }
            else {
                cout << "无右孩子" << endl;
            }
        }
        else {
            FindNodeInfo(pBT->lChild, x);  // 递归遍历左子树
            FindNodeInfo(pBT->rChild, x);  // 递归遍历右子树
        }
    }
}


int GetNodeLevel(BiTree pBT, char x, int level) {
    if (pBT) {
        if (pBT->data == x) {
            return level;
        }
        else {
            int nLevel = GetNodeLevel(pBT->lChild, x, level + 1);  // 递归遍历左子树
            if (nLevel == -1) {
                nLevel = GetNodeLevel(pBT->rChild, x, level + 1);  // 递归遍历右子树
            }
            return nLevel;
        }
    }
    return -1;  // 找不到目标结点，返回-1
}

void charArrayToIntArray(char* arr, int* intArr, int nLen) {
    for (int i = 0; i < nLen; i++) {
        intArr[i] = arr[i] - '0';
    }
}
void ArrayToTree(BiTree& pBT, char* arr, int nLen) {
    int nDepth = log2(nLen) + 1;  // 计算二叉树深度
    pBT = new BiNode(arr[0]);  // 创建根结点
    queue<BiNode*> qParent;  // 待插入结点的父结点队列
    qParent.push(pBT);
    int nIndex = 1;  // 数组下标
    for (int i = 2; i <= nDepth; i++) {  // 依次构造每一层的结点
        int nLevelNodeNum = pow(2, i - 1);  // 计算该层结点数
        for (int j = 0; j < nLevelNodeNum; j++) {  // 依次插入该层结点
            BiNode* pParent = qParent.front();  // 取出父结点
            qParent.pop();
            int nLeftIndex = 2 * j;  // 计算左子结点下标
            int nRightIndex = 2 * j + 1;  // 计算右子结点下标
            if (nLeftIndex < nLevelNodeNum && nIndex < nLen) {  // 插入左子结点
                pParent->lChild = new BiNode(arr[nIndex]);
                qParent.push(pParent->lChild);
                nIndex++;
            }
            if (nRightIndex < nLevelNodeNum && nIndex < nLen) {  // 插入右子结点
                pParent->rChild = new BiNode(arr[nIndex]);
                qParent.push(pParent->rChild);
                nIndex++;
            }
            if (nIndex >= nLen) {  // 数组中的元素已经插入完毕
                return;
            }
        }
    }
}
#include <stack>
void PrintPathFromLeafToRoot(BiTree pBT, stack<char>& s) {
    if (pBT) {
        s.push(pBT->data);  // 将当前结点入栈
        if (pBT->lChild == NULL && pBT->rChild == NULL) {  // 遍历到叶子结点
            stack<char> sTemp = s;
            while (!sTemp.empty()) {  // 输出路径
                cout << sTemp.top() << " ";
                sTemp.pop();
            }
            cout << endl;
        }
        else {
            PrintPathFromLeafToRoot(pBT->lChild, s);  // 递归遍历左子树
            PrintPathFromLeafToRoot(pBT->rChild, s);  // 递归遍历右子树
        }
        s.pop();  // 将当前结点出栈
    }
}

void PrintByLevel(BiTree pBT) {
    if (pBT == NULL) {
        return;
    }
    queue<BiNode*> q;
    q.push(pBT);
    while (!q.empty()) {
        int nLevelNodeNum = q.size();  // 当前层结点数
        for (int i = 0; i < nLevelNodeNum; i++) {
            BiNode* pNode = q.front();
            q.pop();
            cout << pNode->data << " ";
            if (pNode->lChild) {
                q.push(pNode->lChild);
            }
            if (pNode->rChild) {
                q.push(pNode->rChild);
            }
        }
        cout << endl;
    }
}
int main() {
    BiTree pBT = NULL;
    char fileName[100];
    char strLine[100][3];
    int nArrLen = 0;
    int nRow = 0;
    int choice;
    while (true) {
        cout << "请输入要执行的操作：\n";
        cout << "1. 从文件创建二叉树\n";
        cout << "2. 销毁二叉树\n";
        cout << "3. 先序遍历二叉树\n";
        cout << "4. 退出程序\n";
        cout << "5. 按中序次序输出二叉树中各结点的值及其所对应的层次数\n";
        cout << "6. 求二叉树的叶子结点数和1度结点数\n";
        cout << "7. 求其父节点、兄弟结点、子结点的值\n";
        cout << "8. 键盘输入一个元素x，求其在树中的层次\n";
        cout << "9. 将按顺序方式存储在数组中的二叉树转换为二叉链表形式 \n";
        cout << "10.输出二叉树从每个叶子结点到根结点的路径\n";
        cout << "11.层次遍历序打印\n";
        
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "请输入二叉树数据文件名：\n";
            cin >> fileName;
            if (ReadFileToArray(fileName, strLine, nArrLen)) {
                nRow = 0;
                if (CreateBiTreeFromFile(pBT, strLine, nArrLen, nRow)) {
                    cout << "二叉树创建成功！" << endl;
                }
                else {
                    cout << "二叉树创建失败！" << endl;
                }
            }
            break;
        case 2:
            DestroyBiTree(pBT);
            pBT = NULL;
            cout << "二叉树已销毁！" << endl;
            break;
        case 3:
            cout << "先序遍历结果为：";
            PreOrderTraverse(pBT);
            cout << endl;
            break;
        case 4:
            if (pBT) {
                DestroyBiTree(pBT);
            }
            cout << "程序已退出！" << endl;
            return 0;
        case 5:
            InOrderTraverse(pBT, 1);
            break;
        case 6:
        { int nLeafNum = 0;  // 初始化叶子结点计数器
        int nOneDegreeNum = 0;  // 初始化1度结点计数器
        CountLeafAndOneDegree(pBT, nLeafNum, nOneDegreeNum);  // 统计叶子结点数目和1度结点数目
        cout << "叶子结点数目为：" << nLeafNum << endl;
        cout << "度数为1的结点数目为：" << nOneDegreeNum << endl;
        }break;
        case 7:
        { BiTree root = nullptr;
        char target = 'D';
        FindNodeInfo(pBT, target);
         }break;
        case 8:
        { BiTree root = nullptr;
        char target1 = 'D';
        int startLevel = 1;
        int level = GetNodeLevel(pBT, target1, startLevel);
        if (level == -1) {
            cout << "未找到目标节点" << endl;
        }
        else {
            cout << "目标节点的层数为：" << level << endl;
        }
         }break;
        case 9:
        {    char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
        int len = sizeof(arr) / sizeof(arr[0]);
        BiTree root = nullptr;
        ArrayToTree(pBT, arr, len);
        cout << "转换成功" << endl;
        // 此时root指向构造好的二叉树的根节点
        }
        break;
        case 10:  
        { BiTree root = nullptr;
        stack<char> s;
        PrintPathFromLeafToRoot(pBT, s);
         }break;
        case 11:
        { // 假设有一棵二叉树，根节点为root
            BiTree root = NULL;
            PrintByLevel(pBT);
         
             }break;
        default:
            cout << "请输入正确的操作序号！" << endl;
            break;
        }
    }
}