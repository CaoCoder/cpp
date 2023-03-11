#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

int main()
{
	char p[] = { 'a', 'b', 'c' };
	char q[10] = { 'a', 'b', 'c' };
	cout << strlen(p) << endl;
	cout << strlen(q);
	return 0;
}
