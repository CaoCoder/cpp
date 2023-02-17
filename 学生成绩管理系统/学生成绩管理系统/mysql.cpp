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
//	MYSQL m;        //mysql连接
//	MYSQL_RES* res; //查询结果集
//	MYSQL_ROW row;  //二维数组，存放数据
//
//	//初始化数据库
//	mysql_init(&m);
//
//	//设置编码方式
//	mysql_options(&m, MYSQL_SET_CHARSET_NAME, "gbk");
//
//	//连接数据库
//	if (mysql_real_connect(&m, "localhost", "root", "yigebeiju123", "cc", 3306, NULL, 0))
//	{                           //主机       用户名   密码      数据库名  端口
//		printf("数据库连接成功\n");
//	}
//	else {
//		printf("数据库连接失败:%s \n", mysql_error(&m));
//		//输出错误信息
//	}
//
//	//向数据库插入数据
//	const char* sql = "insert into student values('张三',1,1,1,1,1)";
//	if (mysql_query(&m, sql))
//	{
//		printf("插入数据失败：%s \n", mysql_error(&m));
//	}
//	else
//	{
//		printf("插入数据成功\n");
//	}
//
//	////向数据库删除数据
//	//const char* sql_2 = "delete from student where name = '赵六'";
//	//if (mysql_query(&m, sql_2))
//	//{
//	//	printf("删除数据失败：%s \n", mysql_error(&m));
//	//}
//	//else
//	//{
//	//	printf("删除数据成功\n");
//	//}
//
//
//	////向数据库修改数据
//	//const char* sql_3 = "update student set id = 5 where name = '李四'";
//	//if (mysql_query(&m, sql_3))
//	//{
//	//	printf("修改数据失败：%s \n", mysql_error(&m));
//	//}
//	//else
//	//{
//	//	printf("修改数据成功\n");
//	//}
//
//	////需要注意的是，在下面的设置中，所查询到的数据 与打印出来的数据要相互匹配，
//	////不然就会出现乱码的
//	////查询数据
//	//const char* sql_4 = "select id,sex,name from student where name = '张三'";
//	//if (mysql_query(&m, sql_4))
//	//{
//	//	printf("未查到记录：%s \n", mysql_error(&m));
//	//}
//	//else
//	//{
//	//	printf("查询成功 \n");
//	//}
//	////获取查询结果集
//	//res = mysql_store_result(&m);
//	//if (res)
//	//{
//	//	printf("获取到数据\n");
//	//}
//	//else
//	//{
//	//	printf("未获取到数据：%s \n", mysql_error(&m));
//	//}
//	////打印获取到的数据
//	//printf("id\tname\tsex\n");
//	//while (row = mysql_fetch_row(res))
//	//{
//	//	printf("%s\t%s\t%s\n", row[0], row[1], row[2]);
//	//}
//	//释放资源
//	//mysql_free_result(res);//释放结果集
//	//mysql_close(&m);//关闭数据库
//}
//
//
//
