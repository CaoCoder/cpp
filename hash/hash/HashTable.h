#pragma once
#include<vector>
#include <iostream>
using namespace std;
namespace CloseHash
{
	enum State
	{
		EMPTY,
		EXITS,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K>
	struct DefaultHash
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};

	//特化
	template<>
	struct DefaultHash<string>
	{
		size_t operator()(const string& key)
		{
			//BKDR算法
			size_t hash = 0;
			for (auto ch : key)
			{
				//hash += ch;另字符串每个字符相加
				//为了解决苹果 和 果苹的问题
				hash = hash * 131 + ch;
			}
			return hash;
		}
	};

	template<class K, class V, class HashFunc = DefaultHash<K>>
	class HashTable
	{
		typedef HashData<K, V> Data;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			//防冗余
			if (Find(kv.first))
			{
				return false;
			}

			//判断负载因子来扩容超过0.7就扩容
			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				//扩容以后需要重新映射
				HashTable<K, V, HashFunc> newHT;
				newHT._tables.resize(newSize);
				//遍历旧表，把旧表的值重新映射到新表newHT
				for (auto& e : _tables)
				{
					if (e._state == EXITS)
					{
						newHT.Insert(e._kv);
					}
				}
				//交换的新表的vector的_tables和旧表的vector的_tables;
				//vecotr是自定义类型自带析构函数
				newHT._tables.swap(_tables);
			}

			HashFunc hf;
			size_t starti = hf(kv.first);
			starti %= _tables.size();//除留余法

			size_t hashi = starti;
			size_t i = 1;
			//线性探测
			//如果不为空就往后走
			while (_tables[hashi]._state == EXITS)
			{
				hashi = starti + i;
				++i;
				hashi %= _tables.size();//留余防止越界。
			}

			//为空或删除
			_tables[hashi]._kv = kv;//通过下表赋值
			_tables[hashi]._state = EXITS;//改状态
			_n++;

			return true;

		}

		
		Data* Find(const K& key)
		{
			//假如表是空，返回nullptr
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			HashFunc hf;
			size_t starti = hf(key);
			starti %= _tables.size();

			size_t hashi = starti;
			size_t i = 1;
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state != DELETE && _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}

				//没找到
				hashi = starti + i;
				++i;
				hashi %= _tables.size();
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			Data* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}
	private:
		vector<Data> _tables;
		size_t _n = 0;//存储关键字个数
	};

	void TestHT1()
	{
		int a[] = { 20, 5, 8, 99999, 10, 30, 50 };
		HashTable<int, int> ht;

		if (ht.Find(10))
		{
			cout << "找到了10" << endl;
		}

		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		if (ht.Find(50))
		{
			cout << "找到了50" << endl;
		}

		// 测试扩容
		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(5, 5));
		ht.Insert(make_pair(15, 15));
		ht.Erase(10);
		ht.Erase(10);


	
	}
	void TestHT2()
	{
		string arr[] = { "苹果", "西瓜","苹果",
			"西瓜","苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };

		HashTable<string, int> countHT;
		for (auto& str : arr)
		{
			//找到了返回真
			auto ret = countHT.Find(str);
			if (ret)
			{
				ret->_kv.second++;
			}
			//找不到就插入
			else
			{
				countHT.Insert(make_pair(str, 1));
			}
		}
	}
}


//开散列 哈希桶
namespace Bucket
{
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{}
	};

	template<class K, class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{

			//负载因子等于1，就扩容
			if (_tables.size() == _n)
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newHT;
				newHT._tables.resize(newSize, nullptr);

				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						newHT.Insert(cur->_kv);
						cur = cur->_next;
					}
				}

				newHT._tables.swap(_tables);
			}


			size_t hashi = kv.first;
			hashi %= _tables.size();
			
			//头插入相应的桶即可
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return true;
		}


		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			size_t hashi = key;
			hashi %= _tables.size();
			Node* cur = _tables[hashi];
			
			while (cur)
			{
				if (cur->_kv.first == key)
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

	void TestHT1()
	{
		int a[] = { 20, 5, 8, 99999, 10, 30, 50 };
		//HashTable<int, int, DefaultHash<int>> ht;
		HashTable<int, int> ht;

		if (ht.Find(10))
		{
			cout << "找到了10" << endl;
		}

		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		// 测试扩容
		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(5, 5));
		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(25, 15));
		ht.Insert(make_pair(35, 15));
		ht.Insert(make_pair(45, 15));
	}

}