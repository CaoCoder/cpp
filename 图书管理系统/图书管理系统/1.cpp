//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define H 1000
//
//struct student//����ͼ����Ϣ�Ľṹ�� 
//{
//	char bookname[20];
//	float price;
//	char date[11];
//	long SerialNumber;
//	char borrower[10];
//	int id;
//}stu[H];
//
//
//struct zhonglei//���������ͼ��ing�ɵĹ�ϵ
//{
//	char bookname[20];
//	int xuhao;
//}zl[H];
//
//
//void PrintfMenu()//����˵����� 
//{
//	printf("***************ͼ�������Ϣ����ϵͳ***************\n");
//	printf("	1.ͼ�������Ϣ¼��\n");
//	printf("	2.ͼ�鰴������Ϣ�������\n");
//	printf("	3.��ͼ�����Ʋ��Ľ��ļ�¼\n");
//	printf("	4.��������������ѯ���ļ�¼\n");
//	printf("	5.��ѯ�۸���ߺ���͵�ͼ��\n");
//	printf("	6.ͳ��������Ĵ�������3����\n");
//	printf("	0.�˳�ϵͳ\n");
//	printf("**************************************************\n");
//}
//
//
//void biaotou()//�ļ���д���ͷ 
//{
//	FILE* fp;
//	char a[100] = "ͼ������\t��������\t������\t��ˮ��\t�۸�\t������ID��\n";//��ʼ�� 
//
//	if ((fp = fopen("xinxi.txt", "a")) == NULL)
//	{
//		printf("�ļ���ʧ�ܣ�\n");
//		exit(0);
//	}//����ļ����Ƿ�ɹ� 
//
//	fputs(a, fp);
//
//	fclose(fp);
//
//}
//
//void zlChuShiHua(int* p, struct zhonglei zl[])
//{
//	int i;
//	for (i = 0; i < (*p); i++)
//	{
//		zl[i].xuhao = 0;
//	}//������ÿһ����ų�ʼֵΪ0 
//}
//
//
////void WritetoFile(struct student stu[], int* p, struct zhonglei zl[])//��������Ϣ¼���ļ� 
////{
////	FILE* fp;
////	int i, j;
////
////	if ((fp = fopen("xinxi.txt", "a")) == NULL)
////	{
////		printf("�ļ���ʧ�ܣ�\n");
////		exit(0);
////	}//�ж��ļ����Ƿ�ɹ�
////
////	printf("������ͼ�����ƣ�\n");//��Ϣ�Ӽ���¼�� 
////	scanf(" %s", stu[*p].bookname);
////	fprintf(fp, "   %s\t", stu[*p].bookname);
////
////	printf("������������ڣ�\n");
////	scanf(" %s", stu[*p].date);
////	fprintf(fp, "   %s\t", stu[*p].date);
////
////	printf("����������ˣ�\n");
////	scanf(" %s", stu[*p].borrower);
////	fprintf(fp, "     %s\t", stu[*p].borrower);
////
////	printf("��������ˮ�ţ�\n");
////	scanf("%d", &stu[*p].SerialNumber);
////	fprintf(fp, "     %d\t", stu[*p].SerialNumber);
////
////	printf("������ͼ��۸�\n");
////	scanf("%f", &stu[*p].price);
////	fprintf(fp, "      %.1f\t", stu[*p].price);
////
////	printf("�����������ID�ţ�\n");
////	scanf("%d", &stu[*p].id);
////	fprintf(fp, "      %d\n", stu[*p].id);
////
////	fclose(fp);
////
////	//�ж��Ȿ���Ƿ񱻽�� ������ 
////	if (*p == 1)
////	{
////		for (i = 0; stu[*p].bookname != '\0'; i++)
////		{
////			zl[*p].bookname[i] = stu[*p].bookname[i];
////		}
////		zl[*p].bookname[i] = stu[*p].bookname[i];
////		(zl[*p].xuhao)++;
////	}
////
////
////	for (i = 0; i < *p; i++)
////	{
////		if (zl[i].bookname == stu[*p].bookname)
////		{
////			(zl[i].xuhao)++;
////		}
////
////		else
////		{
////			for (i = 0; stu[*p].bookname != '\0'; i++)
////			{
////				zl[*p].bookname[i] = stu[*p].bookname[i];
////			}
////			zl[*p].bookname[i] = stu[*p].bookname[i];
////			(zl[*p].xuhao)++;
////		}
////	}
////
////}
//
//
//void paixu1(int* p, struct student stu[])//��id��С������� 
//{
//	int i, j;
//	struct student temp;//��ʼ�� 
//
//	for (i = 0; i <= (*p); i++)
//	{
//		for (j = i + 1; j <= (*p); j++)
//		{
//			if (stu[i].id < stu[j].id)//�����ͽ��� �������ǰ��  //ѡ������ 
//			{
//				temp = stu[i];
//				stu[i] = stu[j];
//				stu[j] = temp;
//			}
//		}
//	}
//
//	for (i = 0; i < (*p); i++)//��������� 
//	{
//		printf("ͼ�����ƣ�");
//		printf("%s\n", stu[i].bookname);
//
//		printf("ͼ��۸�");
//		printf("%.1f\n", stu[i].price);
//
//		printf("�������ڣ�");
//		printf("%s\n", stu[i].date);
//
//		printf("��ˮ�ţ�");
//		printf("%d\n", stu[i].SerialNumber);
//
//		printf("�����ˣ�");
//		printf("%s\n", stu[i].borrower);
//
//		printf("������ID��");
//		printf("%d\n", stu[i].id);
//
//		printf("-------------------------------------------------\n");
//	}
//
//	printf("������ɣ�\n");
//
//}
//
//
//void find1(int* p, struct student stu[])//��ͼ�����Ʋ�ѯ���ļ�¼ 
//{
//	int i, a, b = 0;
//	char name[20];
//	printf("������ͼ������ƣ�\n");
//	scanf(" %s", name);
//	for (i = 0; i <= *p; i++)
//	{
//		if (strcmp(stu[i].bookname, name) == 0)
//		{
//			b++;
//			printf("ͼ�顶%s���Ľ��ļ�¼���£�\n", stu[i].bookname);
//
//			printf("�۸�%.1f\n", stu[i].price);
//			printf("�������ڣ�%s\n", stu[i].date);
//			printf("��ˮ�ţ�%d\n", stu[i].SerialNumber);
//			printf("�����ˣ�%s\n", stu[i].borrower);
//			printf("������ID�ţ�%d\n", stu[i].id);
//
//			printf("------------------------------------------------------\n");
//		}
//	}
//	if (b == 0) printf("�Ҳ�����ͼ���Ӧ�Ľ��ļ�¼��");
//}
//
//
//void find2(int* p, struct student stu[])//��������������ѯ���ļ�¼ 
//{
//	int i, a, b = 0;
//	char name[20];
//	printf("�����������������\n");
//	scanf(" %s", name);
//	for (i = 0; i <= *p; i++)
//	{
//		if (strcmp(stu[i].borrower, name) == 0)
//		{
//			b++;
//			printf("\n%s�Ľ��ļ�¼���£�\n", stu[i].borrower);
//
//			printf("ͼ�����ƣ�%s\n", stu[i].bookname);
//			printf("�۸�%.1f\n", stu[i].price);
//			printf("�������ڣ�%s\n", stu[i].date);
//			printf("��ˮ�ţ�%d\n", stu[i].SerialNumber);
//			printf("������ID�ţ�%d\n", stu[i].id);
//
//			printf("------------------------------------------------------\n");
//		}
//	}
//	if (b == 0) printf("       �Ҳ������˶�Ӧ�Ľ��ļ�¼��");
//}
//
//
//void find3(int* p, struct student stu[])//��ѯ�۸���ߺ���͵��� �������ڼ۸���ͬ���飩
//{
//	int i, max, min;
//	max = min = 0;
//
//	int  j;
//	struct student temp;//��ʼ�� 
//
//	for (i = 0; i <= (*p); i++)
//	{
//		for (j = i + 1; j <= (*p); j++)
//		{
//			if (stu[i].id < stu[j].id)//�����ͽ��� �������ǰ��  //ѡ������ 
//			{
//				temp = stu[i];
//				stu[i] = stu[j];
//				stu[j] = temp;
//			}
//		}
//	}
//
//	//������
//	printf("�۸���ߵ�����:%s\n", stu[0].bookname);
//	printf("��۸�Ϊ��%.1f\n", stu[0].price);
//
//	printf("�۸���͵�����:%s\n", stu[(*p-1)].bookname);
//	printf("��۸�Ϊ��%.1f\n", stu[(*p-1)].price);
//
//	printf("--------------------------------------------\n");
//
//}
//
//
//
//
//void find4(int* p, struct student stu[], struct zhonglei zl[])//���ҽ��Ĵ�������������
//{
//	int i;
//	int first, second, third;
//	first = second = third = 0;//��ʼ�� 
//
//	int  j;
//	struct student temp;//��ʼ�� 
//
//	for (i = 0; i <= (*p); i++)
//	{
//		for (j = i + 1; j <= (*p); j++)
//		{
//			if (stu[i].id < stu[j].id)//�����ͽ��� �������ǰ��  //ѡ������ 
//			{
//				temp = stu[i];
//				stu[i] = stu[j];
//				stu[j] = temp;
//			}
//		}
//	}
//
//	printf("���Ĵ�����1����%c,���Ĵ���Ϊ%d��\n", zl[0].bookname, zl[0].xuhao);
//	printf("���Ĵ�����2����%c,���Ĵ���Ϊ%d��\n", zl[1].bookname, zl[1].xuhao);
//	printf("���Ĵ�����3����%c,���Ĵ���Ϊ%d��\n", zl[2].bookname, zl[2].xuhao);
//
//}
//
//
//int main()//������ 
//{
//	int a, * p, h;
//	char b;
//	h = 0;
//	p = &h;//ͼ����������� 
//	//�������ĳ�ʼ�� 
//	char code[20];
//	zlChuShiHua(p, zl);//��ͼ�������ͳ�ƽṹ����ɳ�ʼ�� 
//
//	biaotou();//���ļ�¼��һ����ͷ 
//
//	do
//	{
//		printf("����������:(123456)       ");
//		scanf("%s", code);
//		if (strcmp(code, "123456") != 0)
//		{
//			printf("�����������:����������\n");
//			break;
//		}
//		printf("����������ȷ����ʼѡ��\n\n\n\n");
//		PrintfMenu();
//		printf("������ѡ��ִ�ж�Ӧ���ܣ�\n");
//		scanf("%d", &a);
//		switch (a)
//		{
//		case 1://��Ϣ¼�� 
//			do
//			{
//
//				h++;
//				//WritetoFile(stu, p, zl);
//				printf("ͼ�������Ϣ¼��ɹ���\n");
//				printf("�Ƿ�Ҫ¼����һ��������Ϣ��(Y/N)\n");
//				scanf(" %c", &b);
//
//			} while ((b == 'y') || (b == 'Y'));
//			break;
//
//		case 2://��id��С������� 
//			paixu1(p, stu);
//			break;
//
//		case 3://��ͼ�����Ʋ�ѯ���ļ�¼
//			find1(p, stu);
//			break;
//
//		case 4://��������������ѯ���ļ�¼
//			find2(p, stu);
//			break;
//
//		case 5://��ѯ�۸���ߺ���͵��� 
//			find3(p, stu);
//			break;
//
//		case 6://��ѯ���Ĵ������������� 
//			find4(p, stu, zl);
//			break;
//
//		case 0://�˳�ϵͳ 
//			return 0;
//		
//
//		}
//		printf("�Ƿ�Ҫ�˳�����(Y/N)\n");
//		scanf(" %c", &b);
//	} while ((b == 'n') || (b == 'N'));
//
//
//
//	return 0;
//}
