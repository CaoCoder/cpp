#pragma once//防止头文件被包含
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
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
    //printf("输入成功\n");

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
            printf("找到了\n");
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
