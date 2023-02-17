//#define  _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
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
//    // 读取文件中的数据
//    while (fscanf(fp, "%s%d%d%d%d%d",
//        name, &id, &clas, &math, &english, &physics) != EOF)
//    {
//        // 构造插入语句
//        query = "INSERT INTO student (name, id, clas, math, english, physics) VALUES (?,?, ?, ?, ?,?)";
//        // 准备插入语句
//        stmt = mysql_stmt_init(conn);
//        if (mysql_stmt_prepare(stmt, query,strlen(query)) != 0) {
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
//    const char* filename = "wode.txt";
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

