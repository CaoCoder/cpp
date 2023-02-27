#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EQUIPMENTS 100 // ���100���豸
#define MAX_USERS 100 // ���100���û�
#define MAX_RESERVATIONS 1000 // ���1000��ԤԼ��¼
#define MAX_ID_LENGTH 100//�����豸id��¼
// �豸�ṹ��
struct Equipment {
    char name[50]; // �豸����
    char id[20]; // �豸���
    char type[20]; // �豸����
    char status[20]; // �豸״̬��0-���У�1-��ԤԼ��
    float price; // �豸�۸�
    int num_reserved; // ��ԤԼ����
};

// �û��ṹ��
struct User {
    char name[50]; // �û���
    char id[20]; // ְ����
    char password[20]; // ����
};

// ԤԼ��¼�ṹ��
struct Reservation {
    char equipment_id[20]; // �豸���
    char user_id[20]; // �û�ְ����
    char time[20]; // ԤԼʱ��
};
// ȫ�ֱ���
struct Equipment equipments[MAX_EQUIPMENTS]; // �豸�б�
int num_equipments = 0; // �豸����
struct User users[MAX_USERS]; // �û��б�
int num_users = 0; // �û�����
struct Reservation reservations[MAX_RESERVATIONS]; // ԤԼ��¼�б�
int num_reservations = 0; // ԤԼ��¼����


// ����豸
void add_equipment(struct Equipment* equipments, int* num_equipments) {
    printf("�������豸���ƣ�");
    scanf("%s", equipments[*num_equipments].name);
    printf("�������豸��ţ�");
    scanf("%s", equipments[*num_equipments].id);
    printf("�������豸���ͣ�");
    scanf("%s", equipments[*num_equipments].type);
    printf("�������豸״̬��");
    scanf("%s", equipments[*num_equipments].status);
    printf("�������豸�۸�");
    scanf("%f", &equipments[*num_equipments].price);
    equipments[*num_equipments].num_reserved = 0; // ��ʼ��ԤԼ����Ϊ0
    (*num_equipments)++; // �豸������1
    printf("�豸��ӳɹ���\n");
}


// �޸��豸��Ϣ
void modify_equipment(struct Equipment* equipments, int num_equipments) {
    char id[MAX_ID_LENGTH];
    printf("��������Ҫ�޸���Ϣ���豸��ţ�");
    scanf("%s", id);
    for (int i = 0; i < num_equipments; i++) {
        if (strcmp(equipments[i].id, id) == 0) {
            printf("�������µ��豸���ƣ�");
            scanf("%s", equipments[i].name);
            printf("�������µ��豸���ͣ�");
            scanf("%s", equipments[i].type);
            printf("�������µ��豸״̬��");
            scanf("%s", equipments[i].status);
            printf("�������µ��豸�۸�");
            scanf("%f", &equipments[i].price);
            printf("�豸��Ϣ�޸ĳɹ���\n");
            return;
        }
    }
    printf("δ�ҵ��豸���Ϊ%s���豸�����������Ƿ���ȷ��\n", id);
}
//����
int find_equipment(struct Equipment* equipments, int num_equipments, char* equipment_id) {
    for (int i = 0; i < num_equipments; i++) {
        if (strcmp(equipments[i].id, equipment_id) == 0) {
            return i;
        }
    }
    return -1;
}

// ɾ���豸
void delete_equipment(struct Equipment* equipments, int* num_equipments) {
    char equipment_id[MAX_ID_LENGTH]; // ����һ���ַ����飬���������豸���
    int index; // �豸�������е�����

    printf("������Ҫɾ�����豸��ţ�");
    scanf("%s", equipment_id);

    index = find_equipment(equipments, *num_equipments, equipment_id);

    if (index == -1) { // �豸�����ڣ������ʾ��Ϣ
        printf("�豸�����ڣ�\n");
    }
    else { // �豸���ڣ�����ɾ������
        for (int i = index; i < (*num_equipments - 1); i++) { // ��ɾ���豸������豸��ǰ�ƶ�
            equipments[i] = equipments[i + 1];
        }
        (*num_equipments)--; // �豸����Ԫ�ظ�����һ
        printf("�豸ɾ���ɹ���\n");
    }
}



// ����û�
void add_user(struct User* users, int* num_users) {
    // �ж��Ƿ��Ѵﵽ����û���
    if (*num_users >= MAX_USERS) {
        printf("�Ѵﵽ����û������޷�������û���\n");
        return;
    }

    // �����û���Ϣ
    printf("�������û�����");
    scanf("%s", users[*num_users].name);
    printf("������ְ���ţ�");
    scanf("%s", users[*num_users].id);
    printf("�������ʼ���룺");
    scanf("%s", users[*num_users].password);

    // �����û���
    (*num_users)++;

    printf("����û��ɹ���\n");
}

int find_user(struct User* users, int num_users, char* username) {
    // �����û����飬������ָ���û�����ͬ���û�
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, username) == 0) {
            return i; // �����ҵ����û��������е�����
        }
    }
    return -1; // û���ҵ��û������� -1
}

//�޸��û���Ϣ
void modify_user(struct User* users, int num_users) {
    char input[100];

    printf("������Ҫ�޸ĵ��û���ְ���ţ�");
    scanf("%s", input);

    int index = find_user(users, num_users, input);
    if (index == -1) {
        printf("�û������ڣ�\n");
        return;
    }

    printf("�������û�������");
    scanf("%s", users[index].name);

    printf("�������û����룺");
    scanf("%s", users[index].password);

    printf("�û���Ϣ�޸ĳɹ���\n");
}
//ɾ���û���Ϣ
void delete_user(struct User* users, int* num_users) {
    char user_id[MAX_ID_LENGTH];
    printf("������Ҫɾ�����û�ID��");
    scanf("%s", user_id);
    int index = find_user(users, *num_users, user_id);
    if (index == -1) {
        printf("�û������ڣ�\n");
        return;
    }
    // �����һ���û�����Ϣ���ǵ���ɾ����λ��
    users[index] = users[(*num_users) - 1];
    (*num_users)--;
    printf("�û�ɾ���ɹ���\n");
}

// ¼��ԤԼ��Ϣ
void add_reservation(struct Reservation* reservations, int* num_reservations, struct Equipment* equipments,
    int num_equipments, struct User* users, int num_users) {
    // ��ȡԤԼ��Ϣ
    struct Reservation reservation;
    printf("������ԤԼ��Ϣ��\n");
    printf("�豸��ţ�");
    scanf("%s", reservation.equipment_id);
    printf("�����˹��ţ�");
    scanf("%s", reservation.user_id);
    printf("ԤԼʱ�䣺");
    scanf("%s", reservation.time);

    // �����豸�Ƿ����
    int index = find_equipment(equipments, num_equipments, reservation.equipment_id);
    if (index == -1) {
        printf("�豸�����ڣ�\n");
        return;
    }

    // �����û��Ƿ����
    index = find_user(users, num_users, reservation.user_id);
    if (index == -1) {
        printf("�û������ڣ�\n");
        return;
    }

    // ���ԤԼ��Ϣ��������
    reservations[*num_reservations] = reservation;
    *num_reservations += 1;

    printf("ԤԼ�ɹ���\n");
}


// ��ѯ�����豸��ԤԼ��Ϣ
void display_all_reservations(struct Reservation* reservations, int num_reservations) {
    if (num_reservations == 0) {
        printf("����ԤԼ��Ϣ\n");
        return;
    }
    printf("�����豸��ԤԼ��Ϣ���£�\n");
    printf("�豸���\t������\t\tԤԼʱ��\n");
    for (int i = 0; i < num_reservations; i++) {
        printf("%s\t\t%s\t\t%s\n", reservations[i].equipment_id, reservations[i].user_id, reservations[i].time);
    }
}


// ��ѯĳ���豸��ԤԼ��Ϣ
void display_equipment_reservations(struct Reservation* reservations, int num_reservations) {
    char equipment_id[10];
    int count = 0;

    printf("������Ҫ��ѯ���豸id��");
    scanf("%s", equipment_id);

    printf("�豸 %s ��ԤԼ��Ϣ���£�\n", equipment_id);
    printf("%-10s%-15s%-25s\n", "�豸id", "������", "ԤԼʱ��");

    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(reservations[i].equipment_id, equipment_id) == 0) {
            printf("%-10s%-15s%-25s\n", reservations[i].equipment_id, reservations[i].user_id, reservations[i].time);
            count++;
        }
    }

    if (count == 0) {
        printf("û���ҵ��豸 %s ��ԤԼ��Ϣ��\n", equipment_id);
    }
}



// ��ѯ�����û���ԤԼ��Ϣ
void display_all_user_reservations(struct Reservation* reservations, int num_reservations, struct User* users, int num_users) {
    printf("�����û���ԤԼ��Ϣ���£�\n");
    printf("%-10s%-15s%-25s%-15s\n", "�豸���", "������", "ԤԼʱ��", "�û�ID");
    for (int i = 0; i < num_reservations; i++) {
        struct Reservation reservation = reservations[i];
        struct User user = users[find_user(users, num_users, reservation.user_id)];
        printf("%-10s%-15s%-25s%-15s\n", reservation.equipment_id, user.name, reservation.time, user.id);
    }
}


// ��ѯĳ���û���ԤԼ��Ϣ
void display_user_reservations(struct Reservation* reservations, int num_reservations) {
    char user_name[50];
    int count = 0;

    printf("������Ҫ��ѯԤԼ��Ϣ���û�������");
    scanf("%s", user_name);

    printf("ԤԼ��Ϣ��ѯ�����\n");
    printf("%-10s%-15s%-25s\n", "�豸���", "������", "ԤԼʱ��");
    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(reservations[i].user_id, user_name) == 0) {
            printf("%-10s%-15s%-25s\n", reservations[i].equipment_id, reservations[i].user_id, reservations[i].time);
            count++;
        }
    }

    if (count == 0) {
        printf("û���ҵ� %s ��ԤԼ��Ϣ.\n", user_name);
    }
}



// �����û���ԤԼ��Ϣ
void modify_user_reservation(struct Reservation* reservations, int num_reservations) {
    char user_name[50];
    printf("������ԤԼ��������");
    scanf("%s", user_name);

    // ���Ҹ��û�������ԤԼ��Ϣ
    int count = 0;
    printf("\nԤԼ�� %s ��ԤԼ��Ϣ���£�\n", user_name);
    printf("%-15s%-10s%-25s\n", "ԤԼ��", "�豸", "ԤԼʱ��");
    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(reservations[i].user_id, user_name) == 0) {
            printf("%-15s%-10s%-25s\n", reservations[i].user_id, reservations[i].equipment_id, reservations[i].time);
            count++;
        }
    }
    if (count == 0) {
        printf("���û�δ���й�ԤԼ��\n");
        return;
    }

    // �޸�ԤԼ��Ϣ
    char equipment_id[50], new_time[50];
    printf("\n������Ҫ�޸�ԤԼʱ����豸��ţ�");
    scanf("%s", equipment_id);
    printf("�������µ�ԤԼʱ�䣺");
    scanf("%s", new_time);

    int modified = 0;
    for (int i = 0; i < num_reservations; i++) {
        if (strcmp(reservations[i].user_id, user_name) == 0 && strcmp(reservations[i].equipment_id, equipment_id) == 0) {
            strcpy(reservations[i].time, new_time);
            printf("\nԤԼ��Ϣ�޸ĳɹ���\n");
            modified = 1;
            break;
        }
    }
    if (!modified) {
        printf("\nδ�ҵ����豸��ԤԼ��Ϣ��ԤԼ��Ϣ�޸�ʧ�ܡ�\n");
    }
}

// ����ԤԼ��Ϣ
void save_reservations(struct Reservation* reservations, int num_reservations) {
    FILE* fp;
    fp = fopen("data.txt", "w"); // ���ļ�

    if (fp == NULL) { // �ж��ļ��Ƿ�ɹ���
        printf("�޷����ļ�.\n");
        return;
    }

    for (int i = 0; i < num_reservations; i++) {
        fprintf(fp, "%s,%s,%s\n", reservations[i].equipment_id, reservations[i].user_id, reservations[i].time);
    }

    fclose(fp); // �ر��ļ�
    printf("ԤԼ��Ϣ�ѱ��浽data.txt�ļ���.\n");
}
//����ԤԼ��Ϣ
void load_reservations(struct Reservation* reservations, int* num_reservations) {
    FILE* fp;
    fp = fopen("data.txt", "r"); // ���ļ�

    if (fp == NULL) { // �ж��ļ��Ƿ�ɹ���
        printf("�޷����ļ�.\n");
        return;
    }

    char line[100];
    int i = 0;

    while (fgets(line, 100, fp)) {
        sscanf(line, "%[^,],%[^,],%s", reservations[i].equipment_id, reservations[i].user_id, reservations[i].time);
        i++;
    }

    *num_reservations = i;

    fclose(fp); // �ر��ļ�
    printf("ԤԼ��Ϣ�Ѵ�data.txt�ļ��м���.\n");
}


// ���豸����ѯ�豸��Ϣ
void search_equipment_by_name(char* name) {
    int i;
    int count = 0; // ��¼��ѯ�����豸����

    // �����豸�б�
    for (i = 0; i < num_equipments; i++) {
        if (strcmp(name, equipments[i].name) == 0) {
            printf("�豸���ƣ�%s\n", equipments[i].name);
            printf("�豸��ţ�%s\n", equipments[i].id);
            printf("�豸���ͣ�%s\n", equipments[i].type);
            printf("�豸״̬��%s\n", equipments[i].status);
            printf("�豸�۸�%f\n", equipments[i].price);
            printf("��ԤԼ������%d\n", equipments[i].num_reserved);
            printf("\n");
            count++;
        }
    }

    if (count == 0) {
        printf("δ�ҵ�ƥ����豸.\n");
    }
}
// �����豸�Ų�ѯ�豸��Ϣ
void search_equipment_by_id(char* id) {
    int found = 0;
    for (int i = 0; i < num_equipments; i++) {
        if (strcmp(equipments[i].id, id) == 0) {
            found = 1;
            printf("�豸���ƣ�%s\n", equipments[i].name);
            printf("�豸��ţ�%s\n", equipments[i].id);
            printf("�豸���ͣ�%s\n", equipments[i].type);
            printf("�豸״̬��%s\n", equipments[i].status);
            printf("�豸�۸�%.2f\n", equipments[i].price);
            printf("��ԤԼ������%d\n", equipments[i].num_reserved);
            break;
        }
    }
    if (!found) {
        printf("δ�ҵ��豸��Ϊ%s���豸\n", id);
    }
}
// �����豸���Ͳ�ѯ�豸��Ϣ
void search_equipment_by_type(char* type) {
    int found = 0; // �Ƿ��ҵ��豸�ı�־
    printf("��ѯ�����\n");
    for (int i = 0; i < num_equipments; i++) {
        if (strcmp(equipments[i].type, type) == 0) {
            printf("�豸���ƣ�%s\n", equipments[i].name);
            printf("�豸��ţ�%s\n", equipments[i].id);
            printf("�豸���ͣ�%s\n", equipments[i].type);
            printf("�豸״̬��%s\n", equipments[i].status);
            printf("�豸�۸�%.2f\n", equipments[i].price);
            printf("��ԤԼ������%d\n", equipments[i].num_reserved);
            found = 1;
        }
    }
    if (!found) {
        printf("δ�ҵ��豸��\n");
    }
}
//�����豸�۸��������
void sort_equipments_by_price() {
    int i, j;
    struct Equipment temp;

    for (i = 0; i < num_equipments - 1; i++) {
        for (j = 0; j < num_equipments - 1 - i; j++) {
            if (equipments[j].price > equipments[j + 1].price) {
                // ����λ��
                temp = equipments[j];
                equipments[j] = equipments[j + 1];
                equipments[j + 1] = temp;
            }
        }
    }

    printf("�豸���۸�����ɹ���\n");
}

//��������ͳ��
void count_equipments_by_type() {
    int num_types = 0; // �豸��������
    char types[MAX_EQUIPMENTS][20]; // �豸��������
    int counts[MAX_EQUIPMENTS]; // �豸������������
    memset(counts, 0, sizeof(counts)); // ����������

    // �����豸�б�ͳ�Ʋ�ͬ���͵��豸����
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

    // ���ͳ�ƽ��
    printf("ͳ�ƽ�����£�\n");
    for (int i = 0; i < num_types; i++) {
        printf("%s: %d\n", types[i], counts[i]);
    }
}


         
void menu()
{
    printf("*****************************\n");
    printf("*****************************\n");
    printf("*****************************\n");
    printf("******1.�豸����ģ��   ******\n");
    printf("******2.�û�����ģ��   ******\n");
    printf("******3.�豸ԤԼ����ģ��*****\n");
    printf("******4.��Ϣͳ�Ʋ�ѯģ��*****\n");
    printf("******5.�˳�            *****\n");
    printf("*****************************\n");
    printf("��ѡ��(1-5):");
}
void EquipmentMenu()
{
    printf("*****��ӭ�����豸�������**\n");
    printf("***************************\n");
    printf("***************************\n");
    printf("******1.����豸       ****\n");
    printf("******2.�޸��豸��Ϣ   ****\n");
    printf("******3.ɾ���豸       ****\n");
    printf("******4.�������˵�     ****\n");
    printf("***************************\n");
    printf("��ѡ��(1-4):");

}
void UserMenu()
{
    printf("*****��ӭ�����û��������**\n");
    printf("***************************\n");
    printf("***************************\n");
    printf("******1.����û�       ****\n");
    printf("******2.�޸��û���Ϣ   ****\n");
    printf("******3.ɾ���û�       ****\n");
    printf("******4.�������˵�     ****\n");
    printf("***************************\n");
    printf("***************************\n");
    printf("��ѡ��(1-4):");

}
void ReserMenu()
{
    printf("***********��ӭ����ԤԼ�������*****\n");
    printf("************************************\n");
    printf("************************************\n");
    printf("******1.¼��ԤԼ��Ϣ          ******\n");
    printf("******2.��ѯ�����豸��ԤԼ��Ϣ******\n");
    printf("******3.��ѯĳ���豸��ԤԼ��Ϣ******\n");
    printf("******4.��ѯ�����û���ԤԼ��Ϣ******\n");
    printf("******5.��ѯĳ���û���ԤԼ��Ϣ******\n");
    printf("******6.�����û���ԤԼ��Ϣ    ******\n");
    printf("******7.����ԤԼ��Ϣ          ******\n");
    printf("******8.�������˵�            ******\n");
    printf("************************************\n");
    printf("************************************\n");
    printf("��ѡ��(1-8):");

}
void CalMenu()
{
    printf("***********��ӭ����ͳ�Ʋ�ѯ����*****\n");
    printf("************************************\n");
    printf("************************************\n");
    printf("******1.���豸����ѯ�豸��Ϣ  ******\n");
    printf("******2.���豸�Ų�ѯ�豸��Ϣ  ******\n");
    printf("******3.���豸���Ͳ�ѯ�豸��Ϣ******\n");
    printf("******4.���豸�۸��������    ******\n");
    printf("******5.���豸����ͳ���豸����******\n");
    printf("******6.�������˵�            ******\n");
    printf("************************************\n");
    printf("************************************\n");
    printf("��ѡ��(1-6):");

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
            printf("�����ʽ��������������\n");
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
            printf("�����ʽ��������������\n");
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
            printf("�����ʽ��������������\n");
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
            printf("������Ҫ��ѯ���豸��:");
            scanf("%s", a);
            search_equipment_by_name(a);
            break;
        case 2:
            char a1[30];
            printf("������Ҫ��ѯ���豸ID:");
            scanf("%s", a1);
            search_equipment_by_id(a1);
            break;
        case 3:
            char a2[30];
            printf("������Ҫ��ѯ���豸����:");
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
            printf("�����ʽ��������������\n");
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
            printf("�˳�ϵͳ");
            exit(-1);
            break;
        default:
            system("cls");
            printf("�����ʽ��������������\n");
            break;
        }
    } while (n);
    return 0;
}
