#include <iostream>
using namespace std;

int main()
{
	//int s[3][4] = { {1,2,3},{4,5,6},{7,8,9} };
	//int(*p)[4];
	//p = s;
	//cout << *(p + 1) << endl;
	//cout << p;

	int a = 10;
	int* p = &a;//一级指针,p里面存储的是整型变量a的地址。

	int** pp = &p;//二级指针,pp里面存储的是指针变量p的地址。

	cout << *p << endl;//通过p可以访问到a。
	cout << *pp << endl;//通过*pp可以拿到p。
	return 0;
}