//#include <iostream>
//using namespace std;
//
//#include <WinSock.h>
//#include <mysql.h>
//void test();
//int main()
//{
//	cout << "main" << endl;
//
//	test();
//	getchar();
//	return 0;
//}
//
//void test()
//{
//	printf("test\n");
//
//	MYSQL m;        //mysql����
//	MYSQL_RES* res; //��ѯ�����
//	MYSQL_ROW row;  //��ά���飬�������
//
//	//��ʼ�����ݿ�
//	mysql_init(&m);
//
//	//���ñ��뷽ʽ
//	mysql_options(&m, MYSQL_SET_CHARSET_NAME, "gbk");
//
//	//�������ݿ�
//	if (mysql_real_connect(&m, "localhost", "root", "yigebeiju123", "cc", 3306, NULL, 0))
//	{                           //����       �û���   ����      ���ݿ���  �˿�
//		printf("���ݿ����ӳɹ�\n");
//	}
//	else {
//		printf("���ݿ�����ʧ��:%s \n", mysql_error(&m));
//		//���������Ϣ
//	}
//
//	//�����ݿ��������
//	const char* sql = "insert into student values('����',1,1,1,1,1)";
//	if (mysql_query(&m, sql))
//	{
//		printf("��������ʧ�ܣ�%s \n", mysql_error(&m));
//	}
//	else
//	{
//		printf("�������ݳɹ�\n");
//	}
//
//	////�����ݿ�ɾ������
//	//const char* sql_2 = "delete from student where name = '����'";
//	//if (mysql_query(&m, sql_2))
//	//{
//	//	printf("ɾ������ʧ�ܣ�%s \n", mysql_error(&m));
//	//}
//	//else
//	//{
//	//	printf("ɾ�����ݳɹ�\n");
//	//}
//
//
//	////�����ݿ��޸�����
//	//const char* sql_3 = "update student set id = 5 where name = '����'";
//	//if (mysql_query(&m, sql_3))
//	//{
//	//	printf("�޸�����ʧ�ܣ�%s \n", mysql_error(&m));
//	//}
//	//else
//	//{
//	//	printf("�޸����ݳɹ�\n");
//	//}
//
//	////��Ҫע����ǣ�������������У�����ѯ�������� ���ӡ����������Ҫ�໥ƥ�䣬
//	////��Ȼ�ͻ���������
//	////��ѯ����
//	//const char* sql_4 = "select id,sex,name from student where name = '����'";
//	//if (mysql_query(&m, sql_4))
//	//{
//	//	printf("δ�鵽��¼��%s \n", mysql_error(&m));
//	//}
//	//else
//	//{
//	//	printf("��ѯ�ɹ� \n");
//	//}
//	////��ȡ��ѯ�����
//	//res = mysql_store_result(&m);
//	//if (res)
//	//{
//	//	printf("��ȡ������\n");
//	//}
//	//else
//	//{
//	//	printf("δ��ȡ�����ݣ�%s \n", mysql_error(&m));
//	//}
//	////��ӡ��ȡ��������
//	//printf("id\tname\tsex\n");
//	//while (row = mysql_fetch_row(res))
//	//{
//	//	printf("%s\t%s\t%s\n", row[0], row[1], row[2]);
//	//}
//	//�ͷ���Դ
//	//mysql_free_result(res);//�ͷŽ����
//	//mysql_close(&m);//�ر����ݿ�
//}
//
//
//
