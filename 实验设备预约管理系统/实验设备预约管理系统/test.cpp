#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EQUIPMENTS 100 // 最多100个设备
#define MAX_USERS 100 // 最多100个用户
#define MAX_RESERVATIONS 1000 // 最多1000个预约记录
#define MAX_ID_LENGTH 100//最大的设备id记录
// 设备结构体
struct Equipment {
    char name[50]; // 设备名称
    char id[20]; // 设备编号
    char type[20]; // 设备类型
    char status[20]; // 设备状态（0-空闲，1-已预约）
    float price; // 设备价格
    int num_reserved; // 已预约次数
};

// 用户结构体
struct User {
    char name[50]; // 用户名
    char id[20]; // 职工号
    char password[20]; // 密码
};

// 预约记录结构体
struct Reservation {
    char equipment_id[20]; // 设备编号
    char user_id[20]; // 用户职工号
    char time[20]; // 预约时间
};
// 全局变量
struct Equipment equipments[MAX_EQUIPMENTS]; // 设备列表
int num_equipments = 0; // 设备数量
struct User users[MAX_USERS]; // 用户列表
int num_users = 0; // 用户数量
struct Reservation reservations[MAX_RESERVATIONS]; // 预约记录列表
int num_reservations = 0; // 预约记录数量


// 添加设备
void add_equipment(struct Equipment* equipments, int* num_equipments) {
    printf("请输入设备名称：");
    scanf("%s", equipments[*num_equipments].name);
    printf("请输入设备编号：");
    scanf("%s", equipments[*num_equipments].id);
    printf("请输入设备类型：");
    scanf("%s", equipments[*num_equipments].type);
    printf("请输入设备状态：");
    scanf("%s", equipments[*num_equipments].status);
    printf("请输入设备价格：");
    scanf("%f", &equipments[*num_equipments].price);
    equipments[*num_equipments].num_reserved = 0; // 初始已预约次数为0
    (*num_equipments)++; // 设备数量加1
    printf("设备添加成功！\n");
}


// 修改设备信息
void modify_equipment(struct Equipment* equipments, int num_equipments) {
    char id[MAX_ID_LENGTH];
    printf("请输入需要修改信息的设备编号：");
    scanf("%s", id);
    for (int i = 0; i < num_equipments; i++) {
        if (strcmp(equipments[i].id, id) == 0) {
            printf("请输入新的设备名称：");
            scanf("%s", equipments[i].name);
            printf("请输入新的设备类型：");
            scanf("%s", equipments[i].type);
            printf("请输入新的设备状态：");
            scanf("%s", equipments[i].status);
            printf("请输入新的设备价格：");
            scanf("%f", &equipments[i].price);
            printf("设备信息修改成功！\n");
            return;
        }
    }
    printf("未找到设备编号为%s的设备，请检查输入是否正确！\n", id);
}
//查找
int find_equipment(struct Equipment* equipments, int num_equipments, char* equipment_id) {
    for (int i = 0; i < num_equipments; i++) {
        if (strcmp(equipments[i].id, equipment_id) == 0) {
            return i;
        }
    }
    return -1;
}

// 删除设备
void delete_equipment(struct Equipment* equipments, int* num_equipments) {
    char equipment_id[MAX_ID_LENGTH]; // 定义一个字符数组，用于输入设备编号
    int index; // 设备在数组中的索引

    printf("请输入要删除的设备编号：");
    scanf("%s", equipment_id);

    index = find_equipment(equipments, *num_equipments, equipment_id);

    if (index == -1) { // 设备不存在，输出提示信息
        printf("设备不存在！\n");
    }
    else { // 设备存在，进行删除操作
        for (int i = index; i < (*num_equipments - 1); i++) { // 将删除设备后面的设备往前移动
            equipments[i] = equipments[i + 1];
        }
        (*num_equipments)--; // 设备数组元素个数减一
        printf("设备删除成功！\n");
    }
}



// 添加用户
void add_user(struct User* users, int* num_users) {
    // 判断是否已达到最大用户数
    if (*num_users >= MAX_USERS) {
        printf("已达到最大用户数，无法添加新用户！\n");
        return;
    }

    // 输入用户信息
    printf("请输入用户名：");
    scanf("%s", users[*num_users].name);
    printf("请输入职工号：");
    scanf("%s", users[*num_users].id);
    printf("请输入初始密码：");
    scanf("%s", users[*num_users].password);

    // 增加用户数
    (*num_users)++;

    printf("添加用户成功！\n");
}

int find_user(struct User* users, int num_users, char* username) {
    // 遍历用户数组，查找与指定用户名相同的用户
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, username) == 0) {
            return i; // 返回找到的用户在数组中的索引
        }
    }
    return -1; // 没有找到用户，返回 -1
}

//修改用户信息
void modify_user(struct User* users, int num_users) {
    char input[100];

    printf("请输入要修改的用户的职工号：");
    scanf("%s", input);

    int index = find_user(users, num_users, input);
    if (index == -1) {
        printf("用户不存在！\n");
        return;
    }

    printf("请输入用户姓名：");
    scanf("%s", users[index].name);

    printf("请输入用户密码：");
    scanf("%s", users[index].password);

    printf("用户信息修改成功！\n");
}
//删除用户信息
void delete_user(struct User* users, int* num_users) {
    char user_id[MAX_ID_LENGTH];
    printf("请输入要删除的用户ID：");
    scanf("%s", user_id);
    int index = find_user(users, *num_users, user_id);
    if (index == -1) {
        printf("用户不存在！\n");
        return;
    }
    // 将最后一个用户的信息覆盖到待删除的位置
    users[index] = users[(*num_users) - 1];
    (*num_users)--;
    printf("用户删除成功！\n");
}

// 录入预约信息
void add_reservation(struct Reservation* reservations, int* num_reservations, struct Equipment* equipments,
    int num_equipments, struct User* users, int num_users) {
    // 获取预约信息
    struct Reservation reservation;
    printf("请输入预约信息：\n");
    printf("设备编号：");
    scanf("%s", reservation.equipment_id);
    printf("申请人工号：");
    scanf("%s", reservation.user_id);
    printf("预约时间：");
    scanf("%s", reservation.time);

    // 查找设备是否存在
    int index = find_equipment(equipments, num_equipments, reservation.equipment_id);
    if (index == -1) {
        printf("设备不存在！\n");
        return;
    }

    // 查找用户是否存在
    index = find_user(users, num_users, reservation.user_id);
    if (index == -1) {
        printf("用户不存在！\n");
        return;
    }

    // 添加预约信息到数组中
    reservations[*num_reservations] = reservation;
    *num_reservations += 1;

    printf("预约成功！\n");
}


// 查询所有设备的预约信息
void display_all_reservations(struct Reservation* reservations, int num_reservations) {
    if (num_reservations == 0) {
        printf("暂无预约信息\n");
        return;
    }
    printf("所有设备的预约信息如下：\n");
    printf("设备编号\t申请人\t\t预约时间\n");
    for (int i = 0; i < num_reservations; i++) {
        printf("%s\t\t%s\t\t%s\n", reservations[i].equipment_id, reservations[i].user_id, reservations[i].time);
    }
}


// 查询某个设备的预约信息
void display_equipment_reservations(struct Reservation* reservations, int num_reservations) {
    char equipment_id[10];
    int count = 0;

    printf("请输入要查询的设备id：");
    scanf("%s", equipment_id);

    printf("设备 %s 的预约信息如下：\n", equipment_id);
    printf("%-10s%-15s%-25s\n", "设备id", "申请人", "预约时间");

    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(reservations[i].equipment_id, equipment_id) == 0) {
            printf("%-10s%-15s%-25s\n", reservations[i].equipment_id, reservations[i].user_id, reservations[i].time);
            count++;
        }
    }

    if (count == 0) {
        printf("没有找到设备 %s 的预约信息。\n", equipment_id);
    }
}



// 查询所有用户的预约信息
void display_all_user_reservations(struct Reservation* reservations, int num_reservations, struct User* users, int num_users) {
    printf("所有用户的预约信息如下：\n");
    printf("%-10s%-15s%-25s%-15s\n", "设备编号", "申请人", "预约时间", "用户ID");
    for (int i = 0; i < num_reservations; i++) {
        struct Reservation reservation = reservations[i];
        struct User user = users[find_user(users, num_users, reservation.user_id)];
        printf("%-10s%-15s%-25s%-15s\n", reservation.equipment_id, user.name, reservation.time, user.id);
    }
}


// 查询某个用户的预约信息
void display_user_reservations(struct Reservation* reservations, int num_reservations) {
    char user_name[50];
    int count = 0;

    printf("请输入要查询预约信息的用户姓名：");
    scanf("%s", user_name);

    printf("预约信息查询结果：\n");
    printf("%-10s%-15s%-25s\n", "设备编号", "申请人", "预约时间");
    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(reservations[i].user_id, user_name) == 0) {
            printf("%-10s%-15s%-25s\n", reservations[i].equipment_id, reservations[i].user_id, reservations[i].time);
            count++;
        }
    }

    if (count == 0) {
        printf("没有找到 %s 的预约信息.\n", user_name);
    }
}



// 更改用户的预约信息
void modify_user_reservation(struct Reservation* reservations, int num_reservations) {
    char user_name[50];
    printf("请输入预约者姓名：");
    scanf("%s", user_name);

    // 查找该用户的所有预约信息
    int count = 0;
    printf("\n预约者 %s 的预约信息如下：\n", user_name);
    printf("%-15s%-10s%-25s\n", "预约者", "设备", "预约时间");
    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(reservations[i].user_id, user_name) == 0) {
            printf("%-15s%-10s%-25s\n", reservations[i].user_id, reservations[i].equipment_id, reservations[i].time);
            count++;
        }
    }
    if (count == 0) {
        printf("该用户未进行过预约。\n");
        return;
    }

    // 修改预约信息
    char equipment_id[50], new_time[50];
    printf("\n请输入要修改预约时间的设备编号：");
    scanf("%s", equipment_id);
    printf("请输入新的预约时间：");
    scanf("%s", new_time);

    int modified = 0;
    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(reservations[i].user_id, user_name) == 0 && strcmp(reservations[i].equipment_id, equipment_id) == 0) {
            strcpy(reservations[i].time, new_time);
            printf("\n预约信息修改成功！\n");
            modified = 1;
            break;
        }
    }
    if (!modified) {
        printf("\n未找到该设备的预约信息，预约信息修改失败。\n");
    }
}

// 保存预约信息
void save_reservations(struct Reservation* reservations, int num_reservations) {
    FILE* fp;
    fp = fopen("data.txt", "w"); // 打开文件

    if (fp == NULL) { // 判断文件是否成功打开
        printf("无法打开文件.\n");
        return;
    }

    for (int i = 0; i < num_reservations; i++) {
        fprintf(fp, "%s,%s,%s\n", reservations[i].equipment_id, reservations[i].user_id, reservations[i].time);
    }

    fclose(fp); // 关闭文件
    printf("预约信息已保存到data.txt文件中.\n");
}
//加载预约信息
void load_reservations(struct Reservation* reservations, int* num_reservations) {
    FILE* fp;
    fp = fopen("data.txt", "r"); // 打开文件

    if (fp == NULL) { // 判断文件是否成功打开
        printf("无法打开文件.\n");
        return;
    }

    char line[100];
    int i = 0;

    while (fgets(line, 100, fp)) {
        sscanf(line, "%[^,],%[^,],%s", reservations[i].equipment_id, reservations[i].user_id, reservations[i].time);
        i++;
    }

    *num_reservations = i;

    fclose(fp); // 关闭文件
    printf("预约信息已从data.txt文件中加载.\n");
}


// 按设备名查询设备信息
void search_equipment_by_name(char* name) {
    int i;
    int count = 0; // 记录查询到的设备数量

    // 遍历设备列表
    for (i = 0; i < num_equipments; i++) {
        if (strcmp(name, equipments[i].name) == 0) {
            printf("设备名称：%s\n", equipments[i].name);
            printf("设备编号：%s\n", equipments[i].id);
            printf("设备类型：%s\n", equipments[i].type);
            printf("设备状态：%s\n", equipments[i].status);
            printf("设备价格：%f\n", equipments[i].price);
            printf("已预约次数：%d\n", equipments[i].num_reserved);
            printf("\n");
            count++;
        }
    }

    if (count == 0) {
        printf("未找到匹配的设备.\n");
    }
}
// 根据设备号查询设备信息
void search_equipment_by_id(char* id) {
    int found = 0;
    for (int i = 0; i < num_equipments; i++) {
        if (strcmp(equipments[i].id, id) == 0) {
            found = 1;
            printf("设备名称：%s\n", equipments[i].name);
            printf("设备编号：%s\n", equipments[i].id);
            printf("设备类型：%s\n", equipments[i].type);
            printf("设备状态：%s\n", equipments[i].status);
            printf("设备价格：%.2f\n", equipments[i].price);
            printf("已预约次数：%d\n", equipments[i].num_reserved);
            break;
        }
    }
    if (!found) {
        printf("未找到设备号为%s的设备\n", id);
    }
}
// 根据设备类型查询设备信息
void search_equipment_by_type(char* type) {
    int found = 0; // 是否找到设备的标志
    printf("查询结果：\n");
    for (int i = 0; i < num_equipments; i++) {
        if (strcmp(equipments[i].type, type) == 0) {
            printf("设备名称：%s\n", equipments[i].name);
            printf("设备编号：%s\n", equipments[i].id);
            printf("设备类型：%s\n", equipments[i].type);
            printf("设备状态：%s\n", equipments[i].status);
            printf("设备价格：%.2f\n", equipments[i].price);
            printf("已预约次数：%d\n", equipments[i].num_reserved);
            found = 1;
        }
    }
    if (!found) {
        printf("未找到设备。\n");
    }
}
//按照设备价格进行排序
void sort_equipments_by_price() {
    int i, j;
    struct Equipment temp;

    for (i = 0; i < num_equipments - 1; i++) {
        for (j = 0; j < num_equipments - 1 - i; j++) {
            if (equipments[j].price > equipments[j + 1].price) {
                // 交换位置
                temp = equipments[j];
                equipments[j] = equipments[j + 1];
                equipments[j + 1] = temp;
            }
        }
    }

    printf("设备按价格排序成功！\n");
}

//按照类型统计
void count_equipments_by_type() {
    int num_types = 0; // 设备类型数量
    char types[MAX_EQUIPMENTS][20]; // 设备类型数组
    int counts[MAX_EQUIPMENTS]; // 设备类型数量数组
    memset(counts, 0, sizeof(counts)); // 将数组清零

    // 遍历设备列表，统计不同类型的设备数量
    for (int i = 0; i < num_equipments; i++) {
        int found = 0;
        for (int j = 0; j < num_types; j++) {
            if (strcmp(equipments[i].type, types[j]) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(types[num_types], equipments[i].type);
            counts[num_types] = 1;
            num_types++;
        }
    }

    // 输出统计结果
    printf("统计结果如下：\n");
    for (int i = 0; i < num_types; i++) {
        printf("%s: %d\n", types[i], counts[i]);
    }
}


         
void menu()
{
    printf("*****************************\n");
    printf("*****************************\n");
    printf("*****************************\n");
    printf("******1.设备管理模块   ******\n");
    printf("******2.用户管理模块   ******\n");
    printf("******3.设备预约管理模块*****\n");
    printf("******4.信息统计查询模块*****\n");
    printf("******5.退出            *****\n");
    printf("*****************************\n");
    printf("请选择(1-5):");
}
void EquipmentMenu()
{
    printf("*****欢迎来到设备管理界面**\n");
    printf("***************************\n");
    printf("***************************\n");
    printf("******1.添加设备       ****\n");
    printf("******2.修改设备信息   ****\n");
    printf("******3.删除设备       ****\n");
    printf("******4.返回主菜单     ****\n");
    printf("***************************\n");
    printf("请选择(1-4):");

}
void UserMenu()
{
    printf("*****欢迎来到用户管理界面**\n");
    printf("***************************\n");
    printf("***************************\n");
    printf("******1.添加用户       ****\n");
    printf("******2.修改用户信息   ****\n");
    printf("******3.删除用户       ****\n");
    printf("******4.返回主菜单     ****\n");
    printf("***************************\n");
    printf("***************************\n");
    printf("请选择(1-4):");

}
void ReserMenu()
{
    printf("***********欢迎来到预约管理界面*****\n");
    printf("************************************\n");
    printf("************************************\n");
    printf("******1.录入预约信息          ******\n");
    printf("******2.查询所有设备的预约信息******\n");
    printf("******3.查询某个设备的预约信息******\n");
    printf("******4.查询所有用户的预约信息******\n");
    printf("******5.查询某个用户的预约信息******\n");
    printf("******6.更改用户的预约信息    ******\n");
    printf("******7.保存预约信息          ******\n");
    printf("******8.返回主菜单            ******\n");
    printf("************************************\n");
    printf("************************************\n");
    printf("请选择(1-8):");

}
void CalMenu()
{
    printf("***********欢迎来到统计查询界面*****\n");
    printf("************************************\n");
    printf("************************************\n");
    printf("******1.按设备名查询设备信息  ******\n");
    printf("******2.按设备号查询设备信息  ******\n");
    printf("******3.按设备类型查询设备信息******\n");
    printf("******4.按设备价格进行排序    ******\n");
    printf("******5.按设备类型统计设备数量******\n");
    printf("******6.返回主菜单            ******\n");
    printf("************************************\n");
    printf("************************************\n");
    printf("请选择(1-6):");

}
void Equip()
{
    int n;
    do
    {
        EquipmentMenu();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            add_equipment(equipments, &num_equipments);
            break;
        case 2:
            modify_equipment(equipments, num_equipments);
            break;
        case 3:
            delete_equipment(equipments, &num_equipments);
            break;
        case 4:
            system("cls");
            return;
            break;
        default:
            printf("输入格式错误请重新输入\n");
            break;
        }
    } while (n);
}

void Use()
{
    int n;
    do
    {
        UserMenu();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            add_user(users, &num_users);
            break;
        case 2:
            modify_user(users, num_users);
            break;
        case 3:
            delete_user(users, &num_users);
            break;
        case 4:
            system("cls");
            return;
            break;
        default:
            printf("输入格式错误请重新输入\n");
            break;
        }
    } while (n);
}

void Reser()
{
    int n;
    do
    {
        ReserMenu();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            add_reservation(reservations, &num_reservations, equipments,
                num_equipments, users, num_users);
            break;
        case 2:
            display_all_reservations(reservations, num_reservations);
            break;
        case 3:
            display_equipment_reservations(reservations, num_reservations);
            break;
        case 4:
            display_all_user_reservations(reservations, num_reservations, users, num_users);
            break;
        case 5:
            display_user_reservations(reservations, num_reservations);
            break;
        case 6:
            modify_user_reservation(reservations, num_reservations);
            break;
        case 7:
            save_reservations(reservations, num_reservations);
            break;
        case 8:
            system("cls");
            return;
            break;
        default:
            printf("输入格式错误请重新输入\n");
            break;
        }
    } while (n);
}
void Cal()
{
    int n;
    do
    {
        CalMenu();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            char a[30];
            printf("请输入要查询的设备名:");
            scanf("%s", a);
            search_equipment_by_name(a);
            break;
        case 2:
            char a1[30];
            printf("请输入要查询的设备ID:");
            scanf("%s", a1);
            search_equipment_by_id(a1);
            break;
        case 3:
            char a2[30];
            printf("请输入要查询的设备类型:");
            scanf("%s", a2);
            search_equipment_by_type(a2);
            break;
        case 4:
            sort_equipments_by_price();
            break;
        case 5:
            count_equipments_by_type();
            break;
        case 6:
            system("cls");
            return;
            break;
        default:
            printf("输入格式错误请重新输入\n");
            break;
        }
    } while (n);
}
int main()
{
    int n;
    do
    {
        menu();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            system("cls");
            Equip();
            break;
        case 2:
            system("cls");
            Use();
            break;
        case 3:
            system("cls");
            Reser();
            break;
        case 4:
            system("cls");
            Cal();
            break;
        case 5:
            printf("退出系统");
            exit(-1);
            break;
        default:
            system("cls");
            printf("输入格式错误请重新输入\n");
            break;
        }
    } while (n);
    return 0;
}
