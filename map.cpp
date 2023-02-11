#include <iostream>
#include <set>
#include <map>
using namespace std;
//int main()
//{
//	int array[] = { 1,3,5,7,9,2,4,6,8 };
//	set<int> s(array, array + 
//		sizeof(array) / sizeof(array[0]));
//	cout << s.size() << endl;
//
//	//正向打印set中的元素，
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//
//	//使用迭代器逆向打印
//	for (auto it = s.rbegin(); it != s.rend(); ++it)
//		cout << *it << " ";
//	cout << endl;
//
//	cout << s.count(3) << endl;
//	return 0;
//}
/*map使用*/
//#include <string>
//int main()
//{
//	map<string, string> m;
//
//	//向map中插入元素的方式
//	m.insert(pair<string,
//		string>("peach", "桃子"));
//
//	m.insert(make_pair("banan", "香蕉"));
//
//	pair<string, string> p("apple", "苹果");
//	m.insert(p);
//
//	m["me"] = "我";
//	m["me"] = "你";
//	cout << m.size() << endl;
//
//	for (auto& e : m)
//		cout << e.first << " " << e.second << endl;
//	cout << endl;
//
//	auto ret = m.insert(make_pair("peac", "桃色"));
//	if (ret.second)
//		cout << "<桃色>之前不在map中，已经插入" << endl;
//	else
//		cout << "peach的元素已经存在" <<
//		ret.first->first << " " <<
//		ret.first->second << "插入失败" << endl;
//
//	m.erase("apple");
//	if (1 == m.count("apple"))
//		cout << "apple还在" << endl;
//	else
//		cout << "apple没了" << endl;
//
//	for (auto& e : m)
//		cout << e.first << " " << e.second << endl;
//	cout << endl;
//	return 0;
//}

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, pParent(nullptr)
		, data(data)
		, _bf(0)
	{}
	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;

};