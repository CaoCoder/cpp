#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INSTRUMENTS 100

// 仪器结构体
typedef struct {
    char id[20]; // 仪器编号
    char name[50]; // 仪器名称
    char purchase_date[20]; // 购买时间
    char borrower[50]; // 借入人
    char status[20]; // 状态信息
} Instrument;

// 仪器列表
Instrument instruments[MAX_INSTRUMENTS];

// 当前仪器数
int num_instruments = 0;

// 函数声明
void add_instrument();
void edit_instrument();
void delete_instrument();
void view_instruments();
void search_instruments();
void save_instruments();
int is_valid_id(char id[]);
int is_duplicate_id(char id[]);

// 主函数
int main() {
    int choice;

    while (1) {
        printf("====== 仪器管理系统 ======\n");
        printf("1. 添加仪器\n");
        printf("2. 修改仪器\n");
        printf("3. 删除仪器\n");
        printf("4. 查看所有仪器\n");
        printf("5. 搜索仪器\n");
        printf("6. 保存数据\n");
        printf("0. 退出系统\n");
        printf("==========================\n");
        printf("请选择：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_instrument();
            break;
        case 2:
            edit_instrument();
            break;
        case 3:
            delete_instrument();
            break;
        case 4:
            view_instruments();
            break;
        case 5:
            search_instruments();
            break;
        case 6:
            save_instruments();
            break;
        case 0:
            printf("谢谢使用，再见！\n");
            return 0;
        default:
            printf("无效的选项，请重新选择。\n");
        }
    }
}
void add_instrument() {
    if (num_instruments >= MAX_INSTRUMENTS) {
        printf("仪器列表已满，无法添加更多仪器。\n");
        return;
    }

    Instrument new_instrument;

    printf("请输入仪器编号：");
    scanf("%s", new_instrument.id);

    if (!is_valid_id(new_instrument.id)) {
        printf("无效的仪器编号，请重新输入。\n");
        return;
    }

    if (is_duplicate_id(new_instrument.id)) {
        printf("仪器编号已存在，请重新输入。\n");
        return;
    }

    printf("请输入仪器名称：");
    scanf("%s", new_instrument.name);

    printf("请输入购买时间：");
    scanf("%s", new_instrument.purchase_date);

    strcpy(new_instrument.borrower, "");
    strcpy(new_instrument.status, "未借出");

    instruments[num_instruments] = new_instrument;
    num_instruments++;

    printf("仪器添加成功！\n");
}

void edit_instrument() {
    char id[20];
    int index = -1;

    printf("请输入要修改的仪器编号：");
    scanf("%s", id);

    for (int i = 0; i < num_instruments; i++) {
        if (strcmp(instruments[i].id, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("未找到编号为%s的仪器。\n", id);
        return;
    }

    Instrument edited_instrument = instruments[index];

    printf("请输入新的仪器名称（原名称：%s）：", edited_instrument.name);
    scanf("%s", edited_instrument.name);

    printf("请输入新的购买时间（原时间：%s）：", edited_instrument.purchase_date);
    scanf("%s", edited_instrument.purchase_date);

    instruments[index] = edited_instrument;

    printf("仪器信息修改成功！\n");
}
void delete_instrument() {
    char id[20];
    int index = -1;

    printf("请输入要删除的仪器编号：");
    scanf("%s", id);

    for (int i = 0; i < num_instruments; i++) {
        if (strcmp(instruments[i].id, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("未找到编号为%s的仪器。\n", id);
        return;
    }

    for (int i = index; i < num_instruments - 1; i++) {
        instruments[i] = instruments[i + 1];
    }

    num_instruments--;

    printf("仪器删除成功！\n");
}
void view_instruments() {
    if (num_instruments == 0) {
        printf("暂无仪器信息。\n");
        return;
    }

    printf("%-10s%-20s%-20s%-20s%s\n", "编号", "名称", "购买时间", "借入人", "状态信息");
    for (int i = 0; i < num_instruments; i++) {
        printf("%-10s%-20s%-20s%-20s%s\n", instruments[i].id, instruments[i].name, instruments[i].purchase_date,
            instruments[i].borrower, instruments[i].status);
    }
}
void search_instruments() {
    char keyword[50];
    int count = 0;

    printf("请输入关键字：");
    scanf("%s", keyword);

    printf("%-10s%-20s%-20s%-20s%s\n", "编号", "名称", "购买时间", "借入人", "状态信息");
    for (int i = 0; i < num_instruments; i++) {
        if (strstr(instruments[i].id, keyword) || strstr(instruments[i].name, keyword) ||
            strstr(instruments[i].purchase_date, keyword) || strstr(instruments[i].borrower, keyword) ||
            strstr(instruments[i].status, keyword)) {
            printf("%-10s%-20s%-20s%-20s%s\n", instruments[i].id, instruments[i].name, instruments[i].purchase_date,
                instruments[i].borrower, instruments[i].status);
            count++;
        }
    }

    if (count == 0) {
        printf("未找到符合条件的仪器信息。\n");
    }
}
void save_instruments() {
    FILE* fp = fopen("instruments.dat", "w");

    if (fp == NULL) {
        printf("文件打开失败。\n");
        return;
    }

    for (int i = 0; i < num_instruments; i++) {
        fprintf(fp, "%s,%s,%s,%s,%s\n", instruments[i].id, instruments[i].name, instruments[i].purchase_date,
            instruments[i].borrower, instruments[i].status);
    }

    fclose(fp);
    printf("仪器信息已成功保存到文件中。\n");
}
int is_valid_id(char id[]) {
    // 仪器编号必须为非空字符串
    if (strlen(id) == 0) {
        return 0;
    }
    return 1;
}
int is_duplicate_id(char id[]) {
    int i;
    for (i = 0; i < num_instruments; i++) {
        if (strcmp(instruments[i].id, id) == 0) {
            return 1;
        }
    }
    return 0;
}
