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
		//1���������Ĺ������
		//2�����Ƿ�Υ��ƽ��������Υ������Ҫ������ת
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;//Ϊʲô������Ϊ��ɫ
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

		//�ҵ��˿�ʼ����
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

		//�ж��Ƿ���������ĺ�ɫ���
		while (parent && parent->_col == RED)
		{
			Node* grandfater = parent->_parent;
			assert(grandfater);

			if (grandfater->_left == parent)
			{
				Node* uncle = grandfater->_right;
				//���һ��
				if (uncle && uncle->_col == RED)//���������Ϊ��
				{
					//��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfater->_col = RED;//Ϊ�˱���������ɫ�����������

					//�������ϴ���
					cur = grandfater;//��仰ʲô��˼����cur��ʲô��ϵ����curָ��g���������ϵ�
					parent = cur->_parent;
				}
				else//���岻���� ���� ���������Ϊ��
				{
					//     g
					//   p
					// c
					if (cur == parent->_left)//��߸ߣ��ҵ���
					{
						RotateR(grandfater);
						parent->_col = BLACK;
						grandfater->_col = RED;
					}
					else//˫��
					{
						RotateL(parent);
						RotateR(grandfater);
						cur->_col = BLACK;
						grandfater->_col = RED;
					}

					break;//ΪʲôҪbreak
				}
			}
			//ΪʲôҪ������
			else(grandfater->_right == parent)
			{
				Node* uncle = grandfater->_left;
				//���һ��
				if (uncle && uncle->_col == RED)
				{
					//��ɫ
					parent->_col = uncle->_col = BLACK;

					//�������ϴ���
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
						//˫��
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