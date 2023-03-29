
#define _CRT_SECURE_NO_WARNINGS 1//这一行是为scanf加的，用scanf都要加上这一行
#define _CRT_SECURE_NO_WARNINGS 1//这一行是为scanf加的，用scanf都要加上这一行
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