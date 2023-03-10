//#pragma once//防止头文件被包含
//
//#include <iostream>
//using namespace std;
//
//#include <WinSock.h>
//#include <mysql.h>
///*向数据库中写入文件*/
//int WriteMysql()
//{
//    MYSQL* conn;
//    MYSQL_STMT* stmt;
//    const char* query;
//    const char* filename = "data.txt";
//    FILE* fp;
//    char name[20];
//    int id, clas, math, english, physics;
//    // 打开文件
//    fp = fopen(filename, "r");
//    if (fp == NULL) {
//        printf("Error opening file!\n");
//        return -1;
//    }
//    // 连接数据库
//    conn = mysql_init(NULL);
//    if (conn == NULL) {
//        printf("Error connecting to database!\n");
//        return -1;
//    }
//    if (mysql_real_connect(conn, "localhost", "root", "yigebeiju123", "cc", 3306, NULL, 0) == NULL)
//    {
//        printf("Error connecting to database!\n");
//        return -1;
//    }
//    else
//    {
//        printf("链接成功\n");
//    }
//
//    // 先清空数据库
//    query = "DELETE FROM student";
//    mysql_query(conn, query);
//    // 读取文件中的数据
//    while (fscanf(fp, "%s%d%d%d%d%d",
//        name, &id, &clas, &math, &english, &physics) != EOF)
//    {
//        // 构造插入语句
//        query = "INSERT INTO student (name, id, clas, math, english, physics) VALUES (?,?, ?, ?, ?,?)";
//        // 准备插入语句
//        stmt = mysql_stmt_init(conn);
//        if (mysql_stmt_prepare(stmt, query, strlen(query)) != 0) {
//            printf("Error preparing statement!\n");
//            return -1;
//        }
//        // 执行插入语句
//        MYSQL_BIND bind[6];
//        memset(bind, 0, sizeof(bind));
//        bind[0].buffer_type = MYSQL_TYPE_STRING;
//        bind[0].buffer = (char*)name;
//        bind[0].buffer_length = strlen(name);
//
//        bind[1].buffer_type = MYSQL_TYPE_LONG;
//        bind[1].buffer = &id;
//        bind[2].buffer_type = MYSQL_TYPE_LONG;
//        bind[2].buffer = &clas;
//        bind[3].buffer_type = MYSQL_TYPE_LONG;
//        bind[3].buffer = &math;
//        bind[4].buffer_type = MYSQL_TYPE_LONG;
//        bind[4].buffer = &english;
//        bind[5].buffer_type = MYSQL_TYPE_LONG;
//        bind[5].buffer = &physics;
//
//        mysql_stmt_bind_param(stmt, bind);
//        mysql_stmt_execute(stmt);
//    }
//    // 关闭文件
//    fclose(fp);
//    // 关闭数据库连接
//    mysql_close(conn);
//
//}
///*从数据库中读取文件*/
//int ReadMysql()
//{
//    MYSQL* conn;
//    MYSQL_STMT* stmt;
//    const char* query;
//    const char* filename = "data.txt";
//    FILE* fp;
//    char name[20];
//    int id, clas, math, english, physics;
//    // 打开文件
//    fp = fopen(filename, "w");
//    if (fp == NULL) {
//        printf("Error opening file!\n");
//        return -1;
//    }
//    // 连接数据库
//    conn = mysql_init(NULL);
//    if (conn == NULL) {
//        printf("Error connecting to database!\n");
//        return -1;
//    }
//    if (mysql_real_connect(conn, "localhost", "root", "yigebeiju123", "cc", 3306, NULL, 0) == NULL)
//    {
//        printf("Error connecting to database!\n");
//        return -1;
//    }
//    else
//    {
//        printf("链接成功\n");
//    }
//    // 构造查询语句
//    query = "SELECT name, id, clas, math, english, physics FROM student";
//    // 准备查询语句
//    stmt = mysql_stmt_init(conn);
//    if (mysql_stmt_prepare(stmt, query, strlen(query)) != 0) {
//        printf("Error preparing statement!\n");
//        return -1;
//    }
//    // 执行查询语句
//    MYSQL_BIND bind[6];
//    memset(bind, 0, sizeof(bind));
//    bind[0].buffer_type = MYSQL_TYPE_STRING;
//    bind[0].buffer = (char*)name;
//    bind[0].buffer_length = strlen(name);
//    bind[1].buffer_type = MYSQL_TYPE_LONG;
//    bind[1].buffer = &id;
//    bind[2].buffer_type = MYSQL_TYPE_LONG;
//    bind[2].buffer = &clas;
//    bind[3].buffer_type = MYSQL_TYPE_LONG;
//    bind[3].buffer = &math;
//    bind[4].buffer_type = MYSQL_TYPE_LONG;
//    bind[4].buffer = &english;
//    bind[5].buffer_type = MYSQL_TYPE_LONG;
//    bind[5].buffer = &physics;
//    mysql_stmt_bind_result(stmt, bind);
//    mysql_stmt_execute(stmt);
//    // 读取查询结果
//    while (mysql_stmt_fetch(stmt) == 0) {
//        fprintf(fp, "%s %d %d %d %d %d\n",
//            name, id, clas, math, english, physics);
//    }
//    // 关闭文件
//    fclose(fp);
//    // 关闭数据库连接
//    mysql_close(conn);
//}
//
//#include <stdio.h>
//#include <malloc.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <string.h>
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
//
////将学生信息等数据写入到文件data.txt中
//void WriteData(Node* phead)
//{
//    //打开文件
//    FILE* pf = fopen("data.txt", "w");
//    if (pf == NULL)
//    {
//        printf("保存失败\n");
//        return;
//    }
//    //向文件传输数据
//    Node* cur = phead->next;
//    printf("%-9s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "姓名", "学号", "班级", "数学", "英语", "物理");
//    while (cur != phead)
//    {
//        fprintf(pf, "%s %d %d %d %d %d\n", cur->val.name, cur->val.id, cur->val.clas,
//           cur->val.s.math, cur->val.s.english, cur->val.s.physics);
//
//        cur = cur->next;
//    }
//
//    //关闭文件
//    fclose(pf);
//    pf = NULL;
//    //printf("写入文件成功\n");
//}
//
//Node* BuyNode(ListDataType x)
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
//    return newNode;//返回节点
//}
////从文件中读出数据到程序中
//void ReadData(Node* phead)
//{
//    ReadMysql();
//    stu st = { "张三",1,1,1,1,1 };
//    //打开文件
//    FILE* pf = fopen("data.txt", "r");
//    if (pf == NULL)
//    {
//        printf("%s\n", strerror(errno));
//        return;//文件打开失败，失败返回
//    }
//
//    Node* newNode = BuyNode(st);
//       
//   //对文件进行格式化读取
//    Node* tail = phead->prev;
//    printf("%-9s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "姓名", "学号", "班级", "数学", "英语", "物理");
//        while (fscanf(pf, "%s %d %d %d %d %d\n", newNode->val.name, &newNode->val.id, &newNode->val.clas,
//            &newNode->val.s.math, &newNode->val.s.english, &newNode->val.s.physics) != EOF)
//        {
//            printf("%-9s\t%-9d\t%-9d\t%-9d\t%-9d\t%-9d\n", newNode->val.name, newNode->val.id, newNode->val.clas,
//                newNode->val.s.math, newNode->val.s.english, newNode->val.s.physics);
//          
//            //phead==tail ->newNode 
//
//
//            tail->next = newNode;
//            newNode->prev = tail;
//            newNode->next = phead;
//            phead->prev = newNode;
//
//            tail = phead->prev;
//
//            newNode = BuyNode(st);
//        }
//       
//    
//    //关闭文件
//    fclose(pf);
//    pf = NULL;
//    printf("读取数据完成\n");
//}
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
//
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
//
//    WriteData(phead);
//
//    WriteMysql();
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
//            printf("结果如下\n");
//            printf("%-9s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "姓名", "学号", "班级", "数学", "英语", "物理");
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
//
//    WriteData(phead);
//
//    WriteMysql();
//
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
//    WriteData(phead);
//
//    WriteMysql();
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
