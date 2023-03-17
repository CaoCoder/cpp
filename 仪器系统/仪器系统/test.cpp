#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INSTRUMENTS 100

// �����ṹ��
typedef struct {
    char id[20]; // �������
    char name[50]; // ��������
    char purchase_date[20]; // ����ʱ��
    char borrower[50]; // ������
    char status[20]; // ״̬��Ϣ
} Instrument;

// �����б�
Instrument instruments[MAX_INSTRUMENTS];

// ��ǰ������
int num_instruments = 0;

// ��������
void add_instrument();
void edit_instrument();
void delete_instrument();
void view_instruments();
void search_instruments();
void save_instruments();
int is_valid_id(char id[]);
int is_duplicate_id(char id[]);

// ������
int main() {
    int choice;

    while (1) {
        printf("====== ��������ϵͳ ======\n");
        printf("1. �������\n");
        printf("2. �޸�����\n");
        printf("3. ɾ������\n");
        printf("4. �鿴��������\n");
        printf("5. ��������\n");
        printf("6. ��������\n");
        printf("0. �˳�ϵͳ\n");
        printf("==========================\n");
        printf("��ѡ��");
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
            printf("ллʹ�ã��ټ���\n");
            return 0;
        default:
            printf("��Ч��ѡ�������ѡ��\n");
        }
    }
}
void add_instrument() {
    if (num_instruments >= MAX_INSTRUMENTS) {
        printf("�����б��������޷���Ӹ���������\n");
        return;
    }

    Instrument new_instrument;

    printf("������������ţ�");
    scanf("%s", new_instrument.id);

    if (!is_valid_id(new_instrument.id)) {
        printf("��Ч��������ţ����������롣\n");
        return;
    }

    if (is_duplicate_id(new_instrument.id)) {
        printf("��������Ѵ��ڣ����������롣\n");
        return;
    }

    printf("�������������ƣ�");
    scanf("%s", new_instrument.name);

    printf("�����빺��ʱ�䣺");
    scanf("%s", new_instrument.purchase_date);

    strcpy(new_instrument.borrower, "");
    strcpy(new_instrument.status, "δ���");

    instruments[num_instruments] = new_instrument;
    num_instruments++;

    printf("������ӳɹ���\n");
}

void edit_instrument() {
    char id[20];
    int index = -1;

    printf("������Ҫ�޸ĵ�������ţ�");
    scanf("%s", id);

    for (int i = 0; i < num_instruments; i++) {
        if (strcmp(instruments[i].id, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("δ�ҵ����Ϊ%s��������\n", id);
        return;
    }

    Instrument edited_instrument = instruments[index];

    printf("�������µ��������ƣ�ԭ���ƣ�%s����", edited_instrument.name);
    scanf("%s", edited_instrument.name);

    printf("�������µĹ���ʱ�䣨ԭʱ�䣺%s����", edited_instrument.purchase_date);
    scanf("%s", edited_instrument.purchase_date);

    instruments[index] = edited_instrument;

    printf("������Ϣ�޸ĳɹ���\n");
}
void delete_instrument() {
    char id[20];
    int index = -1;

    printf("������Ҫɾ����������ţ�");
    scanf("%s", id);

    for (int i = 0; i < num_instruments; i++) {
        if (strcmp(instruments[i].id, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("δ�ҵ����Ϊ%s��������\n", id);
        return;
    }

    for (int i = index; i < num_instruments - 1; i++) {
        instruments[i] = instruments[i + 1];
    }

    num_instruments--;

    printf("����ɾ���ɹ���\n");
}
void view_instruments() {
    if (num_instruments == 0) {
        printf("����������Ϣ��\n");
        return;
    }

    printf("%-10s%-20s%-20s%-20s%s\n", "���", "����", "����ʱ��", "������", "״̬��Ϣ");
    for (int i = 0; i < num_instruments; i++) {
        printf("%-10s%-20s%-20s%-20s%s\n", instruments[i].id, instruments[i].name, instruments[i].purchase_date,
            instruments[i].borrower, instruments[i].status);
    }
}
void search_instruments() {
    char keyword[50];
    int count = 0;

    printf("������ؼ��֣�");
    scanf("%s", keyword);

    printf("%-10s%-20s%-20s%-20s%s\n", "���", "����", "����ʱ��", "������", "״̬��Ϣ");
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
        printf("δ�ҵ�����������������Ϣ��\n");
    }
}
void save_instruments() {
    FILE* fp = fopen("instruments.dat", "w");

    if (fp == NULL) {
        printf("�ļ���ʧ�ܡ�\n");
        return;
    }

    for (int i = 0; i < num_instruments; i++) {
        fprintf(fp, "%s,%s,%s,%s,%s\n", instruments[i].id, instruments[i].name, instruments[i].purchase_date,
            instruments[i].borrower, instruments[i].status);
    }

    fclose(fp);
    printf("������Ϣ�ѳɹ����浽�ļ��С�\n");
}
int is_valid_id(char id[]) {
    // ������ű���Ϊ�ǿ��ַ���
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
