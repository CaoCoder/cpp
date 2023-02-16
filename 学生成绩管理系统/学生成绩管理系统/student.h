#pragma once//��ֹͷ�ļ�������
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
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
    //printf("����ɹ�\n");

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
            printf("�ҵ���\n");
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
