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
//	//�����ӡset�е�Ԫ�أ�
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//
//	//ʹ�õ����������ӡ
//	for (auto it = s.rbegin(); it != s.rend(); ++it)
//		cout << *it << " ";
//	cout << endl;
//
//	cout << s.count(3) << endl;
//	return 0;
//}
/*mapʹ��*/
//#include <string>
//int main()
//{
//	map<string, string> m;
//
//	//��map�в���Ԫ�صķ�ʽ
//	m.insert(pair<string,
//		string>("peach", "����"));
//
//	m.insert(make_pair("banan", "�㽶"));
//
//	pair<string, string> p("apple", "ƻ��");
//	m.insert(p);
//
//	m["me"] = "��";
//	m["me"] = "��";
//	cout << m.size() << endl;
//
//	for (auto& e : m)
//		cout << e.first << " " << e.second << endl;
//	cout << endl;
//
//	auto ret = m.insert(make_pair("peac", "��ɫ"));
//	if (ret.second)
//		cout << "<��ɫ>֮ǰ����map�У��Ѿ�����" << endl;
//	else
//		cout << "peach��Ԫ���Ѿ�����" <<
//		ret.first->first << " " <<
//		ret.first->second << "����ʧ��" << endl;
//
//	m.erase("apple");
//	if (1 == m.count("apple"))
//		cout << "apple����" << endl;
//	else
//		cout << "appleû��" << endl;
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