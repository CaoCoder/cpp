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
	int* p = &a;//һ��ָ��,p����洢�������ͱ���a�ĵ�ַ��

	int** pp = &p;//����ָ��,pp����洢����ָ�����p�ĵ�ַ��

	cout << *p << endl;//ͨ��p���Է��ʵ�a��
	cout << *pp << endl;//ͨ��*pp�����õ�p��
	return 0;
}