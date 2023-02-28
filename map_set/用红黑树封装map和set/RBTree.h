#pragma once

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
	T _data;//数据

	Colour _col;

	RBTreeNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}

};
//正向迭代器
template<class T, class Ref, class Ptr>
struct _RBTreeIterator
{
	typedef RBTreeNode<T> Node;//节点类型
	typedef _RBTreeIterator<T, Ref, Ptr> Self;//迭代器类型
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
	//这是难点,通过中序遍历找到当前结点的下一个节点
	Self& operator++()
	{
		if (_node->_right == nullptr)
		{
			//找祖先里面，孩子是父亲左的那个
			Node* cur = _node;
			Node* parent = cur->_parent;

		}
	}

};

template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;


};