
#define _CRT_SECURE_NO_WARNINGS 1//��һ����Ϊscanf�ӵģ���scanf��Ҫ������һ��
#define _CRT_SECURE_NO_WARNINGS 1//��һ����Ϊscanf�ӵģ���scanf��Ҫ������һ��
#include <stdio.h>
int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	if (a > b) {
		c = b;
	}
	else 
	{ 
		c = a;
	}
	for (int i = c; i > 1; i--)
	{
		if (a % i == 0 && b % i == 0) {
			printf("%d", i);
			break;
		}
	}

	return 0;
}