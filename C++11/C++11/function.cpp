#include <iostream>
#include<functional>
using namespace std;

//int f(int a, int b)
//{
//	return a + b;
//}
//struct Functor
//{
//public:
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//class Plus
//{
//public:
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return a + b;
//	}
//};
//int main()
//{
//	//1����װ����ָ�루��������
//	function<int(int, int)> func1 = f;
//	cout << func1(1, 2) << endl;
//
//	//2����װ�º�������������
//	function<int(int, int)> func2 = Functor();
//	cout << func2(1, 2) << endl;
//
//	//3����װlambda���ʽ
//	function<int(int, int)> func3 = [](int a, int b) {return a + b; };
//	cout << func3(1, 2) << endl;
//
//	//4����ľ�̬��Ա����
//	//function<int(int, int)> func4 = Plus::plusi;
//	function<int(int, int)> func4 = &Plus::plusi; //&��ʡ��
//	cout << func4(1, 2) << endl;
//
//	//5����ķǾ�̬��Ա����
//	function<double(Plus, double, double)> func5 = &Plus::plusd; //&����ʡ��
//	cout << func5(Plus(), 1.1, 2.2) << endl;
//	return 0;
//}
//
template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count: " << ++count << endl;
	cout << "count: " << &count << endl;

	return f(x);
}
double f(double i)
{
	return i / 2;
}
struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};
//int main()
//{
//	//����ָ��
//	cout << useF(f, 11.11) << endl;
//
//	//�º���
//	cout << useF(Functor(), 11.11) << endl;
//
//	//lambda���ʽ
//	cout << useF([](double d)->double {return d / 4; }, 11.11) << endl;
//	return 0;
//}
//int main()
//{
//	//������
//	function<double(double)> func1 = f;
//	cout << useF(func1, 11.11) << endl;
//
//	//��������
//	function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//
//	//lambda���ʽ
//	function<double(double)> func3 = [](double d)->double {return d / 4; };
//	cout << useF(func3, 11.11) << endl;
//	return 0;
//}
//int Plus(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	//������İ�
//	function<int(int)> func = bind(Plus, placeholders::_1, 10);
//	cout << func(1) << endl; //3
//	return 0;
//}
class Sub
{
public:
	int sub(int a, int b)
	{
		return a - b;
	}
};
int main()
{
	//�󶨹̶�����
	function<int(int, int)> func = bind(&Sub::sub, Sub(), placeholders::_1, placeholders::_2);
	cout << func(1, 2) << endl; //-1
	return 0;
}
