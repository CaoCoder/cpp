#pragma once
#include <assert.h>
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
enum Colour
{
	RED,
	BLACK,	
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;

	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};

template<class K, class V>
struct RBTree
{
	typedef RBTreeNode<K, V> Node;

public:
	//左单旋
	//p
	//	 subR
	//subRL   c
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* ppNode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parent == ppNode->_left)
			{
				ppNode->_left = subR;
			}
			else
			{
				ppNode->_right = subR;
			}

			subR->_parent = ppNode;
		}
	}
	

	//中序遍历
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}


	//右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* ppNode = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}

	}

	//判断是否为红黑树
	bool _IsValidRBTree(Node* pRoot, size_t k,
		const size_t blackCount)
	{
		//走到null之后，判断k和black是否相等
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径中黑色节点个数必须相同" << endl;
				return false;
			}
			return true;
		}

		//统计黑色节点个数
		if (BLACK == pRoot->_col)
			k++;
		//检查当前节点与其双亲是否都为红色
		if (RED == pRoot->_col && pRoot->_parent && pRoot->_parent->_col == RED)
		{
			cout << "违反性质三：存在连在一起的红色结点" << endl;
			return false;
		}

		return _IsValidRBTree(pRoot->_left, k, blackCount) &&
			_IsValidRBTree(pRoot->_right, k, blackCount);
	}
	
	bool IsBalanceTree()
	{
		//检查红黑树几条顾泽
		Node* pRoot = _root;
		//空树也是红黑树
		if (nullptr == pRoot)
			return true;
		//检查节点是否满足情况
		if (BLACK != pRoot->_col)
		{
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}

		//获取任意一条路径上黑色节点的个数 ——比较基准值
		//这里以最左边为准
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_col)
				blackCount++;
			pCur = pCur->_left;
		}

		//检查是否满足红黑树的性质 k用来记录黑色节点个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	//层序遍历
	vector<vector<int>> levelOrder()
	{
		vector<vector<int>> vv;
		if (nullptr == _root)
			return vv;

		queue<Node*> q;
		int levelSize = 1;
		q.push(_root);

		while (!q.empty())
		{
			vector<int> levelV;
			while (levelSize--)
			{
				Node* front = q.front();
				q.pop();
				levelV.push_back(front->_kv.first);
				if (front->_left)
					q.push(front->_left);
				if (front->_right)
					q.push(front->_right);
			}

			vv.push_back(levelV);
			for (auto e : levelV)
			{
				cout << e << " ";
			}
			cout << endl;

			levelSize = q.size();
		}

		return vv;
	}
	//计算最大高度
	int _maxHeight(Node* root)
	{
		if (root == nullptr)
			return 0;
		int lh = _maxHeight(root->_left);
		int rh = _maxHeight(root->_right);

		return lh > rh ? lh + 1 : rh + 1;
	}

	int _minHeight(Node* root)
	{
		if (root == nullptr)
			return 0;

		int lh = _minHeight(root->_left);
		int rh = _minHeight(root->_right);

		return lh < rh ? lh + 1 : rh + 1;
	}

	void Height()
	{
		cout << "最长路径:" << _maxHeight(_root) << endl;
		cout << "最短路径:" << _minHeight(_root) << endl;
	}



	bool Insert(const pair<K, V>& kv)
	{
		//1.搜索树的插入规则
		//2.看是否违反平衡规则，如果违反就处理：旋转
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		//开始插入
		cur = new Node(kv);
		cur->_col = RED;
		if (kv.first > parent->_kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;
		//判断规则
		//1.假如存在连续的红色节点
		while (parent && parent->_col == RED)
		{
			Node* grandfater = parent->_parent;
			assert(grandfater);
			
			if (grandfater->_left == parent)
			{
				Node* uncle = grandfater->_right;
				// 情况一 爸爸为红，叔叔存在且为红
				if (uncle && uncle->_col == RED)
				{
					//变色
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;

					//继续往上处理
					cur = grandfater;
					parent = cur->_parent;
				}
				else//叔叔不存在 或者 叔叔存在且为黑
				{
					//都在左边线上，单旋
					if (cur == parent->_left)
					{
						//有单旋
						RotateR(grandfater);
						//变色
						parent->_col = BLACK;
						grandfater->_col = RED;

					}
					//是折线，就双旋
					else
					{
						RotateL(parent);
						RotateR(grandfater);

						cur->_col = BLACK;
						grandfater->_col = RED;
					}

					break;
				}

			}
			//grandfater的右是parent
			else
			{
				Node* uncle = grandfater->_left;
				
				//情况1如果叔叔为红，父亲也为红
				if (uncle && uncle->_col == RED)
				{
					//变色
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;
					//继续向上处理

					cur = grandfater;
					parent = cur->_parent;

				}
				//情况二
				else//叔叔不存在 或 叔叔为黑 
				{
					//是一条线
					//g
					//	p
					//	  c
					if (cur == parent->_right)
					{
						RotateL(grandfater);
						grandfater->_col = RED;
						parent->_col = BLACK;
					}
					else //双旋
					{
						//g
						//	p
						//c
						RotateR(parent);
						RotateL(grandfater);
						cur->_col = BLACK;
						grandfater->_col = RED;
					}
					break;
				}

			}
		}
		//确保根节点为黑
		_root->_col = BLACK;

		return true;
	}
private:
	Node* _root = nullptr;

};

void test1()
{
	int a[] = { 30, 29, 28, 27, 26, 25, 24, 11, 8, 7, 6, 5, 4, 3, 2, 1 };
	RBTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	t.InOrder();
	t.levelOrder();
	t.Height();
	cout << t.IsBalanceTree() <<endl;
}
void test2()
{
	const size_t N = 1024 * 1024;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(rand());
		//v.push_back(i);
	}

	RBTree<int, int> t;
	for (auto e : v)
	{
		t.Insert(make_pair(e, e));
	}

	//t.levelOrder();
	//cout << endl;
	cout << "是否平衡?" << t.IsBalanceTree() << endl;
	t.Height();

	//t.InOrder();
}
