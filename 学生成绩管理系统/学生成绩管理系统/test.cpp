#define _CRT_SECURE_NO_WARNINGS 1
#pragma once//��ֹͷ�ļ�������
#include <iostream>
using namespace std;

#include <WinSock.h>
#include <mysql.h>
//��ע����˺�����д���ļ�
void WriteCode(int a,int b, int c)
{
    //���ļ�
    FILE* pf = fopen("code.txt", "w");
    if (pf == NULL)
    {
        printf("����ʧ��\n");
        return;
    }
    //���ļ���������
    int id = a, nummber =b , code = c;
        fprintf(pf, "%d %d %d\n", id, nummber, code);
    
    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    //printf("д���ļ��ɹ�\n");
}
//��ע����˺�����д�����ݿ�
int WriteCodeMysql()
{
    MYSQL* conn;
    MYSQL_STMT* stmt;
    const char* query;
    const char* filename = "code.txt";
    FILE* fp;
    int id,nummber,code;
    // ���ļ�
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
    // �������ݿ�
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

        /*printf("���ӳɹ�\n")*/;
    }

    // ��������ݿ�
    query = "DELETE FROM Code";
    mysql_query(conn, query);
    // ��ȡ�ļ��е�����
    while (fscanf(fp, "%d%d%d",
        &id,&nummber,&code) != EOF)
    {
        // ����������
        query = "INSERT INTO Code (id, nummber, code) VALUES (?,?, ?)";
        // ׼���������
        stmt = mysql_stmt_init(conn);
        if (mysql_stmt_prepare(stmt, query, strlen(query)) != 0) {
            printf("Error preparing statement!\n");
            return -1;
        }
        // ִ�в������
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
    // �ر��ļ�
    fclose(fp);
    // �ر����ݿ�����
    mysql_close(conn);

}
/*�����ݿ���д���ļ�*/
int WriteMysql()
{
    MYSQL* conn;
    MYSQL_STMT* stmt;
    const char* query;
    const char* filename = "data.txt";
    FILE* fp;
    char name[20];
    int id, clas, math, english, physics;
    // ���ļ�
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
    // �������ݿ�
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

        /*printf("���ӳɹ�\n")*/;
    }

    // ��������ݿ�
    query = "DELETE FROM student";
    mysql_query(conn, query);
    // ��ȡ�ļ��е�����
    while (fscanf(fp, "%s%d%d%d%d%d",
        name, &id, &clas, &math, &english, &physics) != EOF)
    {
        // ����������
        query = "INSERT INTO student (name, id, clas, math, english, physics) VALUES (?,?, ?, ?, ?,?)";
        // ׼���������
        stmt = mysql_stmt_init(conn);
        if (mysql_stmt_prepare(stmt, query, strlen(query)) != 0) {
            printf("Error preparing statement!\n");
            return -1;
        }
        // ִ�в������
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
    // �ر��ļ�
    fclose(fp);
    // �ر����ݿ�����
    mysql_close(conn);

}
/*�����ݿ��ж�ȡ�ļ�*/
int ReadMysql()
{
    MYSQL* conn;
    MYSQL_STMT* stmt;
    const char* query;
    const char* filename = "data.txt";
    FILE* fp;
    char name[20];
    int id, clas, math, english, physics;
    // ���ļ�
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
    // �������ݿ�
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
        /*printf("���ӳɹ�\n")*/;
    }
    // �����ѯ���
    query = "SELECT name, id, clas, math, english, physics FROM student";
    // ׼����ѯ���
    stmt = mysql_stmt_init(conn);
    if (mysql_stmt_prepare(stmt, query, strlen(query)) != 0) {
        printf("Error preparing statement!\n");
        return -1;
    }
    // ִ�в�ѯ���
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
    // ��ȡ��ѯ���
    while (mysql_stmt_fetch(stmt) == 0) {
        fprintf(fp, "%s %d %d %d %d %d\n",
            name, id, clas, math, english, physics);
    }
    // �ر��ļ�
    fclose(fp);
    // �ر����ݿ�����
    mysql_close(conn);
}

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
//���Ƴɼ�
typedef struct Score
{
    int math;
    int english;
    int physics;
}score;

//ѧ����Ϣ
typedef struct student
{
    char name[20];
    int id;
    int clas;
    score s;//�ɼ�
}stu;
//��ʼ���ṹ������

//����˫������ṹ
typedef stu ListDataType;

typedef struct ListNode
{
    struct ListNode* prev;
    struct ListNode* next;
    ListDataType val;
}Node;

//��ѧ����Ϣ������д�뵽�ļ�data.txt��
void WriteData(Node* phead)
{
    //���ļ�
    FILE* pf = fopen("data.txt", "w");
    if (pf == NULL)
    {
        printf("����ʧ��\n");
        return;
    }
    //���ļ���������
    Node* cur = phead->next;
   
    while (cur != phead)
    {
        fprintf(pf, "%s %d %d %d %d %d\n", cur->val.name, cur->val.id, cur->val.clas,
            cur->val.s.math, cur->val.s.english, cur->val.s.physics);

        cur = cur->next;
    }

    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    //printf("д���ļ��ɹ�\n");
}

Node* BuyNode(ListDataType x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("����ʧ��");
        exit(-1);
    }

    //��ʼ���ڵ�����
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;//���ؽڵ�
}
//���ļ��ж������ݵ�������
void ReadData(Node* phead)
{
    ReadMysql();
    stu st = { "����",1,1,1,1,1 };
    //���ļ�
    FILE* pf = fopen("data.txt", "r");
    if (pf == NULL)
    {
        printf("%s\n", strerror(errno));
        return;//�ļ���ʧ�ܣ�ʧ�ܷ���
    }

    Node* newNode = BuyNode(st);

    //���ļ����и�ʽ����ȡ
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


    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    printf("��ȡ�������\n");
}
//��ʼ����Ϣ
void InitStu(Node** x)
{

    printf("�����������Ϣ��\n");
    printf("������������");
    scanf("%s", &(*x)->val.name);
    printf("������ѧ�ţ�");

    scanf("%d", &(*x)->val.id);
    printf("������༶��");

    scanf("%d", &(*x)->val.clas);
    printf("��������ѧ�ɼ���");

    scanf("%d", &(*x)->val.s.math);
    printf("������Ӣ��ɼ���");

    scanf("%d", &(*x)->val.s.english);
    printf("����������ɼ���");

    scanf("%d", &(*x)->val.s.physics);

}
//����ڵ�ռ�
Node* BuynewNode(ListDataType x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("����ʧ��");
        exit(-1);
    }

    //��ʼ���ڵ�����
    newNode->next = NULL;
    newNode->prev = NULL;

    InitStu(&newNode);
    return newNode;//���ؽڵ�
}
Node* BuyInitNode(ListDataType x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("����ʧ��");
        exit(-1);
    }

    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->val = x;

    return newNode;
}
//�����ڱ�ͷ���
void ListNodeInit(Node** pphead)
{
    stu st = { "����",1,1,1,1,1 };

    Node* newNode = BuyInitNode(st);
    *pphead = newNode;
    (*pphead)->next = *pphead;
    (*pphead)->prev = *pphead;
}

//β��
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
    printf("������Ϣ�ɹ�\n");

}

void ListPrint(Node* phead)
{
    assert(phead);

    Node* cur = phead->next;
    printf("%-9s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "����", "ѧ��", "�༶", "��ѧ", "Ӣ��", "����");
    while (cur != phead)
    {

        printf("%-9s\t%-9d\t%-9d\t%-9d\t%-9d\t%-9d\n", cur->val.name, cur->val.id, cur->val.clas,
            cur->val.s.math, cur->val.s.english, cur->val.s.physics);

        cur = cur->next;
    }
    printf("\n\n");
}
//����ѧ�Ų���ĳ��
Node* Find(Node* phead)
{
    assert(phead);
    int x = 0;
    printf("������Ҫ���ҵ�ѧ�ţ�");
    scanf("%d", &x);
    Node* cur = phead->next;
    while (cur != phead)
    {
        if (cur->val.id == x)
        {
            printf("�������\n");
            printf("%-9s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "����", "ѧ��", "�༶", "��ѧ", "Ӣ��", "����");
            printf("%-9s\t%-9d\t%-9d\t%-9d\t%-9d\t%-9d\n", cur->val.name, cur->val.id, cur->val.clas,
                cur->val.s.math, cur->val.s.english, cur->val.s.physics);

            return cur;
        }

        cur = cur->next;
    }
    printf("���޴��˻�ϵͳΪ��\n");
    return NULL;

}
//ɾ��ָ��λ�õĽڵ�
void Erease(Node* phead, Node* pos)
{
    if (pos == phead || pos == NULL)
    {
        printf("δ�ҵ���ѧ�����޴�id\n");
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

    printf("ɾ���ɹ�\n");
}
//�޸�ָ��λ�õĽڵ��ѧ���ɼ�
void Modify(Node* phead, Node* pos)
{
    if (pos == phead || pos == NULL)
    {
        printf("δ�ҵ���ѧ�����޴�id\n");
        return;
    }
    printf("�������޸ĺ����ѧ�ɼ���");

    scanf("%d", &pos->val.s.math);
    printf("�������޸ĺ��Ӣ��ɼ���");

    scanf("%d", &pos->val.s.english);
    printf("�������޸ĺ������ɼ���");

    scanf("%d", &pos->val.s.physics);


    WriteData(phead);


    WriteMysql();
    printf("�޸ĳɹ�\n");
}

void cal(Node* phead)
{
    int avmath = 0;
    int avenglish = 0;
    int avphysics = 0;
    Node* cur = phead->next;
    while (cur != phead)
    {

        printf("%s���ܳɼ���%d   \n", cur->val.name, (cur->val.s.math + cur->val.s.english + cur->val.s.physics));
        avmath += cur->val.s.math;
        avenglish += cur->val.s.english;
        avphysics += cur->val.s.physics;

        cur = cur->next;
    }

    printf("��ѧ����ƽ������%d,Ӣ�ﵥ��ƽ������%d,������ƽ������%d\n", avmath, avenglish, avphysics);
}



void menu()
{
	printf("***************************\n");
	printf("***************************\n");
	printf("******1.����Ա���棺   ****\n");
	printf("******2.��ʦ���棺     ****\n");
	printf("******3.ѧ�����棺     ****\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("��ѡ��(1-3):");
}

void AdminMenu()
{
	printf("*****��ӭ��������Ա����****\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("******1.���ѧ����Ϣ   ****\n");
	printf("******2.�޸�ѧ����Ϣ   ****\n");
	printf("******3.ɾ��ѧ����Ϣ   ****\n");
	printf("******4.��ѯѧ����Ϣ   ****\n");
	printf("******5.��ʾѧ����Ϣ   ****\n");
	printf("******6.��        ��   ****\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("��ѡ��(1-6):");

}

void Admin(Node* phead)
{
	stu st = { "����",1,1,1,1,1 };
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
                printf("�Ƿ�Ҫ�����޸�?������:(yes/no)\n");
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
			printf("�����ʽ��������������\n");
			break;
		}
	} while (n);
}
void TeacherMenu()
{
	printf("*****��ӭ������ʦ����******\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("******1.�鿴ѧ����Ϣ   ****\n");
	printf("******2.�޸�ѧ���ɼ�   ****\n");
	printf("******3.�鿴�ɼ����   ****\n");
	printf("******4.�������˵�     ****\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("��ѡ��(1-4):");

}

void Teacher(Node* phead)
{
	stu st = { "����",1,1,1,1,1 };
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
			printf("�����ʽ��������������\n");
			break;
		}
	} while (n);
}

void StudentMenu()
{
	printf("*****��ӭ����ѧ������******\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("******1.ע���˺�       ****\n");
	printf("******2.�鿴�Լ��ɼ�   ****\n");
    printf("******3.�������˵�     ****\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("��ѡ��(1-3):");

}

void Login(Node* phead)
{

    int id = 0;
    int nummber = 0;
    int code = 0;
    printf("������ѧ�ţ�");
    scanf("%d", &id);
    printf("�������˺ţ�");
    scanf("%d", &nummber);
    printf("���������룺");
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
    printf("%-9s\t%-9s\t%-9s\t%-9s\t%-9s\t%-9s\n", "����", "ѧ��", "�༶", "��ѧ", "Ӣ��", "����");
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
	stu st = { "����",1,1,1,1,1 };
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
			printf("�����ʽ��������������\n");
			break;
		}
	} while (n);
}
int main()
{
	
	
	int n = 0;
	Node* phead = NULL;
	ListNodeInit(&phead);

	ReadData(phead);//���Ӳ���ȡ���ݿ���Ϣ

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
			printf("���������룺");
			scanf("%s", a);
			if (strcmp(ma, a) == 0)
			{
				Admin(phead);
			}
			else
			{
				printf("���������������������\n");
			}
			break;
		case 2:
			printf("���������룺");
			scanf("%s", b);
			if (strcmp(mb, b) == 0)
			{
				Teacher(phead);
			}
			else
			{
				printf("���������������������\n");
			}

			break;
		case 3:
            Student(phead);

		/*	printf("���������룺");
			scanf("%s", c);
			if (strcmp(mc, c) == 0)
			{
				Student(phead);
			}
			else
			{
				printf("���������������������\n");
			}*/

			break;

		default:
			printf("�����ʽ��������������\n");
			break;
		}
	} while (n);
	return 0;
}

