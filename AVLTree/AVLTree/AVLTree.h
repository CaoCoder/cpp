#pragma once
#include <assert.h>
#include <iostream>
#include <set>
#include <map>
using namespace std;
//�ڵ���
template <class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;//��ֵ��
	AVLTreeNode<K, V>* _left;//������
	AVLTreeNode<K, V>* _right;//������
	AVLTreeNode<K, V>* _parent;//��ָ��

	//һ�������������������ĸ߶Ȳ�
	int _bf;

	//���캯��
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}

};

//AVL����
template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		//1.���������Ĺ������
		//2.���Ƿ�Υ��ƽ��������Υ���ͽ�����ת��
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
		//���ߵ���һ��˵���ҵ��ˣ���ʼ����

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

		//�����²��������ȵ�ƽ������
		// ����µ���
		//1.���Υ������ֱ�ӽ�����
		//2.���û��Υ��������ת����

		/*1.�����߶ȱ��ˣ��ͼ������ϸ��¡�
		2.�����߶Ȳ��䣬��������
		3.����Υ��ƽ�����ֹͣ���£���ת������*/

		//1.���(parent->_bf == 1)������parent->_bf == -1
		//��ʱ������Ҫ�䣬��Ϊԭ����0�������ұ߻���(���)����ˡ�
		//2.���(parent->_bf == 0)
		//��ʱ��parent���ڵ������߶Ȳ���,���½���
		//˵��ԭ����1�����ڱ��0��֮ǰһ�߸�һ�ߵͣ����ڲ���
		//ֻ��һ������������˰���һ�ߡ�
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
			//�Ƿ�������£�
			//˵�������������˰�����һ��
			if (parent->_bf == 0)
			{
				//�߶Ȳ��䣬���½���
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//�����ĸ߶ȱ��ˣ�������������
				cur = cur->_parent;
				parent->parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//��ƽ���ˣ�ֱ����ת��
			}
			else
			{
				//����֮ǰAVL�ʹ��ڲ�ƽ������ƽ�����ӵľ���ֵ�д���2
				//���ڵĽڵ�
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

		//1.parent�����Ǹ�
		//2.parentֻ��������������
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