#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX_LEN 100
#define NOT_FOUND-1
struct line//行与行之间的结构
{
    char text[100];//输入文本，本行最多100个字符
    int num;
    struct line* pro;//指向上一行的指针结构
    struct line* next;//指向下一行的指针结构
};
int lnum;
struct line* start; 	   //指向线性表中第一行的指针
struct line* last; 	   //指向线性表中最后一行的指针
struct line* find(int);    //查找指定行是否存在
void patchup(int, int);    //对当前行以后的每行的行号加1或减1
void delete_text(int);     //删除一行文字
void list();   //显示文件的全部内容
void save();   //保存文件
void load();   //打开文件，初始化线性表
void insert(char str[], int linenum, int position); //插入文字到一行的中间
void printline(int linenum);   //打印一行文字
void deletestr(int linenum, int position, int lenth); //删除一个字符串
int findstr(char* to_find);  //查找字符串
int menu_select();        //显示主菜单
int menu_select_insert();//显示插入功能子菜单
int menu_select_delete();//显示删除功能子菜单
int menu_select_print(); //显示打印功能子菜单
int menu_select_move();  //显示移动功能子菜单
void enter(int linenum); //插入一行文字
void enter_empty(int linenum); //插入一个空白行

//显示菜单进行选择 ，下列功能为主菜单功能选项
int menu_select()
{
    int c;
    printf("\n\t\t1.插入\n");
    printf("\t\t2.删除\n");
    printf("\t\t3.显示\n");
    printf("\t\t4.移动\n");
    printf("\t\t5.替换\n");
    printf("\t\t6.文件存盘\n");
    printf("\t\t7.装入文件\n");
    printf("\t\t8.退出\n");
    do
    {
        printf("\n\n\t\t请按数字选择：");
        scanf("%d", &c);
    } while (!(c >= 1 && c <= 9));
    return;
}
//下列是删除 功能子菜单的提示界面
int menu_select_delete()
{
    int c;
    printf("\n\t\t1.删除一行文字\n");
    printf("\t\t2.删除一段文字\n");
    printf("\t\t3.返回上级菜单\n");
    do {
        printf("\n\n\t\t请按数字选择：");
        scanf("%d", &c);
    } while (!(c >= 1 && c <= 3));
    return;
}
//下列是插入子菜单 的提示，插入菜单的选项
int menu_select_insert()
{
    int c;
    printf("\n\t\t1.插入一行\n");
    printf("\t\t2.插入一段文字\n");
    printf("\t\t3.返回上级菜单\n");
    do
    {
        printf("\n\n\t\t请按数字选择：");
        scanf("%d", &c);
    } while (!(c >= 1 && c <= 3));
    return;
}
//下列是显示子菜单，说明显示功能下的选项
int menu_select_printf()
{
    int c;
    printf("\n\t\t1.显示一行\n");
    printf("\t\t2.全部显示\n");
    printf("\t\t3.返回上级菜单\n");
    do
    {
        printf("\n\n\t\t请按照数字选择：");
        scanf("%d", &c);
    } while (!(c >= 1 && c <= 3));
    return;
}
//下列函数是移动子菜单，显示移动的选项
int menu_select_move()
{
    int c;
    printf("\n\t\t1.向下移动一行\n");
    printf("\t\t2.向上移动一行\n");
    printf("\t\t3.向右移动一列\n");
    printf("\t\t5.返回上级菜单\n");
    do
    {
        printf("\n\n\t请按照数字选择：");
        scanf("%d", &c);
    } while (!(c >= 1 && c <= 5));
    return;
}
//下列函数是执行插入的函数
void  enter(int linenum)
{
    struct line* info, * q, * p;//运用结构中的指针
    p = start;//头指针
    q = NULL;
    while (p && p->num != linenum)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL && (q->num + 1) != linenum)
        printf("指定行不存在\n");
    else
    {
        info = (struct line*)malloc(sizeof(struct line));//为将要输入的分配空间
        printf("输入要进行输入的字符串\n");
        scanf("%s", info->text);
        info->num = linenum;
        if (linenum == 1)//插入在第一行
        {
            info->next = p;
            p->pro = info;
            info->pro = NULL;
            start = info;
        }
        else if (q->num != linenum)//插入最后一排
        {
            q->next = info;
            info->next = p;
            info->pro = q;
        }
        else//插入其他行
        {
            q->next = info;
            info->next = p;
            p->pro = info;
            info->pro = q;
        }
        while (p)//除去插入在最后一行的情况，其余的行号加一
        {
            p->num = p->num + 1;
            p = p->next;//指针后移一位
        }
    }
}
//若进行删除或不是在最后一行进行添加，则从这以后的每一行都行号减一
void patchup(int n, int incr)
{
    struct line* i;//行指针变量
    i = find(n);
    i = i->next;
    while (i)
    {
        i->num = i->num + incr;
        i = i->next;
    }
}

//在指定位置插入空格
void enter_empty(int linenum)
{
    struct line* info, * p;
    info = (struct line*)malloc(sizeof(struct line));
    if (!info)
    {
        printf("\t!内存不够\n");
        return;
    }
    info->num = linenum;
    info->text[0] = ' ';//以文本数组的方式进行
    info->text[1] = '\0';
    if (find(linenum))
    {
        p = start;
        if (linenum = 1)
        {
            info->next = p;
            start = info;
            info->pro = NULL;
            p->pro = info;//以链表的形式进行添加
        }
        else
        {
            while (p->next->num != linenum)
                p = p->next;//p为表头第一个元素的指针，所以添加时，要用到他下一个的位置
            info->next = p->next;
            p->next->pro = info;
            info->pro = p;
        }
        patchup(linenum, 1);//以一个数进行添加
    }
    else
        printf("该行不存在\n");
}
//进行插入文字到某一行，如果要插入的和与原有的 中间有空格，进行补全
void insert(char str[], int linenum, int position)
{
    struct line* info;
    int len, i, lenth;
    char rest_str[MAX_LEN], nostr[2] = { " " };
    info = start;
    while (info && info->num != linenum)
    {
        info = info->next;
    }
    if (info == NULL)
        printf("不存在该行\n");
    else if (position < 0)
        printf("不存在该列\n");
    else//二维数组中两个变量都存在，进行插入
    {
        lenth = strlen(info->text);
        if (lenth < position)//进行插入的列大于文件规定的列的数
        {
            len = position - lenth - 1;
            for (i = 0; i < len; i++)

                strcat((char*)info->next, nostr);//将空格拼接到字符中
            strcat(info->text, str);
        }
        else//插入到文本中央的情况
        {
            strcpy(rest_str, &info->text[position - 1]);
            strcpy(&info->text[position - 1], str);
            strcat(info->text, rest_str);
        }
    }
}
//下列函数是执行删除指定行的功能
void delete_text(int linenum)
{
    struct line* info, * p;
    info = start;
    while (info->num = linenum && info)
        info = info->next;
    if (info->next == NULL)
        printf("不存在\n");//因为是头指针的链表数指向下一个指针
    else
    {
        p = info->next;
        if (start == info)//如果删除的是第一行
        {
            start = info->next;
            if (start)//如果删除后，不为空
                start->pro = NULL;
            else//删除后为空
                last = NULL;
        }
        else
        {
            info->pro->next = info->next;//将所指定行的上一行指向其下一行
            if (info != last)
                info->next->pro = info->pro;//修改其下一行的指针
            else
                last = info->pro;//将最后的尾指针，指向其删除行的上一行将其连结

        }
        free(info);//释放所在行的内存
        while (p)
        {
            p->num = p->num - 1;
            p = p->next;//将其行数进行修改
        }
    }
}
//删除指定行列的长度为length的文字
void deletestr(int linenum, int position, int length)
{
    struct line* info;
    char rest_str[MAX_LEN];
    info = find(linenum);
    if (info == NULL)
        printf("该行不存在\n");
    else//删除后，将文字前后进行连结
    {
        if (strlen(info->text) <= (position + length))//判断要进行删除的文字的长度是否合适
            info->text[position] = '\0';
        else
        {
            strcpy(rest_str, &info->text[position + length]);
            strcpy(&info->text[position], rest_str);
        }
    }
}
//查找功能，查找一段文字
int findstr(char* to_find)
{
    struct line* info;
    int i = 0, find_len, found = 0, position;
    char substring[MAX_LEN];
    info = start;
    lnum = 0;
    find_len = strlen(to_find);
    while (info && !found)//查询
    {
        i = 0;
        while (!found && (i <= strlen(info->text) - find_len))//进行行内查找
        {
            strcpy(substring, &info->text[i]);
            substring[find_len] = '\0';
            if (strcmp(substring, to_find) == 0)
            {
                found = 1;
                lnum = info->num;
            }
            else
                ++i;
        }
        info = info->next;
    }
    if (found)//查找成功
        position = i;
    else
        position = NOT_FOUND;
    return(position);
}
//查找指定行
struct line* find(int linenum)
{
    struct line* info;
    info = start;
    while (info)
    {
        if (linenum != info->num)
            info = (line*)info->num;
        else
            break;
    }
    return;
};
//执行显示指定功能
void printline(int linenum)
{
    struct line* info;
    info = find(linenum);
    if (info)
        printf("%d %s\n", info->num, info->text);
    else
        printf("该行不存在\n");
}
//执行显示全部文本内容
void list()
{
    struct line* info;
    info = start;//将指针从线性表的头部进行遍历
    while (info)//循环读出
    {
        printf("%d %s\n", info->num, info->text);
        info = info->next;
    }
    printf("\n");
}
//执行文本保存功能，将线性表保存在文件中
void save()
{
    struct line* info;
    char* p;
    FILE* fp = NULL;
    fopen("text.txt", "w");
    //if((fp==fopen("D:\text.txt","w"))==NULL)

    //{
        //printf("\t1文件打不开\n");
        //return;
    //}
    printf("\t正在输入文件\n");
    info = start;
    while (info)//执行输入 ，一个一个的输入
    {
        p = info->text;
        while (*p)
            fputc(*p++, fp);
        fputc('\n', fp);
        info = info->next;
    }
    fclose(fp);
}
//将文本文件的内容读入线性表，将线性表的结构在文件中进行显示
void load()
{
    struct line* info, * temp;//两个指针，一个指向当前行，一个指向其上一行
    char c;
    FILE* fp = NULL;
    int inct, i;//行计数
    temp = NULL;
    fopen("text.txt", "r");
    if ((fp == fopen("text.txt", "r")) == NULL)
    {
        printf("\t2文件打不开\n");
        return;
    }
    //printf("\t正在装入文件\n");
    start = (struct line*)malloc(sizeof(struct line));//为行分配空间
    info = start;
    inct = 1;
    while ((c = fgetc(fp) != EOF))//当文件没有结束时
    {
        i = 0;
        info->text[i] = c;
        i++;
        while ((c = fgetc(fp)) != '\n')//当文件读入字符到线性表，以\n为标志结束
        {
            info->text[i] = c;
            i++;
        }
        info->text[i] = '\0';//每一行结尾的标志
        info->num = inct++;//行计数加1
        info->next = (struct line*)malloc(sizeof(struct line));
        if (!info->next)
        {
            printf("\n\t内存已经用完\n");
            return;
        }
        info->pro = temp;
        temp = info;
        info = info->next;//循环进行，进行上下行的 滚动
    }
    temp->next = NULL;
    last = temp;//当进行到结尾时
    free(info);
    start->pro = NULL;
    fclose(fp);
}
int main()
{
    printf("欢迎进入编译器\n");
    //建立文件进行储存，并显示内容
    char str[100];
    int choice;//进行选项的数目
    int linenum = 1;//行数初始化
    int colnum = 0;//列号初始化
    start = NULL;
    last = NULL;
    load();//进行函数调用，打开主菜单
    do
    {
        choice = menu_select();
        switch (choice)//对主菜单功能进行选择
        {
        case 1://执行插入功能
            choice = menu_select_insert();
            switch (choice)
            {
            case 1:
                printf("输入要进行插入的行号\n");
                scanf("%d", &linenum);
                enter(linenum);//调用函数
                break;
            case 2:
                printf("输入插入的行号\n");
                scanf("%d", &linenum);
                printf("输入要插入的列号\n");
                scanf("%d", &colnum);
                printf("输入要插入的字符\n");
                scanf("%s", &str);
                insert(str, linenum, colnum);
                break;
            case 3:
                break;
            }
            break;

        case 2://删除功能
            choice = menu_select_delete();
            switch (choice)
            {
            case 1:
                printf("输入要删除的行数\n");
                scanf("%d", &linenum);
                delete_text(linenum);
                break;
            case 2:
                printf("输入要删除的字符\n");
                scanf("%s", &str);
                colnum = findstr(str);
                if (colnum == NOT_FOUND)
                    printf("没有找到\n");
                else
                    deletestr(linenum, colnum, strlen(str));
                break;
            case 3:
                break;
            }
            break;
        case 3://执行显示内容的功能
            choice = menu_select_printf();//显示功能的主菜单
            switch (choice)
            {
            case 1://显示部分内容
                printf("输入要显示的行号\n");
                scanf("%d", &linenum);
                printline(linenum);
                break;
            case 2://显示全部内容
                list();
                break;
            case 3://退出显示
                break;
            }
            break;
        case 4://执行移动功能
            choice = menu_select_move();//显示功能的主菜单
            switch (choice)
            {
            case 1://整行下移
                printf("输入要移动的行号\n");
                scanf("%d", &linenum);
                enter_empty(linenum);//在本行加入空行
                break;
            case 2://整行上移
                printf("输入要移动的行号\n");
                scanf("%d", &linenum);
                delete_text(linenum - 1);
                break;
            case 3://向左移动字符串
                printf("输入要移动的字符所在行号\n");
                scanf("%d", &linenum);
                printf("输入要移动的字符所在列号\n");
                scanf("%d", &colnum);
                if (colnum <= 0)
                    printf("该列不存在");
                else
                    deletestr(linenum, colnum - 2, 1);
                break;
            case 4://向右移动字符串
                printf("输入要移动的字符所在行号\n");
                scanf("%d", &linenum);
                printf("输入要移动的字符所在列号\n");
                scanf("%d", &colnum);
                if (colnum <= 0)
                    printf("该列不存在");
                else
                    deletestr(linenum, colnum + 2, 1);
                break;
            case 5://退出移动
                break;
            }
            break;
        case 5://替换功能
            printf("输入需要被替换的字符串\n");
            scanf("%s", str);
            colnum = findstr(str);
            if (colnum == NOT_FOUND)
                printf("没有找到\n");
            else
            {
                deletestr(linenum, colnum, strlen(str));
                printf("要替换的字符串\n");
                scanf("%d", &str);
                insert(str, linenum, colnum);
            }
            break;
        case  6://进行储存文件功能
            save();
            break;
        case 7://进行读入文件
            load();
            break;
        case 8://退出编译器
            break;
        }
    } while (1);
    return 0;
}