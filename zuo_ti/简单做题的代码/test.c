//#include <iostream>
#include <string>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct tnode {
	char name[max];
	int parent;
	int son[3];
}BT;
void print(BT* T);
void print(BT* T) {
	for (int i = 0; i < 28; i++)
	{
		if (T != NULL)
		{
			printf("%s", T->name[i]);

		}
	}
}
	int main() {
		BT data[max] = {
		{"中华大学",-1,{1,2}},
		{"计算机学院",0,{3,4,5}},
		{"电信学院",0,{6,7}},
		{"计算机科学",1,{8,9,10}},
		{"信息安全",1,{11,12}},
		{"物联网",1,{13}},
		{"计科1班",3,{14}},
		{"计科2班",3,{15}},
		{"计科3班",3,{16}},
		{"信安1班",4,{17}},
		{"信安2班",4,{18}},
		{"物联班",5,{19}},
		{"电子信息类",2,{20,21,22}},
		{"信息工程",2,{23,24}},
		{"电信1班",6,{25}},
		{"电信2班",6,{26}},
		{"电信3班",6,{27}},
		{"信息1班",7,{28}},
		{"信息2班",7,{29}},
		{"32",8,{NULL}},
		{"35",9,{NULL}},
		{"33",10,{NULL}},
		{"36",11,{NULL}},
		{"38",12,{NULL}},
		{"38",13,{NULL}},
		{"40",20,{NULL}},
		{"38",21,{NULL}},
		{"42",22,{NULL}},
		{"38",23,{NULL}},
		{"35",24,{NULL}},
		};
		print(data);

	}
	