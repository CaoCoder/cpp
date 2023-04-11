#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
int func(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);
	}
	return count;
}
int main() {
	
	printf("%d", func(9999));
	return 0;
}


//babc  daa
//0010011100001111
//0010011100001110
//0 1 2 3 4 5 6 7 8 9
//1 1 2 3 4 5 6 7 8 9
//2 1 2 3 4 5 6 7 8 9
//3 1 2 3 4 5 6 7 8 9
//4 1 2 3 4 5 6 7 8 9
//5 1 2 3 4 5 6 7 8 9
//6 1 2 3 4 5 6 7 8 9
//7 1 2 3 4 5 6 7 8 9
//8 1 2 3 4 5 6 7 8 9
//9 1 2 3 4 5 6 7 8 9


