//#pragma once//防止头文件被包含
//#include <iostream>
//using namespace std;
//
//#include <WinSock.h>
//#include <mysql.h>
//
//
////链接数据库代码
////void test()
////{
////    printf("test\n");
////
////
////    //初始化数据库
////    mysql_init(&m);
////
////    //设置编码方式
////    mysql_options(&m, MYSQL_SET_CHARSET_NAME, "gbk");
////
////    //连接数据库
////    if (mysql_real_connect(&m, "localhost", "root", "yigebeiju123", "cc", 3306, NULL, 0))
////    {                           //主机       用户名   密码      数据库名  端口
////        printf("数据库连接成功\n");
////    }
////    else {
////        printf("数据库连接失败:%s \n", mysql_error(&m));
////        //输出错误信息
////    }
////}
//
//#include <stdio.h>
//#include <malloc.h>
//#include <assert.h>
//#include <stdlib.h>
////各科成绩
//typedef struct Score
//{
//    int math;
//    int english;
//    int physics;
//}score;
//
////学生信息
//typedef struct student
//{
//    char name[20];
//    int id;
//    int clas;
//    score s;//成绩
//}stu;
////初始化结构体数据
//
////定义双向链表结构
//typedef stu ListDataType;
//
//typedef struct ListNode
//{
//    struct ListNode* prev;
//    struct ListNode* next;
//    ListDataType val;
//}Node;
////初始化信息
//void InitStu(Node** x)
//{
//
//    printf("请输入相关信息：\n");
//    printf("请输入姓名：");
//    scanf("%s", &(*x)->val.name);
//    printf("请输入学号：");
//
//    scanf("%d", &(*x)->val.id);
//    printf("请输入班级：");
//
//    scanf("%d", &(*x)->val.clas);
//    printf("请输入数学成绩：");
//
//    scanf("%d", &(*x)->val.s.math);
//    printf("请输入英语成绩：");
//
//    scanf("%d", &(*x)->val.s.english);
//    printf("请输入物理成绩：");
//
//    scanf("%d", &(*x)->val.s.physics);
//    //printf("输入成功\n");
//    //向数据库插入数据
//    MYSQL* conn;
//    MYSQL_STMT* stmt;
//    MYSQL_BIND bind[6];
// 
//    conn = mysql_init(NULL);
//
//    if (mysql_real_connect(conn, "localhost", "root", "yigebeiju123", "cc", 3306, NULL, 0) == NULL)
//    {
//        printf("Error: %!s(MISSING)\n", mysql_error(conn));
//   
//    }
//    else
//    {
//        printf("数据库链接成功\n");
//    }
//
//    stmt = mysql_stmt_init(conn);
//
//    if (mysql_stmt_prepare(stmt, "INSERT INTO student (name, id, clas, math, english, physics) VALUES (3, 3, 3, 3, 3, 3)", -1) != 0)
//    {
//        printf("Error: %!s(MISSING)\n", mysql_stmt_error(stmt));
//    }
//
//    const char* sql = "insert into student values(4,4,4,4,4,4)";
//
//    memset(bind, 0, sizeof(bind));
//    bind[0].buffer_type = MYSQL_TYPE_STRING;
//    bind[0].buffer = (char*)(*x)->val.name;
//    bind[0].buffer_length = sizeof((*x)->val.name);
//    bind[0].is_null = 0;
//    bind[1].buffer_type = MYSQL_TYPE_LONG;
//    bind[1].buffer = (char*)&(*x)->val.id;
//    bind[1].is_null = 0;
//
//    bind[2].buffer_type = MYSQL_TYPE_LONG;
//    bind[2].buffer = (char*)&(*x)->val.clas;
//    bind[2].is_null = 0;
//
//    bind[3].buffer_type = MYSQL_TYPE_LONG;
//    bind[3].buffer = (char*)&(*x)->val.s.math;
//    bind[3].is_null = 0;
//
//    bind[4].buffer_type = MYSQL_TYPE_LONG;
//    bind[4].buffer = (char*)&(*x)->val.s.english;
//    bind[4].is_null = 0;
//
//    bind[5].buffer_type = MYSQL_TYPE_LONG;
//    bind[5].buffer = (char*)&(*x)->val.s.physics;
//    bind[5].is_null = 0;
//
//    if (mysql_stmt_bind_param(stmt, bind) != 0)
//    {
//        printf("Error: %!s(MISSING)\n", mysql_stmt_error(stmt));
//    }
//
//    if (mysql_stmt_execute(stmt) != 0)
//    {
//        printf("Error: %!s(MISSING)\n", mysql_stmt_error(stmt));
//    }
//    mysql_stmt_close(stmt);
//    mysql_close(conn);
//}
////申请节点空间
//Node* BuynewNode(ListDataType x)
//{
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    if (newNode == NULL)
//    {
//        printf("开辟失败");
//        exit(-1);
//    }
//
//    //初始化节点数据
//    newNode->next = NULL;
//    newNode->prev = NULL;
//
//    InitStu(&newNode);
//    return newNode;//返回节点
//}
//Node* BuyInitNode(ListDataType x)
//{
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    if (newNode == NULL)
//    {
//        printf("开辟失败");
//        exit(-1);
//    }
//
//    newNode->next = NULL;
//    newNode->prev = NULL;
//    newNode->val = x;
//
//    return newNode;
//}
////定义哨兵头结点
//void ListNodeInit(Node** pphead)
//{
//    stu st = { "张三",1,1,1,1,1 };
//
//    Node* newNode = BuyInitNode(st);
//    *pphead = newNode;
//    (*pphead)->next = *pphead;
//    (*pphead)->prev = *pphead;
//}
//
////尾插
//void push_back(Node* phead, ListDataType x)
//{
//    assert(phead);
//    Node* newNode = BuynewNode(x);
//    Node* tail = phead->prev;
//
//    //phead==tail ->newNode 
//    tail->next = newNode;
//    newNode->prev = tail;
//    newNode->next = phead;
//    phead->prev = newNode;
//    printf("增加信息成功\n");
//
//}
//
//void ListPrint(Node* phead)
//{
//    assert(phead);
//
//    Node* cur = phead->next;
//    printf("%-9s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "姓名", "学号", "班级", "数学", "英语", "物理");
//    while (cur != phead)
//    {
//
//        printf("%-9s\t%-9d\t%-9d\t%-9d\t%-9d\t%-9d\n", cur->val.name, cur->val.id, cur->val.clas,
//            cur->val.s.math, cur->val.s.english, cur->val.s.physics);
//
//        cur = cur->next;
//    }
//    printf("\n\n");
//}
////按照学号查找某人
//Node* Find(Node* phead)
//{
//    assert(phead);
//    int x = 0;
//    printf("请输入要查找的学号：");
//    scanf("%d", &x);
//    Node* cur = phead->next;
//    while (cur != phead)
//    {
//        if (cur->val.id == x)
//        {
//            printf("找到了\n");
//            printf("%-9s\t%-9d\t%-9d\t%-9d\t%-9d\t%-9d\n", cur->val.name, cur->val.id, cur->val.clas,
//                cur->val.s.math, cur->val.s.english, cur->val.s.physics);
//
//            return cur;
//        }
//
//        cur = cur->next;
//    }
//    printf("查无此人或系统为空\n");
//    return NULL;
//
//}
////删除指定位置的节点
//void Erease(Node* phead, Node* pos)
//{
//    if (pos == phead || pos == NULL)
//    {
//        printf("未找到该学生，无此id\n");
//        return;
//    }
//
//    Node* posPrev = pos->prev;
//    Node* posNext = pos->next;
//
//    posPrev->next = posNext;
//    posNext->prev = posPrev;
//
//    free(pos);
//    pos = NULL;
//    printf("删除成功\n");
//}
////修改指定位置的节点的学生成绩
//void Modify(Node* phead, Node* pos)
//{
//    if (pos == phead || pos == NULL)
//    {
//        printf("未找到该学生，无此id\n");
//        return;
//    }
//    printf("请输入修改后的数学成绩：");
//
//    scanf("%d", &pos->val.s.math);
//    printf("请输入修改后的英语成绩：");
//
//    scanf("%d", &pos->val.s.english);
//    printf("请输入修改后的物理成绩：");
//
//    scanf("%d", &pos->val.s.physics);
//
//
//
//    printf("修改成功\n");
//}
//
//void cal(Node* phead)
//{
//    int avmath = 0;
//    int avenglish = 0;
//    int avphysics = 0;
//    Node* cur = phead->next;
//    while (cur != phead)
//    {
//
//        printf("%s的总成绩是%d   \n", cur->val.name, (cur->val.s.math + cur->val.s.english + cur->val.s.physics));
//        avmath += cur->val.s.math;
//        avenglish += cur->val.s.english;
//        avphysics += cur->val.s.physics;
//
//        cur = cur->next;
//    }
//
//    printf("数学单科平均分是%d,英语单科平均分是%d,物理单科平均分是%d\n", avmath, avenglish, avphysics);
//}
