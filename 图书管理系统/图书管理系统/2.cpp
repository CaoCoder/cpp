#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <map>
using namespace std;
#define H 1000

struct student//定义图书信息的结构体 
{
	char bookname[20];
	float price;
	char date[11];
	long long SerialNumber;
	char borrower[10];
	int id;
}stu[H];


struct zhonglei//定义种类和图书ing成的关系
{
	char bookname[20];
	int xuhao;
}zl[H];


void PrintfMenu()//输出菜单函数 
{
	printf("***************图书借阅信息管理系统***************\n");
	printf("	1.图书借阅信息录入\n");
	printf("	2.图书按借阅信息排序输出\n");
	printf("	3.按图书名称查阅借阅记录\n");
	printf("	4.按借阅人姓名查询借阅记录\n");
	printf("	5.查询价格最高和最低的图书\n");
	printf("	6.统计输出借阅次数最多的3本书\n");
	printf("	0.退出系统\n");
	printf("**************************************************\n");
}


void biaotou()//文件中写入表头 
{
	FILE* fp;
	char a[100] = "图书名称\t借阅日期\t借阅人\t流水号\t价格\t借阅人ID号\n";//初始化 

	if ((fp = fopen("xinxi.txt", "a")) == NULL)
	{
		printf("文件打开失败！\n");
		exit(0);
	}//检测文件打开是否成功 

	fputs(a, fp);

	fclose(fp);

}

/*void zlChuShiHua(int *p,struct zhonglei zl[])
{
	int i;
	for(i=0;i<(*p);i++)
	{
		zl[i].xuhao=0;
	}//让他的每一个序号初始值为0
} */

long long  cal(long long idd)
{
	long long i = 0;
	while (idd)
	{
		idd = idd / 10;
		i++;
	}
	return i;
}
void WritetoFile(struct student stu[], int* p)//将借阅信息录入文件 
{
	FILE* fp;
	int i, j;

	if ((fp = fopen("xinxi.txt", "a")) == NULL)
	{
		printf("文件打开失败！\n");
		exit(0);
	}//判断文件打开是否成功

	printf("请输入图书名称：\n");//信息从键盘录入 
	scanf(" %s", stu[*p].bookname);
	fprintf(fp, "   %s\t", stu[*p].bookname);

	printf("请输入借阅日期：\n");
	scanf(" %s", stu[*p].date);
	fprintf(fp, "   %s\t", stu[*p].date);

	printf("请输入借阅人：\n");
	scanf(" %s", stu[*p].borrower);
	fprintf(fp, "     %s\t", stu[*p].borrower);

	printf("请输入流水号：\n");
	scanf("%lld", &stu[*p].SerialNumber);
	if (cal(stu[*p].SerialNumber) > 15)
	{
		printf("超过15位，输入错误,请重新输入\n");
		scanf("%lld", &stu[*p].SerialNumber);
	}
	fprintf(fp, "     %d\t", stu[*p].SerialNumber);

	printf("请输入图书价格：\n");
	scanf("%f", &stu[*p].price);
	fprintf(fp, "      %.1f\t", stu[*p].price);


	printf("请输入借阅人ID号：\n");
	scanf("%lld", &stu[*p].id);
	if (cal(stu[*p].id) > 15)
	{
		printf("超过15位，输入错误,请重新输入\n");
		scanf("%lld", &stu[*p].id);
	}
	
	fprintf(fp, "     %d\n", stu[*p].id);

	fclose(fp);

	/*//判断这本书是否被借过 并计数
		if(*p==1)
		{
			for(i=0;stu[*p].bookname!='\0';i++)
			{
				zl[*p].bookname[i]=stu[*p].bookname[i];
			}
				zl[*p].bookname[i]=stu[*p].bookname[i];
				(zl[*p].xuhao)++;
		}


		for(i=0;i<*p;i++)
		{
			if(zl[i].bookname==stu[*p].bookname)
			{
				(zl[i].xuhao)++;
			}

			else
			{
				for(i=0;stu[*p].bookname!='\0';i++)
			{
				zl[*p].bookname[i]=stu[*p].bookname[i];
			}
				zl[*p].bookname[i]=stu[*p].bookname[i];
				(zl[*p].xuhao)++;
			}
		}
		*/
}


void paixu1(int* p, struct student stu[])//按id大到小排序输出 
{
	int i, j;
	struct student temp;//初始化 

	for (i = 0; i <= (*p); i++)
	{
		for (j = i + 1; j <= (*p); j++)
		{
			if (stu[i].id < stu[j].id)//如果大就交换 将大的往前排  //选择排序法 
			{
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}

	for (i = 0; i < (*p); i++)//输出排序结果 
	{
		printf("图书名称：");
		printf("%s\n", stu[i].bookname);

		printf("图书价格：");
		printf("%.1f\n", stu[i].price);

		printf("借阅日期：");
		printf("%s\n", stu[i].date);

		printf("流水号：");
		printf("%d\n", stu[i].SerialNumber);

		printf("借阅人：");
		printf("%s\n", stu[i].borrower);

		printf("借阅人ID号");
		printf("%d\n", stu[i].id);

		printf("-------------------------------------------------\n");
	}

	printf("排序完成！\n");

}


void find1(int* p, struct student stu[])//按图书名称查询借阅记录 
{
	int i, a, b = 0;
	char name[20];
	printf("请输入图书的名称：\n");
	scanf(" %s", name);
	for (i = 0; i <= *p; i++)
	{
		if (strcmp(stu[i].bookname, name) == 0)
		{
			b++;
			printf("图书《%s》的借阅记录如下：\n", stu[i].bookname);

			printf("价格：%.1f\n", stu[i].price);
			printf("借阅日期：%s\n", stu[i].date);
			printf("流水号：%d\n", stu[i].SerialNumber);
			printf("借阅人：%s\n", stu[i].borrower);
			printf("借阅人ID号：%d\n", stu[i].id);

			printf("------------------------------------------------------\n");
		}
	}
	if (b == 0) printf("找不到该图书对应的借阅记录！");
}


void find2(int* p, struct student stu[])//按借阅人姓名查询借阅记录 
{
	int i, a, b = 0;
	char name[20];
	printf("请输入借阅人姓名：\n");
	scanf(" %s", name);
	for (i = 0; i <= *p; i++)
	{
		if (strcmp(stu[i].borrower, name) == 0)
		{
			b++;
			printf("\n%s的借阅记录如下：\n", stu[i].borrower);

			printf("图书名称：%s\n", stu[i].bookname);
			printf("价格：%.1f\n", stu[i].price);
			printf("借阅日期：%s\n", stu[i].date);
			printf("流水号：%d\n", stu[i].SerialNumber);
			printf("借阅人ID号：%d\n", stu[i].id);

			printf("------------------------------------------------------\n");
		}
	}
	if (b == 0) printf("       找不到该人对应的借阅记录！");
}


void find3(int* p, struct student stu[])//查询价格最高和最低的书 （不存在价格相同的书）
{
	int i, max, min;
	max = min = 0;
	int j;
	struct student temp;//初始化 

	for (i = 0; i <= (*p); i++)
	{
		for (j = i + 1; j <= (*p); j++)
		{
			if (stu[i].price < stu[j].price)
			{
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}

	//输出结果
	printf("价格最高的书是:%s\n", stu[0].bookname);
	printf("其价格为：%.1f\n", stu[0].price);

	printf("价格最低的书是:%s\n", stu[*p-1].bookname);
	printf("其价格为：%.1f\n", stu[*p-1].price);

	printf("--------------------------------------------\n");

}




void find4(int *p,struct student stu[])//查找借阅次数最多的三本书
{
	int i;
	int j = 0;
	int t[100] = {0};
	int n = *p;
	int k = 0;
	//struct student s[100] = { 0 };
	//for (i = 0; i < 100; i++)
	//{
	//	s[i] = stu[i];
	//}
	//for (i = 0; i < n; i++)
	//{
	//	for (j = i + 1; j < n; j++)
	//		if (s[i].id == s[j].id)
	//		{
	//			for (k= j + 1; k < n; k++)//依次前移一位。
	//				s[k - 1] = s[k];
	//			n--;//总长度减一。
	//		}
	//}

	//for (i = 1; i <= n; i++)
	//{
	//	int ret = 0;
	//	for (j = 1; j <= n; j++)
	//	{
	//		if (s[i].id == s[j].id)
	//		{
	//			ret++;
	//		}
	//	}
	//	t[i - 1] = ret;
	//}

	//int temp;//初始化 
	//int r[100] = {0};
	//for (i = 0; i < 100; i++)
	//{
	//	r[i] = t[i];
	//}
	////int maxi = 0;
	////int max = t[0];
	////for (i = 0; i < 100; i++)
	////{
	////	if (t[i] > max)
	////	{
	////		maxi = i;
	////		max = t[i];
	////	}
	////}
	//for (i = 0; i < 100-1; i++)
	//{
	//	for (j = 0; j < 100-i-1; j++)
	//	{
	//		if (r[j] < r[j+1])
	//		{
	//			temp = r[j];
	//			r[j] = r[j+1];
	//			r[j+1] = temp;
	//		}
	//	}
	//}

	map<int, int> countMap;
	for (i = 1;i<=*p;i++)
	{
		map<int, int>::iterator it = countMap.find(stu[i].id);
		if (it != countMap.end())
		{
			it->second++;
		}
		else
		{
			countMap.insert(make_pair(stu[i].id, 1));
		}
	}

	int ie = 1;
	for (const auto& kv : countMap)
	{
		if (ie <=3)
		{
			cout << "借阅次数第"<<ie << "的ID是: " << kv.first << "   次数是：" << kv.second << endl;
			ie++;
		}
	}



	int a = 0, b = 0, c = 0;
	/*for (i = 0; i <= 100; i++)
	{
		
		if (a != 1 && t[i] == r[0])
		{
			a++;
			printf("借阅次数第1的是%d,借阅次数为%d次\n", stu[i+1].id,r[0]);
		}
		if (b != 1&& t[i] == r[1])
		{
			b++;
			printf("借阅次数第2的是%d,借阅次数为%d次\n", stu[i+2].id, r[1]);
		}
		if (c!= 1 && t[i] == r[2])
		{
			c++;
			printf("借阅次数第3的是%d,借阅次数为%d次\n", stu[i+3].id, r[2]);
		}
	}*/
	
}


int main()//主函数 
{
	int a, * p, h;
	char b;
	h = 0;
	p = &h;//图书种类的数组 
	//主函数的初始化 

	biaotou();//向文件录入一个表头 

	do
	{
		PrintfMenu();
		printf("请输入选项执行对应功能：\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1://信息录入 
			do
			{
				h++;
				WritetoFile(stu, p);
				printf("图书借阅信息录入成功！\n");
				printf("是否要录入下一条借阅信息？(Y/N)\n");
				scanf(" %c", &b);

			} while ((b == 'y') || (b == 'Y'));
			break;

		case 2://按id大到小排序输出 
			paixu1(p, stu);
			break;

		case 3://按图书名称查询借阅记录
			find1(p, stu);
			break;

		case 4://按借阅人姓名查询借阅记录
			find2(p, stu);
			break;

		case 5://查询价格最高和最低的书 
			find3(p, stu);
			break;

		case 6://查询借阅次数最多的三本书 
			find4(p,stu);
			break;

		case 0://退出系统 
			return 0;

		}
		printf("是否要退出程序？(Y/N)\n");
		scanf(" %c", &b);
	} while ((b == 'n') || (b == 'N'));



	return 0;
}
