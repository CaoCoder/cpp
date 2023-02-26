#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
void fun(char* s, char* t1, char* t2, char* w)
{
	char* p, * r, * a;
	strcpy(w, s);
	//开始准备替换
	while (*w)
	{
		p = w;
		r = t1;
		while (*r)//错误1,在于r是一个指针变量，里面存储的是地址。
		{
			if (*r == *p)
			{
				r++;
				p++;
			}
			else
			{
				break;
			}
		}
		//开始替换
		if (*r == '\0')
		{
			a = w;
			r = t2;
			while (*r)
			{
				*a = *r;
				a++;
				r++;
			}
			w += strlen(t2);
		}
		else
			w++;
	}

}
int main()
{
	char s[100], t1[100], t2[100], w[100];
	cout << "请输入s字符串";
	cin.getline(s, 100);
	cout << "请输入子串1";
	cin.getline(t1, 100);
	cout << "请输入子串2";
	cin.getline(t2, 100);
	if (strlen(t1) == strlen(t2))
	{
		fun(s, t1, t2, w);
		cout << "结果是" << w;
	}
	else
	{
		cout << "t1长度不等于t2" << endl;
	}
}