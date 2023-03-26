#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>

double Sign(double x);
double Sign(double x)
{
	if (x > 0)
		return 1;
	else if (x == 0)
		return 0;
	else
		return -1;
}

int main()
{
	double a = 0;
	scanf("%f", &a);
	int b = Sign(a);
	printf("%d", b);
}
