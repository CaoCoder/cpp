#pragma once
#include<vector>
#include <iostream>
using namespace std;

template<class K>
struct DefaultHash
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};
template<>
struct DefaultHash<string>
{
	size_t operator()(const string& key)
	{
		//BKDR ��ϣ�㷨
		size_t hash = 0;
		for (auto ch : key)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};



//��ɢ�� ��ϣͰ
namespace Bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};
	//�����������
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;


	template<class K, class T, class KeyOfT, class HashFunc>
	class _HTIterator
	{
		typedef HashNode<T> Node;
		typedef _HTIterator<K, T, KeyOfT, HashFunc> Self;
	public:
		//������ָ��
		Node* _node;
		//����ָ���ϣ���ָ��
		HashTable<K, T, KeyOfT, HashFunc>* _pht;
		//���������
		_HTIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			,_pht(pht)
		{}
		
		//����һ�����
		Self& operator++()
		{
			//��㲻Ϊ��
			if (_node->_next)
			{
				//����һ�����
				_node = _node->_next;
			}
			//��һ��Ͱ�ߵ�ͷ��
			else
			{
				KeyOfT kot;
				HashFunc hf;
				//Ȼ����kot�õ�kv.first�ؼ��֣���ͨ���ؼ������ӳ�䵽�ĸ�λ��
				size_t hashi = hf(kot(_node->_data));
				//�ٴ���һ��λ�ÿ�ʼ��
				++hashi;
				//����һ����Ϊ�յ�Ͱ
				for (; hashi < _pht->_tables.size(); ++hashi)
				{
					//���Ͱ��Ϊ��
					if (_pht->_tables[hashi])
					{
						//�ý��ָ��ָ���һ��Ͱ�ĵ�һ��Ԫ�أ��ǵ�
						_node = _pht->_tables[hashi];
						break;
					}
				}

				//û���ҵ���Ϊ�յ�Ͱ����nullptrȥ��end��ʶ
				if (hashi == _pht->_tables.size())
				{
					_node = nullptr;
				}
			}
			//���ص�ǰ����������
			return *this;
		}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node = s._node;
		}
	};

	// unordered_map ->HashTable<K, pair<K, V>, MapKeyOfT> _ht;
	// unordered_set ->HashTable<K, K, SetKeyOfT> _ht;

	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable
	{
		template<class K, class T, class KeyOfT, class HashFunc>
		//������HTIterator�ǹ�ϣ������ѣ����������Է���HashTable��˽�л��еĳ�Ա
		friend class _HTIterator;//��Ԫ����ô�ã�����������ѣ��ҾͿ��Է�����ļ�


		typedef HashNode<T> Node;
	public:
		typedef _HTIterator<K, T, KeyOfT, HashFunc> iterator;

		iterator begin()
		{
			//����������ϣ���ҵ���һ����Ϊ�յ�Ͱ�ĵ�һ����㡣
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					//���������
					return iterator(cur, this);
				}
			}
			//û���ҵ�����nullptr������
			return end();
		}
		iterator end()
		{
			//����յĵ�����
			return iterator(nullptr, this);
		}


		bool Insert(const T& data)
		{
			HashFunc hf;
			KeyOfT kot;

			//����������
			if (Find(kot(data)))
			{
				return false;
			}
			//���ݺ����������ӳ��λ�ã��ȰѾɱ�Ĳ����±�
			//�������ӵ���1��������
			if (_tables.size() == _n)
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;

				vector<Node*> newTable;//���ٹ�ϣ��
				newTable.resize(newSize, nullptr);//ȫ����Ϊ��
				
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					//����һ��Ͱ��ÿһ�����
					while (cur)
					{
						Node* next = cur->_next;
						//����ɱ�ÿ��ֵ��ӳ��λ��
						size_t hashi = hf(kot(cur->_data)) % newSize;
						//����curͷ�嵽�±�
						cur->_next = newTable[hashi];//���Ӻ�һ����㡣��һ������newTable[hashi]��nullptr
						newTable[hashi] = cur;//ͷ��λ���õ�cur�ĵ�ַ��

						cur = next;//�ɱ�++
					}

					_tables[i] = nullptr;//�ɱ��ͰΪ��,��ô�±��ͰҲЧ�¡�
				}

				newTable.swap(_tables);
			}

			//����������ݣ�ֱ�Ӳ���
			size_t hashi = hf(kot(data));
			hashi %= _tables.size();//���ӳ��λ��

			//ͷ������Ӧ��Ͱ����
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];//������ͷ���
			_tables[hashi] = newnode;//����ͷ���ָ���½ڵ㡣

			++_n;
			return true;
		}


		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}
			KeyOfT kot;
			HashFunc hf;

			size_t hashi = hf(key);
			hashi %= _tables.size();
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return cur;
				}

				cur = cur->_next;
			}

			return nullptr;
		}
	private:
		//ָ������
		vector<Node*> _tables;
		size_t _n = 0;//�洢����
	};

}