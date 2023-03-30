#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <array>
#include <string>
#include <forward_list>
using namespace std;

#include <assert.h>

//struct Point
//{
//	int _x;
//	int _y;
//};
//
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		, _day(day)
//	{
//		cout << "	Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//namespace cao
//{
//	template<class T>
//	class vector
//	{
//	public:
//		typedef T* iterator;
//		vector(initializer_list<T> l)
//		{
//			_start = new T[l.size()];
//			_finish = _start + l.size();
//			_endofstorage = _start + l.size();
//
//			iterator vit = _start;
//			typename initializer_list<T>::iterator lit = l.begin();
//			while (lit != l.end())
//			{
//				*vit++ = *lit++;
//			}
//			//for (auto e : l)
//			//	*vit++ = e;
//		}
//
//		vector<T>& operator=(initializer_list<T> l)
//		{
//			vector<T> tmp(l);
//			std::swap(_start, tmp._start);
//			std::swap(_finish, tmp._finish);
//			std::swap(_endofstorage, tmp._endofstorage);
//
//			return *this;
//		}
//	private:
//		iterator _start;
//		iterator _finish;
//		iterator _endofstorage;
//	};
//}
//
//int main()
//{
//	int x1 = 1;
//	int* p0 = new int(1);
//
//	int* p1 = new int{1};
//	int* p2 = new int[3] {1, 3, 4};
//	//c++98
//	A aa1(1);
//	A aa2 = 1;//隐式类型的转换+优化
//
//	Date d1(2023, 3, 30);
//	Date d2 = { 2023, 3, 30 };//C++11类似A 的玩法的扩展，隐士类型的转换+优化。
//
//	Date* p3 = new Date(1, 2, 3);
//
//	Date* p4 = new Date[3]{ {1,3,4},{1,4,4},{1,4,4} };
//
//	cao::vector<int> v1 = { 1,2,3,4,5 };
//
//	cao::vector<int> v2{ 1,2,3,4,5 };
//	
//	list<int> lt1{ 1,2,3 };
//
//	set<int> s1{ 1,3,4,5 };
//
//	map<string, int> dict = { {"wd",1} ,{"香蕉",2}, {"西瓜",3},};
//
//	//initializer_list的类型
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//
//	initializer_list<double> ilt = { 3.3, 5.5, 9.9 };
//	initializer_list<double>::iterator it = ilt.begin();
//	while (it != ilt.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

template<class K, class V>
class HashTable
{
private:
	vector<forward_list<pair<K, V>>> _tables;
};

//int main()
//{
//	//int a1[10];
//	////对比c的静态数据，访问更安全
//	//array<int, 10> a2;
//
//	////只要越界一定能检查出来
//	//a2[10];
//
//	set<int> s;
//	s.insert({ 3,4,2,1,5,6 });
//
//	return 0;
//}

//int main()
//{
//	double x = 1.1, y = 2.2;
//	10;
//	x + y;
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	int a = 10;
//	//将a变为右值
//	int&& r2 = move(a);
//
//	return 0;
//}

