#pragma once

#include "HashTable.h"

namespace cao
{
	template<class K, class HashFunc = DefaultHash<K>>
	class unordered_set
	{
		//Àà²¿ Àà
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename Bucket::HashTable<K, K, SetKeyOfT, HashFunc>::iterator iterator;
		
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}

		bool insert(const K& key)
		{
			return _ht.Insert(key);
		}
	private:
		Bucket::HashTable<K, K, SetKeyOfT, HashFunc> _ht;
	};

	void test_set()
	{
		unordered_set<int> s;
		s.insert(2);
		s.insert(3);
		s.insert(1);
		s.insert(2);
		s.insert(5);
		s.insert(12);
		unordered_set<int>::iterator it = s.begin();
		//auto it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;


		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;

	}

}