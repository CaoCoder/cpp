//#define  _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <mysql.h>
///*�����ݿ���д���ļ�*/
//int WriteMysql()
//{
//    MYSQL* conn;
//    MYSQL_STMT* stmt;
//    const char* query;
//    const char* filename = "data.txt";
//    FILE* fp;
//    char name[20];
//    int id, clas, math, english, physics;
//    // ���ļ�
//    fp = fopen(filename, "r");
//    if (fp == NULL) {
//        printf("Error opening file!\n");
//        return -1;
//    }
//    // �������ݿ�
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
//        printf("���ӳɹ�\n");
//    }
//    // ��ȡ�ļ��е�����
//    while (fscanf(fp, "%s%d%d%d%d%d",
//        name, &id, &clas, &math, &english, &physics) != EOF)
//    {
//        // ����������
//        query = "INSERT INTO student (name, id, clas, math, english, physics) VALUES (?,?, ?, ?, ?,?)";
//        // ׼���������
//        stmt = mysql_stmt_init(conn);
//        if (mysql_stmt_prepare(stmt, query,strlen(query)) != 0) {
//            printf("Error preparing statement!\n");
//            return -1;
//        }
//        // ִ�в������
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
//    // �ر��ļ�
//    fclose(fp);
//    // �ر����ݿ�����
//    mysql_close(conn);
//
//}
///*�����ݿ��ж�ȡ�ļ�*/
//int ReadMysql()
//{
//    MYSQL* conn;
//    MYSQL_STMT* stmt;
//    const char* query;
//    const char* filename = "wode.txt";
//    FILE* fp;
//    char name[20];
//    int id, clas, math, english, physics;
//    // ���ļ�
//    fp = fopen(filename, "w");
//    if (fp == NULL) {
//        printf("Error opening file!\n");
//        return -1;
//    }
//    // �������ݿ�
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
//        printf("���ӳɹ�\n");
//    }
//    // �����ѯ���
//    query = "SELECT name, id, clas, math, english, physics FROM student";
//    // ׼����ѯ���
//    stmt = mysql_stmt_init(conn);
//    if (mysql_stmt_prepare(stmt, query, strlen(query)) != 0) {
//        printf("Error preparing statement!\n");
//        return -1;
//    }
//    // ִ�в�ѯ���
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
//    // ��ȡ��ѯ���
//    while (mysql_stmt_fetch(stmt) == 0) {
//        fprintf(fp, "%s %d %d %d %d %d\n",
//            name, id, clas, math, english, physics);
//    }
//    // �ر��ļ�
//    fclose(fp);
//    // �ر����ݿ�����
//    mysql_close(conn);
//}

