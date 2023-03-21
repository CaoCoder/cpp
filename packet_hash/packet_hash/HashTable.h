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
		//BKDR 哈希算法
		size_t hash = 0;
		for (auto ch : key)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};



//开散列 哈希桶
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
	//进行类的声明
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;


	template<class K, class T, class KeyOfT, class HashFunc>
	class _HTIterator
	{
		typedef HashNode<T> Node;
		typedef _HTIterator<K, T, KeyOfT, HashFunc> Self;
	public:
		//定义结点指针
		Node* _node;
		//定义指向哈希表的指针
		HashTable<K, T, KeyOfT, HashFunc>* _pht;
		//构造迭代器
		_HTIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			,_pht(pht)
		{}
		
		//到下一个结点
		Self& operator++()
		{
			//结点不为空
			if (_node->_next)
			{
				//走下一个结点
				_node = _node->_next;
			}
			//第一个桶走到头了
			else
			{
				KeyOfT kot;
				HashFunc hf;
				//然后先kot得到kv.first关键字，在通过关键字算出映射到哪个位置
				size_t hashi = hf(kot(_node->_data));
				//再从下一个位置开始找
				++hashi;
				//找下一个不为空的桶
				for (; hashi < _pht->_tables.size(); ++hashi)
				{
					//如果桶不为空
					if (_pht->_tables[hashi])
					{
						//让结点指针指向第一个桶的第一个元素？是的
						_node = _pht->_tables[hashi];
						break;
					}
				}

				//没有找到不为空的桶，用nullptr去做end标识
				if (hashi == _pht->_tables.size())
				{
					_node = nullptr;
				}
			}
			//返回当前迭代器对象
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
		//迭代器HTIterator是哈希表的朋友，所以它可以访问HashTable的私有或公有的成员
		friend class _HTIterator;//友元类怎么用？我是你的朋友，我就可以访问你的家


		typedef HashNode<T> Node;
	public:
		typedef _HTIterator<K, T, KeyOfT, HashFunc> iterator;

		iterator begin()
		{
			//遍历整个哈希表，找到第一个不为空的桶的第一个结点。
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					//构造迭代器
					return iterator(cur, this);
				}
			}
			//没有找到返回nullptr迭代器
			return end();
		}
		iterator end()
		{
			//构造空的迭代器
			return iterator(nullptr, this);
		}


		bool Insert(const T& data)
		{
			HashFunc hf;
			KeyOfT kot;

			//不允许冗余
			if (Find(kot(data)))
			{
				return false;
			}
			//扩容后避免重新算映射位置，先把旧表的插入新表
			//负载因子等于1，就扩容
			if (_tables.size() == _n)
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;

				vector<Node*> newTable;//开辟哈希表
				newTable.resize(newSize, nullptr);//全部设为空
				
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					//遍历一个桶的每一个结点
					while (cur)
					{
						Node* next = cur->_next;
						//算出旧表每个值的映射位置
						size_t hashi = hf(kot(cur->_data)) % newSize;
						//插入cur头插到新表
						cur->_next = newTable[hashi];//链接后一个结点。第一个插入newTable[hashi]是nullptr
						newTable[hashi] = cur;//头部位置拿到cur的地址。

						cur = next;//旧表++
					}

					_tables[i] = nullptr;//旧表的桶为空,那么新表的桶也效仿。
				}

				newTable.swap(_tables);
			}

			//如果不用扩容，直接插入
			size_t hashi = hf(kot(data));
			hashi %= _tables.size();//算出映射位置

			//头插入相应的桶即可
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];//先连接头结点
			_tables[hashi] = newnode;//再让头结点指向新节点。

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
		//指针数组
		vector<Node*> _tables;
		size_t _n = 0;//存储容量
	};

}