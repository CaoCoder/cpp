//#define _CRT_SECURE_NO_WARNINGS 1
//
//
//#include "student.h"
//
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
//}
//
//void AdminMenu()
//{
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.����ѧ������   ****\n");
//	printf("******2.ɾ��ѧ������   ****\n");
//	printf("******3.����ѧ������   ****\n");
//	printf("******4.�������˵�     ****\n");
//	printf("******5.�鿴ѧ������   ****\n");
//	printf("***************************\n");
//	printf("***************************\n");
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
//			Erease(phead, Find(phead));
//			break;
//		case 3:
//			Find(phead);
//			break;
//		case 4:
//			return;
//			break;
//		case 5:
//			ListPrint(phead);
//			break;
//		default:
//			printf("�����ʽ��������������:");
//			break;
//		}
//	} while (n);
//}
//void TeacherMenu()
//{
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.����ѧ������   ****\n");
//	printf("******2.����ѧ������   ****\n");
//	printf("******3.�޸ĳɼ�       ****\n");
//	printf("******4.�������˵�     ****\n");
//	printf("******5.ͳ��ƽ���ֺ��ܷ�***\n");
//	printf("***************************\n");
//	printf("***************************\n");
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
//			ListPrint(phead);
//			break;
//		case 2:
//			Find(phead);
//			break;
//		case 3:
//			Modify(phead, Find(phead));
//			break;
//		case 4:
//			return;
//			break;
//		case 5:
//			cal(phead);
//			break;
//		default:
//			printf("�����ʽ��������������:");
//			break;
//		}
//	} while (n);
//}
//
//void StudentMenu()
//{
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.��ѯ�ɼ�       ****\n");
//	printf("******2.�������˵�     ****\n");
//	printf("***************************\n");
//	printf("***************************\n");
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
//			printf("�����ʽ��������������:");
//			break;
//		}
//	} while (n);
//}
//int main()
//{
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
//		}
//	} while (n);
//	return 0;
//}

#include <iostream>
using namespace std;
#include <WinSock.h>
#include <mysql.h>
void test();
int main()
{
	cout << "main" << endl;

	test();
	getchar();
	return 0;
}

void test()
{
	printf("test\n");

	MYSQL m;        //mysql����
	MYSQL_RES* res; //��ѯ�����
	MYSQL_ROW row;  //��ά���飬�������

	//��ʼ�����ݿ�
	mysql_init(&m);

	//���ñ��뷽ʽ
	mysql_options(&m, MYSQL_SET_CHARSET_NAME, "gbk");

	//�������ݿ�
	if (mysql_real_connect(&m, "localhost", "root", "yigebeiju123", "c", 3306, NULL, 0))
	{                           //����       �û���   ����      ���ݿ���  �˿�
		printf("���ݿ����ӳɹ�\n");
	}
	else {
		printf("���ݿ�����ʧ��:%s \n", mysql_error(&m));
		//���������Ϣ
	}

	//�����ݿ��������
	const char* sql = "insert into student values(1,'����','��')";
	if (mysql_query(&m, sql))
	{
		printf("��������ʧ�ܣ�%s \n", mysql_error(&m));
	}
	else
	{
		printf("�������ݳɹ�\n");
	}


	////�����ݿ�ɾ������
	//const char* sql_2 = "delete from student where name = '����'";
	//if (mysql_query(&m, sql_2))
	//{
	//	printf("ɾ������ʧ�ܣ�%s \n", mysql_error(&m));
	//}
	//else
	//{
	//	printf("ɾ�����ݳɹ�\n");
	//}


	////�����ݿ��޸�����
	//const char* sql_3 = "update student set id = 5 where name = '����'";
	//if (mysql_query(&m, sql_3))
	//{
	//	printf("�޸�����ʧ�ܣ�%s \n", mysql_error(&m));
	//}
	//else
	//{
	//	printf("�޸����ݳɹ�\n");
	//}
	

}
	
