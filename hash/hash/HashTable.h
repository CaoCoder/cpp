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

	//�ػ�
	template<>
	struct DefaultHash<string>
	{
		size_t operator()(const string& key)
		{
			//BKDR�㷨
			size_t hash = 0;
			for (auto ch : key)
			{
				//hash += ch;���ַ���ÿ���ַ����
				//Ϊ�˽��ƻ�� �� ��ƻ������
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
			//������
			if (Find(kv.first))
			{
				return false;
			}

			//�жϸ������������ݳ���0.7������
			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				//�����Ժ���Ҫ����ӳ��
				HashTable<K, V, HashFunc> newHT;
				newHT._tables.resize(newSize);
				//�����ɱ��Ѿɱ��ֵ����ӳ�䵽�±�newHT
				for (auto& e : _tables)
				{
					if (e._state == EXITS)
					{
						newHT.Insert(e._kv);
					}
				}
				//�������±��vector��_tables�;ɱ��vector��_tables;
				//vecotr���Զ��������Դ���������
				newHT._tables.swap(_tables);
			}

			HashFunc hf;
			size_t starti = hf(kv.first);
			starti %= _tables.size();//�����෨

			size_t hashi = starti;
			size_t i = 1;
			//����̽��
			//�����Ϊ�վ�������
			while (_tables[hashi]._state == EXITS)
			{
				hashi = starti + i;
				++i;
				hashi %= _tables.size();//�����ֹԽ�硣
			}

			//Ϊ�ջ�ɾ��
			_tables[hashi]._kv = kv;//ͨ���±�ֵ
			_tables[hashi]._state = EXITS;//��״̬
			_n++;

			return true;

		}

		
		Data* Find(const K& key)
		{
			//������ǿգ�����nullptr
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

				//û�ҵ�
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
		size_t _n = 0;//�洢�ؼ��ָ���
	};

	void TestHT1()
	{
		int a[] = { 20, 5, 8, 99999, 10, 30, 50 };
		HashTable<int, int> ht;

		if (ht.Find(10))
		{
			cout << "�ҵ���10" << endl;
		}

		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		if (ht.Find(50))
		{
			cout << "�ҵ���50" << endl;
		}

		// ��������
		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(5, 5));
		ht.Insert(make_pair(15, 15));
		ht.Erase(10);
		ht.Erase(10);


	
	}
	void TestHT2()
	{
		string arr[] = { "ƻ��", "����","ƻ��",
			"����","ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };

		HashTable<string, int> countHT;
		for (auto& str : arr)
		{
			//�ҵ��˷�����
			auto ret = countHT.Find(str);
			if (ret)
			{
				ret->_kv.second++;
			}
			//�Ҳ����Ͳ���
			else
			{
				countHT.Insert(make_pair(str, 1));
			}
		}
	}
}


//��ɢ�� ��ϣͰ
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

			//�������ӵ���1��������
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
			
			//ͷ������Ӧ��Ͱ����
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
		//ָ������
		vector<Node*> _tables;
		size_t _n = 0;//�洢����
	};

	void TestHT1()
	{
		int a[] = { 20, 5, 8, 99999, 10, 30, 50 };
		//HashTable<int, int, DefaultHash<int>> ht;
		HashTable<int, int> ht;

		if (ht.Find(10))
		{
			cout << "�ҵ���10" << endl;
		}

		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		// ��������
		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(5, 5));
		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(25, 15));
		ht.Insert(make_pair(35, 15));
		ht.Insert(make_pair(45, 15));
	}

}