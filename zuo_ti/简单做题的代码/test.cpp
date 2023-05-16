//#include <iostream>
#include <string>
#include<stdio.h>
//#include <stdlib.h>
//using namespace std;
#define max 100
typedef struct tnode
{
	char name[max];
	int parent;
	int son[3];

}BT;

int main()
{
	BT data[max];
	data[0] = { "中华", -1, {1, 3} };

}