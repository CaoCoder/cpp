#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <array>
#include <string>
#include <forward_list>
#include "list.h"
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
//	A aa2 = 1;//��ʽ���͵�ת��+�Ż�
//
//	Date d1(2023, 3, 30);
//	Date d2 = { 2023, 3, 30 };//C++11����A ���淨����չ����ʿ���͵�ת��+�Ż���
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
//	map<string, int> dict = { {"wd",1} ,{"�㽶",2}, {"����",3},};
//
//	//initializer_list������
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
//	////�Ա�c�ľ�̬���ݣ����ʸ���ȫ
//	//array<int, 10> a2;
//
//	////ֻҪԽ��һ���ܼ�����
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
//	//��a��Ϊ��ֵ
//	int&& r2 = move(a);
//
//	return 0;
//}

namespace cao
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			,_capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		//�ƶ�����
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- ��Դת��" << endl;
			swap(s);
		}
		//��������
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0) {
			cout << "string(const string& s) -- ���" << endl;
			string tmp(s._str);
			swap(tmp);
		}

		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- ��Դת��" << endl;
			swap(s);

			return *this;
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';

		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;//������\0
	};
	void func1(const cao::string& s)
	{}


	// ����ĳ������ٵ����⣬ֻ�ܴ�ֵ���أ���ֵ���ý������
	// ����++

	cao::string operator+(const cao::string& s, char ch)
	{
		cao::string ret(s);
		ret += ch;

		return ret;
	}
	cao::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		cao::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}

}

//int main()
//{
//	//cao::string s1("hello");//��ֵ���ý��
//	//func1(s1);
//
//	//cao::string ret = cao::to_string(1234);
//	//cout << ret.c_str() << endl;
//	std::string s1("hello");
//	std::string s2(s1);//���
//	std::string s3(move(s1));//ת�ƽ���ֵ����Դ
//	
//}
//int main()
//{
//	std::list<cao::string> lt;
//	/*cao::string s1("1111");
//	lt.push_back(s1);*/
//
//	lt.push_back("2222");
//	//lt.push_back(std::move(s1));
//	std::string s2("hello world");
//	std::string s3 = std::move(s2);
//	//std::string s3 = s2;
//
//	/*void Fun(int& x)
//	{
//		cout << "��ֵ����" << endl;
//	}*/
//
//	
//
//}


void Func(int& x)
{
	cout << "��ֵ����" << endl;
}
void Func(const int& x)
{
	cout << "const ��ֵ����" << endl;
}
void Func(int&& x)
{
	cout << "��ֵ����" << endl;
}
void Func(const int&& x)
{
	cout << "const ��ֵ����" << endl;
}
//Ҳ����˵����ֵ����һ�β������ݺ������Ի��˻�����ֵ
//�������Ҫ����������б�����ֵ�����ԣ�����Ҫ�õ�����ת����
template<typename T>
void PerfectForward(T&& t)
{
	Func(std::forward<T>(t));
}
//int main()
//{
//	int a = 10;
//	PerfectForward(a);       //��ֵ
//	PerfectForward(move(a)); //��ֵ
//
//	const int b = 20;
//	PerfectForward(b);       //const ��ֵ
//	PerfectForward(move(b)); //const ��ֵ
//
//	return 0;
//}

//template<class ...Args>
//void ShowList1(Args... args)
//{
//	//��������
//	cout << sizeof...(args) << endl;
//}
//int main()
//{
//	ShowList1();
//	ShowList1(1);
//	ShowList1(1, 'A');
//	ShowList1(1, 'A', string("hello"));
//	return 0;
//}

////�ݹ���ֹ����
//void ShowList1()
//{
//	cout << endl;
//}
////��ӡ����
//template<class T, class ...Args>
//void ShowList1(T value, Args... args)
//{
//	cout << value << " ";//��ӡ������ĵ�һ������
//	ShowList1(args...);//�ݹ���á����������ݲ�����
//}

////�ݹ���ֹ����
//template<class T>
//void ShowListArg(const T& t)
//{
//	cout << t << endl;
//}
//template<class ...Args>
//void ShowList(Args... args);
//
////չ������
//template<class T, class ...Args>
//void ShowListArg(T value, Args... args)
//{
//	cout << value << " "; //��ӡ��������ɲ����еĵ�һ������
//	ShowList(args...);    //��ʣ�²����������´�
//}
////���ⲿ���õĺ���
//template<class ...Args>
//void ShowList(Args... args)
//{
//	ShowListArg(args...);
//}
//����������е�ÿ������
template<class T>
void PrintArg(const T& t)
{
	cout << t << " ";
}
//չ������
template<class ...Args>
void ShowList(Args... args)
{
	int arr[] = { (PrintArg(args), 0)... }; //�б��ʼ��+���ű��ʽ
	cout << endl;
}

int main()
{
	/*ShowList();*/
	ShowList(1);
	ShowList(1, 'A');
	ShowList(1, 'A', string("hello"));
	return 0;
}