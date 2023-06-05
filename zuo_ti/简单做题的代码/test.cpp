#include <iostream>
#include <queue>
using namespace std;

// 二叉树的二叉链表存储结构
struct BinaryTreeNode {
    int val; // 结点的值
    int level; // 结点的层次
    BinaryTreeNode* left; // 左子结点
    BinaryTreeNode* right; // 右子结点
    BinaryTreeNode(int val, int level) : val(val), level(level), left(nullptr), right(nullptr) {}
};

// 按中序次序输出二叉树中各结点的值及其所对应的层次数
void inOrderTraversal(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << "节点值: " << root->val << ", 层次数: " << root->level << endl;
    inOrderTraversal(root->right);
}

// 求二叉树的叶子结点数和1度结点数
void countLeafAndOneDegreeNodes(BinaryTreeNode* root, int& leafCount, int& oneDegreeCount) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        leafCount++;
    }
    else if (root->left == nullptr || root->right == nullptr) {
        oneDegreeCount++;
    }
    countLeafAndOneDegreeNodes(root->left, leafCount, oneDegreeCount);
    countLeafAndOneDegreeNodes(root->right, leafCount, oneDegreeCount);
}

// 查找给定节点的父节点、兄弟节点和子节点
void findNodeRelations(BinaryTreeNode* root, int x) {
    if (root == nullptr) {
        cout << "错误: 二叉树为空！" << endl;
        return;
    }
    if (root->val == x) {
        cout << "该节点为根节点！" << endl;
        return;
    }
    queue<BinaryTreeNode*> q;
    q.push(root);
    bool isFound = false;
    while (!q.empty()) {
        BinaryTreeNode* cur = q.front();
        q.pop();
        if (cur->left != nullptr) {
            if (cur->left->val == x) {
                isFound = true;
                cout << "父节点的值为: " << cur->val << endl;
                if (cur->right != nullptr) {
                    cout << "兄弟节点的值为: " << cur->right->val << endl;
                }
                else {
                    cout << "该节点没有兄弟节点！" << endl;
                }
                cout << "左子节点的值为: " << cur->left->val << endl;
                if (cur->left->left != nullptr) {
                    cout << "左子节点有左兄弟: " << cur->left->left->val << endl;
                }
                else {
                    cout << "左子节点没有左兄弟！" << endl;
                }
                if (cur->left->right != nullptr) {
                    cout << "左子节点有右兄弟: " << cur->left->right->val << endl;
                }
                else {
                    cout << "左子节点没有右兄弟！" << endl;
                }
                break;
            }
            else {
                q.push(cur->left);
            }
        }
        if (cur->right != nullptr) {
            if (cur->right->val == x) {
                isFound = true;
                cout << "父节点的值为: " << cur->val << endl;
                if (cur->left != nullptr) {
                    cout << "兄弟节点的值为: " << cur->left->val << endl;
                }
                else {
                    cout << "该节点没有兄弟节点！" << endl;
                }
                cout << "右子节点的值为: " << cur->right->val << endl;
                if (cur->right->left != nullptr) {
                    cout << "右子节点有左兄弟: " << cur->right->left->val << endl;
                }
                else {
                    cout << "右子节点没有左兄弟！" << endl;
                }
                if (cur->right->right != nullptr) {
                    cout << "右子节点有右兄弟: " << cur->right->right->val << endl;
                }
                else {
                    cout << "右子节点没有右兄弟！";
                }
                break;
            }
            else {
                q.push(cur->right);
            }
        }
    }
    if (!isFound) {
        cout << "错误: 未找到该节点！" << endl;
    }
}

// 查找给定节点在树中的层次
int findNodeLevel(BinaryTreeNode* root, int x) {
    if (root == nullptr) {
        cout << "错误: 二叉树为空！" << endl;
        return -1;
    }
    if (root->val == x) {
        return root->level;
    }
    queue<BinaryTreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode* cur = q.front();
        q.pop();
        if (cur->left != nullptr) {
            if (cur->left->val == x) {
                return cur->left->level;
            }
            else {
                q.push(cur->left);
            }
        }
        if (cur->right != nullptr) {
            if (cur->right->val == x) {
                return cur->right->level;
            }
            else {
                q.push(cur->right);
            }
        }
    }
    cout << "错误: 未找到该节点！" << endl;
    return -1;
}

// 将按顺序方式存储在数组中的二叉树转换为二叉链表形式
BinaryTreeNode* arrayToBinaryTree(int* arr, int n) {
    if (n == 0) {
        return nullptr;
    }
    BinaryTreeNode* root = new BinaryTreeNode(arr[0], 1);
    queue<BinaryTreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n) {
        BinaryTreeNode* cur = q.front();
        q.pop();
        if (i < n && arr[i] != -1) {
            cur->left = new BinaryTreeNode(arr[i], cur->level + 1);
            q.push(cur->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            cur->right = new BinaryTreeNode(arr[i], cur->level + 1);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

// 输出二叉树从每个叶子结点到根结点的路径（经历的结点）
void printPathsFromLeavesToRoot(BinaryTreeNode* root, vector<int>& path) {
    if (root == nullptr) {
        return;
    }
    // 将当前节点加入路径
    path.push_back(root->val);
    // 如果是叶子节点，输出路径
    if (root->left == nullptr && root->right == nullptr) {
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    // 递归访问左右子树
    printPathsFromLeavesToRoot(root->left, path);
    printPathsFromLeavesToRoot(root->right, path);
    // 回溯，从路径中删除当前节点
    path.pop_back();
}

// 对二叉链表表示的二叉树，按从上到下，从左到右打印结点值，即按层次遍历序打印
void printByLevel(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<BinaryTreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            BinaryTreeNode* cur = q.front();
            q.pop();
            cout << cur->val << " ";
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
        cout << endl;
    }
}

int main()
{
    // 创建二叉树
    BinaryTreeNode* root = new BinaryTreeNode(1, 1);
    root->left = new BinaryTreeNode(2, 2);
    root->right = new BinaryTreeNode(3, 2);
    root->left->left = new BinaryTreeNode(4, 3);
    root->left->right = new BinaryTreeNode(5, 3);
    root->right->left = new BinaryTreeNode(6, 3);
    root->right->right = new BinaryTreeNode(7, 3);

    // 叉树中各结点的值及其所对应的层次数
    cout << "按中序次序输出二叉树中各结点的值及其所对应的层次数：" << endl;
    inOrderTraversal(root);
    cout << endl;
    // 测试2: 求二叉树的叶子结点数和1度结点数
    int leafCount = 0, oneDegreeCount = 0;
    countLeafAndOneDegreeNodes(root, leafCount, oneDegreeCount);
    cout << "叶子结点数: " << leafCount << ", 1度结点数: " << oneDegreeCount << endl;

    // 测试3: 查找给定节点的父节点、兄弟节点和子节点
    cout << "查找节点的父节点、兄弟节点和子节点：" << endl;
    findNodeRelations(root, 5);
    cout << endl;

    // 测试4: 查找给定节点在树中的层次
    int x = 2;
    int level = findNodeLevel(root, x);
    if (level != -1) {
        cout << "节点 " << x << " 在树中的层次为: " << level << endl;
    }
    cout << endl;

    // 测试5: 将按顺序方式存储在数组中的二叉树转换为二叉链表形式
    cout << "将按顺序方式存储在数组中的二叉树转换为二叉链表形式：" << endl;
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    BinaryTreeNode* newRoot = arrayToBinaryTree(arr, 7);
    cout << "按层次遍历序打印新二叉树：" << endl;
    printByLevel(newRoot);
    cout << endl;

    // 测试6: 输出二叉树从每个叶子结点到根结点的路径（经历的结点）
    cout << "输出二叉树从每个叶子结点到根结点的路径（经历的结点）：" << endl;
    vector<int> path;
    printPathsFromLeavesToRoot(root, path);
    cout << endl;

    // 测试7: 对二叉链表表示的二叉树，按从上到下，从左到右打印结点值，即按层次遍历序打印
    cout << "按层次遍历序打印二叉树：" << endl;
    printByLevel(root);

    return 0;

}