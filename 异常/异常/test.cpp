//#include<iostream>
//#include <time.h>
//#include <string>
//#include <windows.h>
//using namespace std;
////
//////double Division(int a, int b)
//////{
//////	if (b == 0)
//////		throw "���쳣";
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
////		throw "���쳣";
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
////	catch (...)//����û��ƥ������������쳣
////	{
////		cout << "δ֪�쳣" << endl;
////	}
////	return 0;
////}
////void func1()
////{
////	throw string("����һ���쳣");
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
////		cout << "����������" << s << endl;
////	}
////	catch (...)
////	{
////		cout << "δ֪�쳣" << endl;
////	}
////	return 0;
////}
////void func1()
////{
////	throw string("����һ���쳣");
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
////		throw;//��������쳣�����׳�
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
////		cout << "δ֪�쳣" << endl;
////	}
////	return 0;
////}
//
////double Division(int a, int b)
////{
////	// ��b == 0ʱ�׳��쳣
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
////	if (val < RAND_MAX / 4)//����%25�������
////	{
////		string str("25%�������쳣->");
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
////		cout << "���쳣�Ĵ���" << x << endl;
////		cout << "���쳣�ĸ���" << (double)x / (double)N << endl;
////	}
////
////	catch(...)
////	{
////		cout << "δ֪�쳣" << endl;
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
