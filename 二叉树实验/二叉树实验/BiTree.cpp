#define _CRT_SECURE_NO_WARNINGS 1

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

// ���ļ��ж�ȡ���ݵ�����
bool ReadFileToArray(char fileName[], char strLine[100][3], int& nArrLen) {
    FILE* pFile;  // �����ļ�ָ��
    char str[1000];  // ��Ŷ���һ���ı����ַ���
    pFile = fopen(fileName, "r");
    if (!pFile) {
        cout << "�����������ļ���ʧ�ܣ�" << endl;
        return false;
    }
    // ��ȡ��һ�У��ж϶�������ʶBinaryTree�Ƿ���ȷ
    if (fgets(str, 1000, pFile) != NULL) {
        if (strcmp(str, "BinaryTree\n") != 0) {
            cout << "�򿪵��ļ���ʽ����" << endl;
            fclose(pFile);
            return false;
        }
    }
    nArrLen = 0;
    while (fscanf(pFile, "%c %c %c\n", &strLine[nArrLen][0], &strLine[nArrLen][1], &strLine[nArrLen][2]) != EOF) {
        // ѭ����ȡ��������ݣ��������飬���������1
        nArrLen++;
    }
    fclose(pFile);
    return true;
}

// ���������ݰ�������򴴽�������
bool CreateBiTreeFromFile(BiTree& pBT, char strLine[100][3], int nLen, int& nRow) {
    if ((nRow >= nLen) || (nLen == 0))
        return false;  // �����Ѿ�������ϣ�����û�����ݣ��˳�
    // �����������ݵݹ鴴��������
    pBT = new BiNode;  // ���������
    pBT->data = strLine[nRow][0];
    pBT->lChild = NULL;
    pBT->rChild = NULL;
    int nRowNext = nRow;  // �������εݹ���к�
    if (strLine[nRowNext][1] == '1') {
        // ��ǰ�����������������һ�����ݣ��ݹ���ô�����������
        nRow++;  // �кż�1
        CreateBiTreeFromFile(pBT->lChild, strLine, nLen, nRow);
    }
    if (strLine[nRowNext][2] == '1') {
        // ��ǰ�����������������һ���������ݹ���ô�����������
        nRow++;  // �кż�1
        CreateBiTreeFromFile(pBT->rChild, strLine, nLen, nRow);
    }
    return true;
}

// ���ٶ�����
void DestroyBiTree(BiTree pBT) {
    if (pBT) {
        DestroyBiTree(pBT->lChild);  // �ݹ�����������
        DestroyBiTree(pBT->rChild);  // �ݹ�����������
        delete pBT;  // �ͷŵ�ǰ�����
    }
}

// �������������
void PreOrderTraverse(BiTree pBT) {
    if (pBT) {
        cout << pBT->data << " ";  // �����ǰ�������
        PreOrderTraverse(pBT->lChild);  // �ݹ����������
        PreOrderTraverse(pBT->rChild);  // �ݹ����������
    }
}


void InOrderTraverse(BiTree pBT, int level) {
    if (pBT) {
        InOrderTraverse(pBT->lChild, level + 1);  // �ݹ����������
        cout << "���ֵ��" << pBT->data << "���������" << level << endl;  // ������ֵ�Ͳ����
        InOrderTraverse(pBT->rChild, level + 1);  // �ݹ����������
    }
}

void CountLeafAndOneDegree(BiTree pBT, int& nLeafNum, int& nOneDegreeNum) {
    if (pBT) {
        if (pBT->lChild == NULL && pBT->rChild == NULL) {
            nLeafNum++;  // Ҷ�ӽ�������1
        }
        else if (pBT->lChild == NULL || pBT->rChild == NULL) {
            nOneDegreeNum++;  // 1�Ƚ�������1
        }
        CountLeafAndOneDegree(pBT->lChild, nLeafNum, nOneDegreeNum);  // �ݹ����������
        CountLeafAndOneDegree(pBT->rChild, nLeafNum, nOneDegreeNum);  // �ݹ����������
    }
}

void FindNodeInfo(BiTree pBT, char x) {
    if (pBT) {
        if (pBT->lChild && pBT->lChild->data == x) {
            cout << "���ڵ㣺" << pBT->data << endl;
            if (pBT->rChild) {
                cout << "���ֵܣ�" << pBT->rChild->data << endl;
            }
            else {
                cout << "�����ֵ�" << endl;
            }
            if (pBT->lChild->lChild) {
                cout << "���ӣ�" << pBT->lChild->lChild->data << endl;
            }
            else {
                cout << "������" << endl;
            }
            if (pBT->lChild->rChild) {
                cout << "�Һ��ӣ�" << pBT->lChild->rChild->data << endl;
            }
            else {
                cout << "���Һ���" << endl;
            }
        }
        else if (pBT->rChild && pBT->rChild->data == x) {
            cout << "���ڵ㣺" << pBT->data << endl;
            if (pBT->lChild) {
                cout << "���ֵܣ�" << pBT->lChild->data << endl;
            }
            else {
                cout << "�����ֵ�" << endl;
            }
            if (pBT->rChild->lChild) {
                cout << "���ӣ�" << pBT->rChild->lChild->data << endl;
            }
            else {
                cout << "������" << endl;
            }
            if (pBT->rChild->rChild) {
                cout << "�Һ��ӣ�" << pBT->rChild->rChild->data << endl;
            }
            else {
                cout << "���Һ���" << endl;
            }
        }
        else {
            FindNodeInfo(pBT->lChild, x);  // �ݹ����������
            FindNodeInfo(pBT->rChild, x);  // �ݹ����������
        }
    }
}


int GetNodeLevel(BiTree pBT, char x, int level) {
    if (pBT) {
        if (pBT->data == x) {
            return level;
        }
        else {
            int nLevel = GetNodeLevel(pBT->lChild, x, level + 1);  // �ݹ����������
            if (nLevel == -1) {
                nLevel = GetNodeLevel(pBT->rChild, x, level + 1);  // �ݹ����������
            }
            return nLevel;
        }
    }
    return -1;  // �Ҳ���Ŀ���㣬����-1
}

void charArrayToIntArray(char* arr, int* intArr, int nLen) {
    for (int i = 0; i < nLen; i++) {
        intArr[i] = arr[i] - '0';
    }
}
void ArrayToTree(BiTree& pBT, char* arr, int nLen) {
    int nDepth = log2(nLen) + 1;  // ������������
    pBT = new BiNode(arr[0]);  // ���������
    queue<BiNode*> qParent;  // ��������ĸ�������
    qParent.push(pBT);
    int nIndex = 1;  // �����±�
    for (int i = 2; i <= nDepth; i++) {  // ���ι���ÿһ��Ľ��
        int nLevelNodeNum = pow(2, i - 1);  // ����ò�����
        for (int j = 0; j < nLevelNodeNum; j++) {  // ���β���ò���
            BiNode* pParent = qParent.front();  // ȡ�������
            qParent.pop();
            int nLeftIndex = 2 * j;  // �������ӽ���±�
            int nRightIndex = 2 * j + 1;  // �������ӽ���±�
            if (nLeftIndex < nLevelNodeNum && nIndex < nLen) {  // �������ӽ��
                pParent->lChild = new BiNode(arr[nIndex]);
                qParent.push(pParent->lChild);
                nIndex++;
            }
            if (nRightIndex < nLevelNodeNum && nIndex < nLen) {  // �������ӽ��
                pParent->rChild = new BiNode(arr[nIndex]);
                qParent.push(pParent->rChild);
                nIndex++;
            }
            if (nIndex >= nLen) {  // �����е�Ԫ���Ѿ��������
                return;
            }
        }
    }
}
#include <stack>
void PrintPathFromLeafToRoot(BiTree pBT, stack<char>& s) {
    if (pBT) {
        s.push(pBT->data);  // ����ǰ�����ջ
        if (pBT->lChild == NULL && pBT->rChild == NULL) {  // ������Ҷ�ӽ��
            stack<char> sTemp = s;
            while (!sTemp.empty()) {  // ���·��
                cout << sTemp.top() << " ";
                sTemp.pop();
            }
            cout << endl;
        }
        else {
            PrintPathFromLeafToRoot(pBT->lChild, s);  // �ݹ����������
            PrintPathFromLeafToRoot(pBT->rChild, s);  // �ݹ����������
        }
        s.pop();  // ����ǰ����ջ
    }
}

void PrintByLevel(BiTree pBT) {
    if (pBT == NULL) {
        return;
    }
    queue<BiNode*> q;
    q.push(pBT);
    while (!q.empty()) {
        int nLevelNodeNum = q.size();  // ��ǰ������
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
        cout << "������Ҫִ�еĲ�����\n";
        cout << "1. ���ļ�����������\n";
        cout << "2. ���ٶ�����\n";
        cout << "3. �������������\n";
        cout << "4. �˳�����\n";
        cout << "5. �������������������и�����ֵ��������Ӧ�Ĳ����\n";
        cout << "6. ���������Ҷ�ӽ������1�Ƚ����\n";
        cout << "7. ���丸�ڵ㡢�ֵܽ�㡢�ӽ���ֵ\n";
        cout << "8. ��������һ��Ԫ��x�����������еĲ��\n";
        cout << "9. ����˳��ʽ�洢�������еĶ�����ת��Ϊ����������ʽ \n";
        cout << "10.�����������ÿ��Ҷ�ӽ�㵽������·��\n";
        cout << "11.��α������ӡ\n";
        
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "����������������ļ�����\n";
            cin >> fileName;
            if (ReadFileToArray(fileName, strLine, nArrLen)) {
                nRow = 0;
                if (CreateBiTreeFromFile(pBT, strLine, nArrLen, nRow)) {
                    cout << "�����������ɹ���" << endl;
                }
                else {
                    cout << "����������ʧ�ܣ�" << endl;
                }
            }
            break;
        case 2:
            DestroyBiTree(pBT);
            pBT = NULL;
            cout << "�����������٣�" << endl;
            break;
        case 3:
            cout << "����������Ϊ��";
            PreOrderTraverse(pBT);
            cout << endl;
            break;
        case 4:
            if (pBT) {
                DestroyBiTree(pBT);
            }
            cout << "�������˳���" << endl;
            return 0;
        case 5:
            InOrderTraverse(pBT, 1);
            break;
        case 6:
        { int nLeafNum = 0;  // ��ʼ��Ҷ�ӽ�������
        int nOneDegreeNum = 0;  // ��ʼ��1�Ƚ�������
        CountLeafAndOneDegree(pBT, nLeafNum, nOneDegreeNum);  // ͳ��Ҷ�ӽ����Ŀ��1�Ƚ����Ŀ
        cout << "Ҷ�ӽ����ĿΪ��" << nLeafNum << endl;
        cout << "����Ϊ1�Ľ����ĿΪ��" << nOneDegreeNum << endl;
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
            cout << "δ�ҵ�Ŀ��ڵ�" << endl;
        }
        else {
            cout << "Ŀ��ڵ�Ĳ���Ϊ��" << level << endl;
        }
         }break;
        case 9:
        {    char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
        int len = sizeof(arr) / sizeof(arr[0]);
        BiTree root = nullptr;
        ArrayToTree(pBT, arr, len);
        cout << "ת���ɹ�" << endl;
        // ��ʱrootָ����õĶ������ĸ��ڵ�
        }
        break;
        case 10:  
        { BiTree root = nullptr;
        stack<char> s;
        PrintPathFromLeafToRoot(pBT, s);
         }break;
        case 11:
        { // ������һ�ö����������ڵ�Ϊroot
            BiTree root = NULL;
            PrintByLevel(pBT);
         
             }break;
        default:
            cout << "��������ȷ�Ĳ�����ţ�" << endl;
            break;
        }
    }
}