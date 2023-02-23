#pragma once

template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
};

template<class K>
class BSTree
{
	typedef BSTreeNode Node;
public:
	bool Insert(const K& Key)
	{

	}
private:
	Node* _root = nullptr;
};