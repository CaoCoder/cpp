#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
void fun(char* s, char* t1, char* t2, char* w)
{
	char* p, * r, * a;
	strcpy(w, s);
	//��ʼ׼���滻
	while (*w)
	{
		p = w;
		r = t1;
		while (*r)//����1,����r��һ��ָ�����������洢���ǵ�ַ��
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
		//��ʼ�滻
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
	cout << "������s�ַ���";
	cin.getline(s, 100);
	cout << "�������Ӵ�1";
	cin.getline(t1, 100);
	cout << "�������Ӵ�2";
	cin.getline(t2, 100);
	if (strlen(t1) == strlen(t2))
	{
		fun(s, t1, t2, w);
		cout << "�����" << w;
	}
	else
	{
		cout << "t1���Ȳ�����t2" << endl;
	}
}