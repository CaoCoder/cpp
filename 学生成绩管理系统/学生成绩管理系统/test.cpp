//#define _CRT_SECURE_NO_WARNINGS 1
//#include "student.h"
//
//#include <string.h>
//void menu()
//{
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.����Ա���棺123****\n");
//	printf("******2.��ʦ���棺 1234****\n");
//	printf("******3.ѧ�����棺12345****\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("��ѡ��(1-3):");
//}
//
//void AdminMenu()
//{
//	printf("*****��ӭ��������Ա����****\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.���ѧ����Ϣ   ****\n");
//	printf("******2.�޸�ѧ����Ϣ   ****\n");
//	printf("******3.ɾ��ѧ����Ϣ   ****\n");
//	printf("******4.��ѯѧ����Ϣ   ****\n");
//	printf("******5.��ʾѧ����Ϣ   ****\n");
//	printf("******6.��        ��   ****\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("��ѡ��(1-6):");
//
//}
//
//void Admin(Node* phead)
//{
//	stu st = { "����",1,1,1,1,1 };
//	int n = 0;
//	do
//	{
//		AdminMenu();
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1:
//			push_back(phead, st);
//			break;
//		case 2:
//			Modify(phead, Find(phead));
//			break;
//		case 3:
//			Erease(phead, Find(phead));
//			break;
//		case 4:
//			Find(phead);
//			break;
//		case 5:
//			ListPrint(phead);
//			break;
//		case 6:
//			return;
//			break;
//		default:
//			printf("�����ʽ��������������\n");
//			break;
//		}
//	} while (n);
//}
//void TeacherMenu()
//{
//	printf("*****��ӭ������ʦ����******\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.�鿴ѧ����Ϣ   ****\n");
//	printf("******2.�޸�ѧ���ɼ�   ****\n");
//	printf("******3.�鿴�ɼ����   ****\n");
//	printf("******4.�������˵�     ****\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("��ѡ��(1-4):");
//
//}
//
//void Teacher(Node* phead)
//{
//	stu st = { "����",1,1,1,1,1 };
//	int n = 0;
//	do
//	{
//		TeacherMenu();
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1:
//			Find(phead);
//			break;
//		case 2:
//			Modify(phead, Find(phead));
//			break;
//		case 3:
//			ListPrint(phead);
//			break;
//		case 4:
//			return;
//			break;
//		default:
//			printf("�����ʽ��������������\n");
//			break;
//		}
//	} while (n);
//}
//
//void StudentMenu()
//{
//	printf("*****��ӭ����ѧ������******\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.��ѯ�ɼ�       ****\n");
//	printf("******2.�������˵�     ****\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("��ѡ��(1-2):");
//
//}
//void Student(Node* phead)
//{
//	stu st = { "����",1,1,1,1,1 };
//	int n = 0;
//	do
//	{
//		StudentMenu();
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1:
//			ListPrint(phead);
//			break;
//		case 2:
//			return;
//			break;
//		default:
//			printf("�����ʽ��������������\n");
//			break;
//		}
//	} while (n);
//}
//int main()
//{
//	//test();//����mysql
//	
//	int n = 0;
//	Node* phead = NULL;
//	ListNodeInit(&phead);
//	const char* ma = "123";
//	const char* mb = "1234";
//	const char* mc = "12345";
//	char a[20];
//	char b[20];
//	char c[20];
//	do
//	{
//		menu();
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1:
//			printf("���������룺");
//			scanf("%s", a);
//			if (strcmp(ma, a) == 0)
//			{
//				Admin(phead);
//			}
//			else
//			{
//				printf("���������������������\n");
//			}
//			break;
//		case 2:
//			printf("���������룺");
//			scanf("%s", b);
//			if (strcmp(mb, b) == 0)
//			{
//				Teacher(phead);
//			}
//			else
//			{
//				printf("���������������������\n");
//			}
//
//			break;
//		case 3:
//			printf("���������룺");
//			scanf("%s", c);
//			if (strcmp(mc, c) == 0)
//			{
//				Student(phead);
//			}
//			else
//			{
//				printf("���������������������\n");
//			}
//
//			break;
//
//		default:
//			printf("�����ʽ��������������\n");
//			break;
//		}
//	} while (n);
//	return 0;
//}
//
