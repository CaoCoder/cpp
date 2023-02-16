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
//	printf("******1.教务员界面：123****\n");
//	printf("******2.老师界面： 1234****\n");
//	printf("******3.学生界面：12345****\n");
//	printf("***************************\n");
//	printf("***************************\n");
//}
//
//void AdminMenu()
//{
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.增加学生档案   ****\n");
//	printf("******2.删除学生档案   ****\n");
//	printf("******3.查找学生档案   ****\n");
//	printf("******4.返回主菜单     ****\n");
//	printf("******5.查看学生档案   ****\n");
//	printf("***************************\n");
//	printf("***************************\n");
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
//			printf("输入格式错误请重新输入:");
//			break;
//		}
//	} while (n);
//}
//void TeacherMenu()
//{
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.访问学生档案   ****\n");
//	printf("******2.查找学生档案   ****\n");
//	printf("******3.修改成绩       ****\n");
//	printf("******4.返回主菜单     ****\n");
//	printf("******5.统计平均分和总分***\n");
//	printf("***************************\n");
//	printf("***************************\n");
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
//			printf("输入格式错误请重新输入:");
//			break;
//		}
//	} while (n);
//}
//
//void StudentMenu()
//{
//	printf("***************************\n");
//	printf("***************************\n");
//	printf("******1.查询成绩       ****\n");
//	printf("******2.返回主菜单     ****\n");
//	printf("***************************\n");
//	printf("***************************\n");
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
//			printf("输入格式错误请重新输入:");
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

	MYSQL m;        //mysql连接
	MYSQL_RES* res; //查询结果集
	MYSQL_ROW row;  //二维数组，存放数据

	//初始化数据库
	mysql_init(&m);

	//设置编码方式
	mysql_options(&m, MYSQL_SET_CHARSET_NAME, "gbk");

	//连接数据库
	if (mysql_real_connect(&m, "localhost", "root", "yigebeiju123", "c", 3306, NULL, 0))
	{                           //主机       用户名   密码      数据库名  端口
		printf("数据库连接成功\n");
	}
	else {
		printf("数据库连接失败:%s \n", mysql_error(&m));
		//输出错误信息
	}

	//向数据库插入数据
	const char* sql = "insert into student values(1,'张三','男')";
	if (mysql_query(&m, sql))
	{
		printf("插入数据失败：%s \n", mysql_error(&m));
	}
	else
	{
		printf("插入数据成功\n");
	}


	////向数据库删除数据
	//const char* sql_2 = "delete from student where name = '赵六'";
	//if (mysql_query(&m, sql_2))
	//{
	//	printf("删除数据失败：%s \n", mysql_error(&m));
	//}
	//else
	//{
	//	printf("删除数据成功\n");
	//}


	////向数据库修改数据
	//const char* sql_3 = "update student set id = 5 where name = '李四'";
	//if (mysql_query(&m, sql_3))
	//{
	//	printf("修改数据失败：%s \n", mysql_error(&m));
	//}
	//else
	//{
	//	printf("修改数据成功\n");
	//}
	

}
	
