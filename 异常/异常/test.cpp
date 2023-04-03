//#include<iostream>
//#include <time.h>
//#include <string>
//#include <windows.h>
//using namespace std;
////
//////double Division(int a, int b)
//////{
//////	if (b == 0)
//////		throw "抛异常";
//////	else
//////		return ((double)a / (double)b);
//////}
//////void Func()
//////{
//////	try
//////	{
//////		int len, time;
//////		cin >> len >> time;
//////		cout << Division(len, time) << endl;
//////	}
//////	catch(const char* errmsg)
//////	{
//////		cout << errmsg << endl;
//////	}
//////
//////}
//////int main()
//////{
//////	/*Func();*/
//////
//////	try
//////	{
//////		Func();
//////	}
//////	catch (const char* errmsg)
//////	{
//////		cout << errmsg << endl;
//////	}
//////
//////}
////
////double Division(int a, int b)
////{
////	if (b == 0)
////		throw "抛异常";
////	else
////		return ((double)a / (double)b);
////}
////
////int main()
////{
////	try
////	{
////		srand(time(0));
////		size_t N = 10000;
////		for (size_t i = 0; i < N; ++i)
////		{
////			Func();
////		}
////	}
////	catch (...)//捕获没有匹配的任意类型异常
////	{
////		cout << "未知异常" << endl;
////	}
////	return 0;
////}
////void func1()
////{
////	throw string("这是一个异常");
////}
////void func2()
////{
////	func1();
////}
////void func3()
////{
////	func2();
////}
////int main()
////{
////	try
////	{
////		func3();
////	}
////	catch (const string& s)
////	{
////		cout << "错误描述：" << s << endl;
////	}
////	catch (...)
////	{
////		cout << "未知异常" << endl;
////	}
////	return 0;
////}
////void func1()
////{
////	throw string("这是一个异常");
////}
////void func2()
////{
////	int* array = new int[10];
////	try
////	{
////		func1();
////
////	}
////	//do something...
////	catch (...)
////	{
////		delete[] array;
////		throw;//将捕获的异常重新抛出
////	}
////	delete[] array;
////}
////int main()
////{
////	try
////	{
////		func2();
////	}
////	catch (const string& s)
////	{
////		cout << s << endl;
////	}
////	catch (...)
////	{
////		cout << "未知异常" << endl;
////	}
////	return 0;
////}
//
////double Division(int a, int b)
////{
////	// 当b == 0时抛出异常
////	if (b == 0)
////		throw "Division by zero condition!";
////	else
////		return ((double)a / (double)b);
////}
////size_t x = 0;
////void Probability()
////{
////
////	int val = rand();
////	if (val < RAND_MAX / 4)//产生%25的随机数
////	{
////		string str("25%概率抛异常->");
////		str += to_string(val);
////		throw str;
////	}
////	else
////	{
////		cout << val << endl;
////	}
////}
////void Func()
////{
////	try
////	{
////		Probability();
////
////	}
////	catch (const string& s)
////	{
////		++x;
////		cout << s << endl;
////	}
////
////}
////int main()
////{
////	try
////	{
////		srand(time(0));
////		size_t N = 10000;
////		for (size_t i = 0; i < N; ++i)
////		{
////			Func();
////		}
////		cout << "抛异常的次数" << x << endl;
////		cout << "抛异常的概率" << (double)x / (double)N << endl;
////	}
////
////	catch(...)
////	{
////		cout << "未知异常" << endl;
////	}
////	return 0;
////}
//int main()
//{
//	try
//	{
//		size_t i = 0;
//		while (1)
//		{
//			int* myarray = new int[1024*1024];
//			cout << myarray <<"->"<<i++<<endl;
//		}
//	}
//	catch (const exception& ba)
//	{
//		std::cerr << "bad_alloc caught: " << ba.what() << '\n';
//	}
//
//	return 0;
//}
