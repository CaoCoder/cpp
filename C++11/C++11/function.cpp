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
//	//1、包装函数指针（函数名）
//	function<int(int, int)> func1 = f;
//	cout << func1(1, 2) << endl;
//
//	//2、包装仿函数（函数对象）
//	function<int(int, int)> func2 = Functor();
//	cout << func2(1, 2) << endl;
//
//	//3、包装lambda表达式
//	function<int(int, int)> func3 = [](int a, int b) {return a + b; };
//	cout << func3(1, 2) << endl;
//
//	//4、类的静态成员函数
//	//function<int(int, int)> func4 = Plus::plusi;
//	function<int(int, int)> func4 = &Plus::plusi; //&可省略
//	cout << func4(1, 2) << endl;
//
//	//5、类的非静态成员函数
//	function<double(Plus, double, double)> func5 = &Plus::plusd; //&不可省略
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
//	//函数指针
//	cout << useF(f, 11.11) << endl;
//
//	//仿函数
//	cout << useF(Functor(), 11.11) << endl;
//
//	//lambda表达式
//	cout << useF([](double d)->double {return d / 4; }, 11.11) << endl;
//	return 0;
//}
//int main()
//{
//	//函数名
//	function<double(double)> func1 = f;
//	cout << useF(func1, 11.11) << endl;
//
//	//函数对象
//	function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//
//	//lambda表达式
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
//	//无意义的绑定
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
	//绑定固定参数
	function<int(int, int)> func = bind(&Sub::sub, Sub(), placeholders::_1, placeholders::_2);
	cout << func(1, 2) << endl; //-1
	return 0;
}
