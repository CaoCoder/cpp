#define _CRT_SECURE_NO_WARNINGS 1
#pragma once//防止头文件被包含
#include <iostream>
using namespace std;

#include <WinSock.h>
#include <mysql.h>
//将注册的账号密码写入文件
void WriteCode(int a,int b, int c)
{
    //打开文件
    FILE* pf = fopen("code.txt", "w");
    if (pf == NULL)
    {
        printf("保存失败\n");
        return;
    }
    //向文件传输数据
    int id = a, nummber =b , code = c;
        fprintf(pf, "%d %d %d\n", id, nummber, code);
    
    //关闭文件
    fclose(pf);
    pf = NULL;
    //printf("写入文件成功\n");
}
//将注册的账号密码写入数据库
int WriteCodeMysql()
{
    MYSQL* conn;
    MYSQL_STMT* stmt;
    const char* query;
    const char* filename = "code.txt";
    FILE* fp;
    int id,nummber,code;
    // 打开文件
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
    // 连接数据库
    conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Error connecting to database!\n");
        return -1;
    }
    if (mysql_real_connect(conn, "localhost", "root", "721229", "test", 3306, NULL, 0) == NULL)
    {
        printf("Error connecting to database!\n");
        return -1;
    }
    else
    {

        /*printf("链接成功\n")*/;
    }

    // 先清空数据库
    query = "DELETE FROM Code";
    mysql_query(conn, query);
    // 读取文件中的数据
    while (fscanf(fp, "%d%d%d",
        &id,&nummber,&code) != EOF)
    {
        // 构造插入语句
        query = "INSERT INTO Code (id, nummber, code) VALUES (?,?, ?)";
        // 准备插入语句
        stmt = mysql_stmt_init(conn);
        if (mysql_stmt_prepare(stmt, query, strlen(query)) != 0) {
            printf("Error preparing statement!\n");
            return -1;
        }
        // 执行插入语句
        MYSQL_BIND bind[3];
        memset(bind, 0, sizeof(bind));
        

        bind[0].buffer_type = MYSQL_TYPE_LONG;
        bind[0].buffer = &id;
        bind[1].buffer_type = MYSQL_TYPE_LONG;
        bind[1].buffer = &nummber;
        bind[2].buffer_type = MYSQL_TYPE_LONG;
        bind[2].buffer = &code;
      
        mysql_stmt_bind_param(stmt, bind);
        mysql_stmt_execute(stmt);
    }
    // 关闭文件
    fclose(fp);
    // 关闭数据库连接
    mysql_close(conn);

}
/*向数据库中写入文件*/
int WriteMysql()
{
    MYSQL* conn;
    MYSQL_STMT* stmt;
    const char* query;
    const char* filename = "data.txt";
    FILE* fp;
    char name[20];
    int id, clas, math, english, physics;
    // 打开文件
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
    // 连接数据库
    conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Error connecting to database!\n");
        return -1;
    }
    if (mysql_real_connect(conn, "localhost", "root", "721229", "test", 3306, NULL, 0) == NULL)
    {
        printf("Error connecting to database!\n");
        return -1;
    }
    else
    {

        /*printf("链接成功\n")*/;
    }

    // 先清空数据库
    query = "DELETE FROM student";
    mysql_query(conn, query);
    // 读取文件中的数据
    while (fscanf(fp, "%s%d%d%d%d%d",
        name, &id, &clas, &math, &english, &physics) != EOF)
    {
        // 构造插入语句
        query = "INSERT INTO student (name, id, clas, math, english, physics) VALUES (?,?, ?, ?, ?,?)";
        // 准备插入语句
        stmt = mysql_stmt_init(conn);
        if (mysql_stmt_prepare(stmt, query, strlen(query)) != 0) {
            printf("Error preparing statement!\n");
            return -1;
        }
        // 执行插入语句
        MYSQL_BIND bind[6];
        memset(bind, 0, sizeof(bind));
        bind[0].buffer_type = MYSQL_TYPE_STRING;
        bind[0].buffer = (char*)name;
        bind[0].buffer_length = strlen(name);

        bind[1].buffer_type = MYSQL_TYPE_LONG;
        bind[1].buffer = &id;
        bind[2].buffer_type = MYSQL_TYPE_LONG;
        bind[2].buffer = &clas;
        bind[3].buffer_type = MYSQL_TYPE_LONG;
        bind[3].buffer = &math;
        bind[4].buffer_type = MYSQL_TYPE_LONG;
        bind[4].buffer = &english;
        bind[5].buffer_type = MYSQL_TYPE_LONG;
        bind[5].buffer = &physics;

        mysql_stmt_bind_param(stmt, bind);
        mysql_stmt_execute(stmt);
    }
    // 关闭文件
    fclose(fp);
    // 关闭数据库连接
    mysql_close(conn);

}
/*从数据库中读取文件*/
int ReadMysql()
{
    MYSQL* conn;
    MYSQL_STMT* stmt;
    const char* query;
    const char* filename = "data.txt";
    FILE* fp;
    char name[20];
    int id, clas, math, english, physics;
    // 打开文件
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
    // 连接数据库
    conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Error connecting to database!\n");
        return -1;
    }
    if (mysql_real_connect(conn, "localhost", "root", "721229", "test", 3306, NULL, 0) == NULL)
    {
        printf("Error connecting to database!\n");
        return -1;
    }
    else
    {
        /*printf("链接成功\n")*/;
    }
    // 构造查询语句
    query = "SELECT name, id, clas, math, english, physics FROM student";
    // 准备查询语句
    stmt = mysql_stmt_init(conn);
    if (mysql_stmt_prepare(stmt, query, strlen(query)) != 0) {
        printf("Error preparing statement!\n");
        return -1;
    }
    // 执行查询语句
    MYSQL_BIND bind[6];
    memset(bind, 0, sizeof(bind));
    bind[0].buffer_type = MYSQL_TYPE_STRING;
    bind[0].buffer = (char*)name;
    bind[0].buffer_length = strlen(name);
    bind[1].buffer_type = MYSQL_TYPE_LONG;
    bind[1].buffer = &id;
    bind[2].buffer_type = MYSQL_TYPE_LONG;
    bind[2].buffer = &clas;
    bind[3].buffer_type = MYSQL_TYPE_LONG;
    bind[3].buffer = &math;
    bind[4].buffer_type = MYSQL_TYPE_LONG;
    bind[4].buffer = &english;
    bind[5].buffer_type = MYSQL_TYPE_LONG;
    bind[5].buffer = &physics;
    mysql_stmt_bind_result(stmt, bind);
    mysql_stmt_execute(stmt);
    // 读取查询结果
    while (mysql_stmt_fetch(stmt) == 0) {
        fprintf(fp, "%s %d %d %d %d %d\n",
            name, id, clas, math, english, physics);
    }
    // 关闭文件
    fclose(fp);
    // 关闭数据库连接
    mysql_close(conn);
}

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
//各科成绩
typedef struct Score
{
    int math;
    int english;
    int physics;
}score;

//学生信息
typedef struct student
{
    char name[20];
    int id;
    int clas;
    score s;//成绩
}stu;
//初始化结构体数据

//定义双向链表结构
typedef stu ListDataType;

typedef struct ListNode
{
    struct ListNode* prev;
    struct ListNode* next;
    ListDataType val;
}Node;

//将学生信息等数据写入到文件data.txt中
void WriteData(Node* phead)
{
    //打开文件
    FILE* pf = fopen("data.txt", "w");
    if (pf == NULL)
    {
        printf("保存失败\n");
        return;
    }
    //向文件传输数据
    Node* cur = phead->next;
   
    while (cur != phead)
    {
        fprintf(pf, "%s %d %d %d %d %d\n", cur->val.name, cur->val.id, cur->val.clas,
            cur->val.s.math, cur->val.s.english, cur->val.s.physics);

        cur = cur->next;
    }

    //关闭文件
    fclose(pf);
    pf = NULL;
    //printf("写入文件成功\n");
}

Node* BuyNode(ListDataType x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("开辟失败");
        exit(-1);
    }

    //初始化节点数据
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;//返回节点
}
//从文件中读出数据到程序中
void ReadData(Node* phead)
{
    ReadMysql();
    stu st = { "张三",1,1,1,1,1 };
    //打开文件
    FILE* pf = fopen("data.txt", "r");
    if (pf == NULL)
    {
        printf("%s\n", strerror(errno));
        return;//文件打开失败，失败返回
    }

    Node* newNode = BuyNode(st);

    //对文件进行格式化读取
    Node* tail = phead->prev;
   
    while (fscanf(pf, "%s %d %d %d %d %d\n", newNode->val.name, &newNode->val.id, &newNode->val.clas,
        &newNode->val.s.math, &newNode->val.s.english, &newNode->val.s.physics) != EOF)
    {


        //phead==tail ->newNode 


        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = phead;
        phead->prev = newNode;

        tail = phead->prev;

        newNode = BuyNode(st);
    }


    //关闭文件
    fclose(pf);
    pf = NULL;
    printf("读取数据完成\n");
}
//初始化信息
void InitStu(Node** x)
{

    printf("请输入相关信息：\n");
    printf("请输入姓名：");
    scanf("%s", &(*x)->val.name);
    printf("请输入学号：");

    scanf("%d", &(*x)->val.id);
    printf("请输入班级：");

    scanf("%d", &(*x)->val.clas);
    printf("请输入数学成绩：");

    scanf("%d", &(*x)->val.s.math);
    printf("请输入英语成绩：");

    scanf("%d", &(*x)->val.s.english);
    printf("请输入物理成绩：");

    scanf("%d", &(*x)->val.s.physics);

}
//申请节点空间
Node* BuynewNode(ListDataType x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("开辟失败");
        exit(-1);
    }

    //初始化节点数据
    newNode->next = NULL;
    newNode->prev = NULL;

    InitStu(&newNode);
    return newNode;//返回节点
}
Node* BuyInitNode(ListDataType x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("开辟失败");
        exit(-1);
    }

    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->val = x;

    return newNode;
}
//定义哨兵头结点
void ListNodeInit(Node** pphead)
{
    stu st = { "张三",1,1,1,1,1 };

    Node* newNode = BuyInitNode(st);
    *pphead = newNode;
    (*pphead)->next = *pphead;
    (*pphead)->prev = *pphead;
}

//尾插
void push_back(Node* phead, ListDataType x)
{
    assert(phead);
    Node* newNode = BuynewNode(x);
    Node* tail = phead->prev;

    //phead==tail ->newNode 
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = phead;
    phead->prev = newNode;

    WriteData(phead);

    WriteMysql();
    printf("增加信息成功\n");

}

void ListPrint(Node* phead)
{
    assert(phead);

    Node* cur = phead->next;
    printf("%-9s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "姓名", "学号", "班级", "数学", "英语", "物理");
    while (cur != phead)
    {

        printf("%-9s\t%-9d\t%-9d\t%-9d\t%-9d\t%-9d\n", cur->val.name, cur->val.id, cur->val.clas,
            cur->val.s.math, cur->val.s.english, cur->val.s.physics);

        cur = cur->next;
    }
    printf("\n\n");
}
//按照学号查找某人
Node* Find(Node* phead)
{
    assert(phead);
    int x = 0;
    printf("请输入要查找的学号：");
    scanf("%d", &x);
    Node* cur = phead->next;
    while (cur != phead)
    {
        if (cur->val.id == x)
        {
            printf("结果如下\n");
            printf("%-9s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "姓名", "学号", "班级", "数学", "英语", "物理");
            printf("%-9s\t%-9d\t%-9d\t%-9d\t%-9d\t%-9d\n", cur->val.name, cur->val.id, cur->val.clas,
                cur->val.s.math, cur->val.s.english, cur->val.s.physics);

            return cur;
        }

        cur = cur->next;
    }
    printf("查无此人或系统为空\n");
    return NULL;

}
//删除指定位置的节点
void Erease(Node* phead, Node* pos)
{
    if (pos == phead || pos == NULL)
    {
        printf("未找到该学生，无此id\n");
        return;
    }

    Node* posPrev = pos->prev;
    Node* posNext = pos->next;

    posPrev->next = posNext;
    posNext->prev = posPrev;

    free(pos);
    pos = NULL;

    WriteData(phead);

    WriteMysql();

    printf("删除成功\n");
}
//修改指定位置的节点的学生成绩
void Modify(Node* phead, Node* pos)
{
    if (pos == phead || pos == NULL)
    {
        printf("未找到该学生，无此id\n");
        return;
    }
    printf("请输入修改后的数学成绩：");

    scanf("%d", &pos->val.s.math);
    printf("请输入修改后的英语成绩：");

    scanf("%d", &pos->val.s.english);
    printf("请输入修改后的物理成绩：");

    scanf("%d", &pos->val.s.physics);


    WriteData(phead);


    WriteMysql();
    printf("修改成功\n");
}

void cal(Node* phead)
{
    int avmath = 0;
    int avenglish = 0;
    int avphysics = 0;
    Node* cur = phead->next;
    while (cur != phead)
    {

        printf("%s的总成绩是%d   \n", cur->val.name, (cur->val.s.math + cur->val.s.english + cur->val.s.physics));
        avmath += cur->val.s.math;
        avenglish += cur->val.s.english;
        avphysics += cur->val.s.physics;

        cur = cur->next;
    }

    printf("数学单科平均分是%d,英语单科平均分是%d,物理单科平均分是%d\n", avmath, avenglish, avphysics);
}



void menu()
{
	printf("***************************\n");
	printf("***************************\n");
	printf("******1.管理员界面：   ****\n");
	printf("******2.老师界面：     ****\n");
	printf("******3.学生界面：     ****\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("请选择(1-3):");
}

void AdminMenu()
{
	printf("*****欢迎来到管理员界面****\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("******1.添加学生信息   ****\n");
	printf("******2.修改学生信息   ****\n");
	printf("******3.删除学生信息   ****\n");
	printf("******4.查询学生信息   ****\n");
	printf("******5.显示学生信息   ****\n");
	printf("******6.返        回   ****\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("请选择(1-6):");

}

void Admin(Node* phead)
{
	stu st = { "张三",1,1,1,1,1 };
	int n = 0;
	do
	{
		AdminMenu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			push_back(phead, st);
			break;
		case 2:
			Modify(phead, Find(phead));
            while (1)
            {
                char s[20] = {0};
                printf("是否还要继续修改?请输入:(yes/no)\n");
                scanf("%s", s);
                if (strcmp(s, "yes") == 0)
                {
                    Modify(phead, Find(phead));
                }
                else
                {

                    break;
                }
            }
			break;
		case 3:
			Erease(phead, Find(phead));
			break;
		case 4:
			Find(phead);
			break;
		case 5:
			ListPrint(phead);
			break;
		case 6:
			return;
			break;
		default:
			printf("输入格式错误请重新输入\n");
			break;
		}
	} while (n);
}
void TeacherMenu()
{
	printf("*****欢迎来到老师界面******\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("******1.查看学生信息   ****\n");
	printf("******2.修改学生成绩   ****\n");
	printf("******3.查看成绩情况   ****\n");
	printf("******4.返回主菜单     ****\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("请选择(1-4):");

}

void Teacher(Node* phead)
{
	stu st = { "张三",1,1,1,1,1 };
	int n = 0;
	do
	{
		TeacherMenu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			Find(phead);
			break;
		case 2:
			Modify(phead, Find(phead));
			break;
		case 3:
			ListPrint(phead);
			break;
		case 4:
			return;
			break;
		default:
			printf("输入格式错误请重新输入\n");
			break;
		}
	} while (n);
}

void StudentMenu()
{
	printf("*****欢迎来到学生界面******\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("******1.注册账号       ****\n");
	printf("******2.查看自己成绩   ****\n");
    printf("******3.返回主菜单     ****\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("请选择(1-3):");

}

void Login(Node* phead)
{

    int id = 0;
    int nummber = 0;
    int code = 0;
    printf("请输入学号：");
    scanf("%d", &id);
    printf("请输入账号：");
    scanf("%d", &nummber);
    printf("请输入密码：");
    scanf("%d", &code);

    WriteCode(id, nummber, code);
    WriteCodeMysql();
}
int Print(Node* phead)
{
    assert(phead);
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    const char* server = "localhost";
    const char* user = "root";
   const char* password = "721229";
   const char* database = "test";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 3306, NULL, 0)) {
        printf("Error: %s\n", mysql_error(conn));
        return 1;
    }

    if (mysql_query(conn, "SELECT * FROM Code LIMIT 1")) {
        printf("Error: %s\n", mysql_error(conn));
        return 1;
    }

    res = mysql_use_result(conn);
    row = mysql_fetch_row(res);

    printf("First data in first row: %s\n", row[0]);

  
   
    Node* cur = phead->next;
    printf("%-9s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "姓名", "学号", "班级", "数学", "英语", "物理");
    while (cur != phead)
    {
        char str[20];
        _itoa(cur->val.id, str, 10);
        if (strcmp(str, row[0])==0)
        {
            printf("%-9s\t%-9d\t%-9d\t%-9d\t%-9d\t%-9d\n", cur->val.name, cur->val.id, cur->val.clas,
                cur->val.s.math, cur->val.s.english, cur->val.s.physics);
            break;
        }

        cur = cur->next;
    }

    mysql_free_result(res);
    mysql_close(conn);
    printf("\n\n");
}
void Student(Node* phead)
{
	stu st = { "张三",1,1,1,1,1 };
	int n = 0;
	do
	{
		StudentMenu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
            Login(phead);

			break;
		case 2:
            Print(phead);
			break;
        case 3:
            return;
            break;
		default:
			printf("输入格式错误请重新输入\n");
			break;
		}
	} while (n);
}
int main()
{
	
	
	int n = 0;
	Node* phead = NULL;
	ListNodeInit(&phead);

	ReadData(phead);//链接并读取数据库信息

	const char* ma = "123";
	const char* mb = "1234";

	char a[20];
	char b[20];
	char c[20];
	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("请输入密码：");
			scanf("%s", a);
			if (strcmp(ma, a) == 0)
			{
				Admin(phead);
			}
			else
			{
				printf("密码输入错误请重新输入\n");
			}
			break;
		case 2:
			printf("请输入密码：");
			scanf("%s", b);
			if (strcmp(mb, b) == 0)
			{
				Teacher(phead);
			}
			else
			{
				printf("密码输入错误请重新输入\n");
			}

			break;
		case 3:
            Student(phead);

		/*	printf("请输入密码：");
			scanf("%s", c);
			if (strcmp(mc, c) == 0)
			{
				Student(phead);
			}
			else
			{
				printf("密码输入错误请重新输入\n");
			}*/

			break;

		default:
			printf("输入格式错误请重新输入\n");
			break;
		}
	} while (n);
	return 0;
}

