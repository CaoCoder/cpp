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
		{"�л���ѧ",-1,{1,2}},
		{"�����ѧԺ",0,{3,4,5}},
		{"����ѧԺ",0,{6,7}},
		{"�������ѧ",1,{8,9,10}},
		{"��Ϣ��ȫ",1,{11,12}},
		{"������",1,{13}},
		{"�ƿ�1��",3,{14}},
		{"�ƿ�2��",3,{15}},
		{"�ƿ�3��",3,{16}},
		{"�Ű�1��",4,{17}},
		{"�Ű�2��",4,{18}},
		{"������",5,{19}},
		{"������Ϣ��",2,{20,21,22}},
		{"��Ϣ����",2,{23,24}},
		{"����1��",6,{25}},
		{"����2��",6,{26}},
		{"����3��",6,{27}},
		{"��Ϣ1��",7,{28}},
		{"��Ϣ2��",7,{29}},
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
	