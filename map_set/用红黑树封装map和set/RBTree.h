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
	T _data;//����

	Colour _col;

	RBTreeNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}

};
//���������
template<class T, class Ref, class Ptr>
struct _RBTreeIterator
{
	typedef RBTreeNode<T> Node;//�ڵ�����
	typedef _RBTreeIterator<T, Ref, Ptr> Self;//����������
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
	//�����ѵ�,ͨ����������ҵ���ǰ������һ���ڵ�
	Self& operator++()
	{
		if (_node->_right == nullptr)
		{
			//���������棬�����Ǹ�������Ǹ�
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