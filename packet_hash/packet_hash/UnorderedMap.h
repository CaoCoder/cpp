#pragma once

#include "HashTable.h"
namespace cao
{
	template<class K, class V, class HashFunc = DefaultHash<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		bool insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}
	private:
		Bucket::HashTable<K, pair<K, V>, MapKeyOfT, HashFunc> _ht;
	};

	void test_map()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "ÅÅĞò"));
		dict.insert(make_pair("left", "×ó±ß"));
		dict.insert(make_pair("left", "ÁôÏÂ"));
	}
}