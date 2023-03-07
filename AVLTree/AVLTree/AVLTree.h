#pragma once
#include <assert.h>
#include <iostream>
#include <set>
#include <map>
using namespace std;
//节点类
template <class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;//键值对
	AVLTreeNode<K, V>* _left;//左子树
	AVLTreeNode<K, V>* _right;//右子树
	AVLTreeNode<K, V>* _parent;//父指针

	//一般是右子树减左子树的高度差
	int _bf;

	//构造函数
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}

};

//AVL树类
template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		//1.按搜索树的规则插入
		//2.看是否违反平衡规则，如果违反就进行旋转。
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;

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
		//能走到这一行说明找到了，开始插入

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//更新新插入结点祖先的平衡因子
		// 最坏更新到根
		//1.如果违反规则直接结束，
		//2.如果没有违反，则旋转处理。

		/*1.子树高度变了，就继续往上更新。
		2.子树高度不变，则更新完成
		3.子树违反平衡规则，停止更新，旋转子树。*/

		//1.如果(parent->_bf == 1)，或者parent->_bf == -1
		//这时候祖先要变，因为原来是0，现在右边或者(左边)变高了。
		//2.如果(parent->_bf == 0)
		//这时候parent所在的子树高度不变,更新结束
		//说明原来是1，现在变成0，之前一边高一边低，现在插入
		//只有一种情况，填上了矮的一边。
		while (parent)
		{
			if (cur == parent->right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--
			}
			//是否继续更新？
			//说明插入结点填上了矮的那一边
			if (parent->_bf == 0)
			{
				//高度不变，更新结束
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//子树的高度变了，继续更新祖先
				cur = cur->_parent;
				parent->parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//不平衡了，直接旋转。
			}
			else
			{
				//插入之前AVL就存在不平衡树，平衡因子的绝对值有大于2
				//等于的节点
				assert(false);
			}
		}
		
		


		return true;
	}

private:
	RotateL(Node* _root)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if(subRL)
			subRL->_parent = parent;

		Node* ppNode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		//1.parent可能是根
		//2.parent只是整个树的子树
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
private:
	Node* _root = nullptr;
};

void TestAVLTree()
{
	AVLTree<int, int> t;
	t.Insert(make_pair(1, 1));
	t.Insert(make_pair(2, 2));
	t.Insert(make_pair(3, 3));
}