#pragma once
#include <assert.h>
#include <utility>
#include <iostream>
enum Colour
{
	RED,
	BLACK,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;//���� ������ key Ҳ������ pair

	Colour _col;

	RBTreeNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};
//��������ʵ��
template<class T, class Ref, class Ptr>
struct _RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef _RBTreeIterator<T, Ref, Ptr> Self;
	Node* _node;

	_RBTreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	Self& operator++()
	{
		if (_node->_right == nullptr)
		{
			//����������,�����Ǹ�������Ǹ�
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;//�ҵ���
		}
		else
		{
			//��������������
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}

			_node = subLeft;
		}

		return *this;
	}

	Self operator++(int)
	{
		Self tmp(*this);
		++(*this);

		return tmp;
	}

	Self& operator--()
	{
		if (_node->_left == nullptr)
		{
			//���������棬�����Ǹ����ҵ��Ǹ�
			Node* cur = _node;
			Node* parent = cur->_parent;

			while (parent && parent->_left == cur)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}

			_node = parent;

		}
		else
		{
			//�����������ҽڵ�
			Node* subRight = _node->_left;
			while (subRight->_right)
			{
				subRight = subRight->_right;
			}

			_node = subRight;
		}

		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);

		--(*this);
		return tmp;
	}
	
	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}

	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}
};

//T���Ժ�����д�ʲô����

//T ����set ��˵�� RBTree<K, K>
//  ����map ��˵�� RBTree<K. pair<K, V>>

//KeyOfT ֧��ȡ��T�����е�key�ķº���
template<class K, class T, class KeyOfT>
struct RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef _RBTreeIterator<T, T&, T*> iterator;
	typedef _RBTreeIterator<T, const T&, const T*> const_iterator;

	iterator Begin()
	{
		Node* subLeft = _root;
		while (subLeft && subLeft->_left)
		{
			subLeft = subLeft->_left;
		}
		return iterator(subLeft);
	}

	iterator End()
	{
		return iterator(nullptr);
	}

	const_iterator Begin() const
	{
		Node* subLeft = _root;
		while (subLeft && subLeft->_left)
		{
			subLeft = subLeft->_left;
		}

		return const_iterator(subLeft);
	}

	const_iterator End() const
	{
		return const_iterator(nullptr);
	}

	
	pair<iterator, bool> Insert(const T& data)
	{
		// 1���������Ĺ������
		// 2�����Ƿ�Υ��ƽ��������Υ������Ҫ������ת
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		KeyOfT kot;

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), true);
			}
		}

		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED;
		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;

		// ����������ɫ�ڵ�
		while (parent && parent->_col == RED)
		{
			Node* grandfater = parent->_parent;
			assert(grandfater);

			if (grandfater->_left == parent)
			{
				Node* uncle = grandfater->_right;
				// ���һ��
				if (uncle && uncle->_col == RED) // ���������Ϊ��
				{
					// ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;

					// �������ϴ���
					cur = grandfater;
					parent = cur->_parent;
				}
				else // ���岻���� ���� ���������Ϊ��
				{
					if (cur == parent->_left) // ����
					{
						//     g
						//   p
						// c
						RotateR(grandfater);
						parent->_col = BLACK;
						grandfater->_col = RED;
					}
					else // ˫��
					{
						//     g
						//   p
						//     c 
						RotateL(parent);
						RotateR(grandfater);
						cur->_col = BLACK;
						grandfater->_col = RED;
					}

					break;
				}
			}
			else //(grandfater->_right == parent)
			{
				Node* uncle = grandfater->_left;
				// ���һ��
				if (uncle && uncle->_col == RED)
				{
					// ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;

					// �������ϴ���
					cur = grandfater;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						// g
						//   p
						//     c 
						RotateL(grandfater);
						parent->_col = BLACK;
						grandfater->_col = RED;
					}
					else // ˫��
					{
						// g
						//   p
						// c
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

		return make_pair(iterator(newnode), true);
	}


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

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
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

	iterator Find(const K& key)
	{
		Node* cur = _root;
		KeyOfT kot;
		while (cur)
		{
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return iterator(cur);
			}
		}

		return End();
	}

private:
	Node* _root = nullptr;
};
