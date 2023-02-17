//#define _CRT_SECURE_NO_WARNINGS 1
//#include "student.h"
//
//#include <string.h>
//void menu()
//{
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.管理员界面：123****\n");
//	printf("******2.老师界面： 1234****\n");
//	printf("******3.学生界面：12345****\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("请选择(1-3):");
//}
//
//void AdminMenu()
//{
//	printf("*****欢迎来到管理员界面****\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.添加学生信息   ****\n");
//	printf("******2.修改学生信息   ****\n");
//	printf("******3.删除学生信息   ****\n");
//	printf("******4.查询学生信息   ****\n");
//	printf("******5.显示学生信息   ****\n");
//	printf("******6.返        回   ****\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("请选择(1-6):");
//
//}
//
//void Admin(Node* phead)
//{
//	stu st = { "张三",1,1,1,1,1 };
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
//			printf("输入格式错误请重新输入\n");
//			break;
//		}
//	} while (n);
//}
//void TeacherMenu()
//{
//	printf("*****欢迎来到老师界面******\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.查看学生信息   ****\n");
//	printf("******2.修改学生成绩   ****\n");
//	printf("******3.查看成绩情况   ****\n");
//	printf("******4.返回主菜单     ****\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("请选择(1-4):");
//
//}
//
//void Teacher(Node* phead)
//{
//	stu st = { "张三",1,1,1,1,1 };
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
//			printf("输入格式错误请重新输入\n");
//			break;
//		}
//	} while (n);
//}
//
//void StudentMenu()
//{
//	printf("*****欢迎来到学生界面******\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.查询成绩       ****\n");
//	printf("******2.返回主菜单     ****\n");
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("请选择(1-2):");
//
//}
//void Student(Node* phead)
//{
//	stu st = { "张三",1,1,1,1,1 };
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
//			printf("输入格式错误请重新输入\n");
//			break;
//		}
//	} while (n);
//}
//int main()
//{
//	//test();//链接mysql
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
//			printf("请输入密码：");
//			scanf("%s", a);
//			if (strcmp(ma, a) == 0)
//			{
//				Admin(phead);
//			}
//			else
//			{
//				printf("密码输入错误请重新输入\n");
//			}
//			break;
//		case 2:
//			printf("请输入密码：");
//			scanf("%s", b);
//			if (strcmp(mb, b) == 0)
//			{
//				Teacher(phead);
//			}
//			else
//			{
//				printf("密码输入错误请重新输入\n");
//			}
//
//			break;
//		case 3:
//			printf("请输入密码：");
//			scanf("%s", c);
//			if (strcmp(mc, c) == 0)
//			{
//				Student(phead);
//			}
//			else
//			{
//				printf("密码输入错误请重新输入\n");
//			}
//
//			break;
//
//		default:
//			printf("输入格式错误请重新输入\n");
//			break;
//		}
//	} while (n);
//	return 0;
//}
//
