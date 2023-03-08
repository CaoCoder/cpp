#pragma once

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
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(RED)
	{}
};

template<class K, class V>
struct RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		//1、搜索树的规则插入
		//2、看是否违反平衡规则，如果违反就需要处理：旋转
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;//为什么先设置为黑色
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

		//找到了开始插入
		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//判断是否存在连续的红色结点
		while (parent && parent->_col == RED)
		{
			Node* grandfater = parent->_parent;
			assert(grandfater);

			if (grandfater->_left == parent)
			{
				Node* uncle = grandfater->_right;
				//情况一：
				if (uncle && uncle->_col == RED)//叔叔存在且为红
				{
					//变色
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;//为了保持子树黑色结点数量不变

					//继续往上处理
					cur = grandfater;//这句话什么意思？和cur有什么关系：让cur指向g，继续往上调
					parent = cur->_parent;
				}
				else//叔叔不存在 或者 叔叔存在且为黑
				{
					//     g
					//   p
					// c
					if (cur == parent->_left)//左边高，右单旋
					{
						RotateR(grandfater);
						parent->_col = BLACK;
						grandfater->_col = RED;
					}
					else//双旋
					{
						RotateL(parent);
						RotateR(grandfater);
						cur->_col = BLACK;
						grandfater->_col = RED;
					}

					break;//为什么要break
				}
			}
			//为什么要分左右
			else(grandfater->_right == parent)
			{
				Node* uncle = grandfater->_left;
				//情况一：
				if (uncle && uncle->_col == RED)
				{
					//变色
					parent->_col = uncle->_col = BLACK;

					//继续向上处理
					cur = grandfater;
					parent = cur->parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(grandfater);
						parent->_col = BLACK;
						grandfater->_col = RED;
					}
					else
					{
						//双旋
						RotateR(parent);
						RotateL(grandfater);
						cur->_col = BLACK;
						grandfater->_col = RED;
					}

					break;
				}

			}
		}

		_root->_col = BLACK;
		return true;
	}
private:
	Node* _root = nullptr;
};