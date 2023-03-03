#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// ����γ���Ϣ�ṹ��
struct course {
    char code[10]; // �γ̱��
    char name[50]; // �γ�����
    int credit;    // ѧ��
    int selected;  // ��ѡ����
    int max_num;   // �γ���������
};

// �洢���пγ̵�����
struct course courses[100];
int num_courses = 0; // ��ǰ�γ���

// �洢ѧ����Ϣ�Ľṹ��
typedef struct student {
    char name[50];   // ѧ������
    char id[20];     // ѧ��ѧ��
    char password[20];// ѧ������
    int num_courses; // ��ѡ�γ���
    char courses[10][10]; // ��ѡ�γ̱��
}Student;


// �洢����ѧ��������
struct student students[100];
int num_students = 0; // ��ǰѧ����


// ¼��ѧ����Ϣ����
void addStudent()
{
    Student s;
    printf("������ѧ��������");
    scanf("%s", s.name);
    printf("������ѧ��ѧ�ţ�");
    scanf("%s", s.id);
    printf("������ѧ�����룺");
    scanf("%s", s.password);
    s.num_courses = 0; //��ʼ��Ϊ0
 
    students[num_students++] = s;
    printf("¼��ɹ���\n");
}

// �γ̹���ģ��

// ʵ�ֿγ���Ϣ��¼�����ӹ���
void addCourse() {
    struct course c;
    printf("������γ̱��: ");
    scanf("%s", c.code);
    printf("������γ�����: ");
    scanf("%s", c.name);
    printf("������γ�ѧ��: ");
    scanf("%d", &c.credit);
    printf("������γ���������: ");
    scanf("%d", &c.max_num);
    c.selected = 0; // ��ѡ������ʼ��Ϊ0
    courses[num_courses++] = c; // ���γ���Ϣ��ӵ�������
    printf("�γ���Ϣ��ӳɹ���\n");
}

// ʵ�ֿγ���Ϣ���������
void viewCourses() {
    printf("�γ̱��\t�γ�����\tѧ��\t��ѡ����\t��������\n");
    for (int i = 0; i < num_courses; i++) {
        printf("%s\t\t%s\t\t%d\t%d\t\t%d\n", courses[i].code, courses[i].name,
            courses[i].credit, courses[i].selected, courses[i].max_num);
    }
}

// ʵ�ֿγ���Ϣ��ɾ������
void deleteCourse() {
    char code[10];
    printf("������Ҫɾ���Ŀγ̱��: ");
    scanf("%s", code);
    int index = -1;
    for (int i = 0; i < num_courses; i++) {
        if (strcmp(courses[i].code, code) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("δ�ҵ��ÿγ̣�\n");
    }
    else {
        for (int i = index; i < num_courses - 1; i++) {
            courses[i] = courses[i + 1];
        }
        num_courses--;
        printf("�γ�ɾ���ɹ���\n");
    }
}
// �޸Ŀγ���Ϣ�ĺ���
void modifyCourse() {
    char code[10];
    printf("������Ҫ�޸ĵĿγ̱��: ");
    scanf("%s", code);
    int index = -1;
    for (int i = 0; i < num_courses; i++) {
        if (strcmp(courses[i].code, code) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("δ�ҵ��ÿγ̣�\n");
    }
    else {
        printf("�������޸ĺ�Ŀγ�����: ");
        scanf("%s", courses[index].name);
        printf("�������޸ĺ�Ŀγ�ѧ��: ");
        scanf("%d", &courses[index].credit);
        printf("�������޸ĺ�Ŀγ���������: ");
        scanf("%d", &courses[index].max_num);
        printf("�γ���Ϣ�޸ĳɹ���\n");
    }
}

// ѧ������ģ��
void studentSelectCourse();
// ѧ����¼����
void studentLogin() {
    char id[20], password[20];
    printf("������ѧ��ѧ��: ");
    scanf("%s", id);
    printf("������ѧ������: ");
    scanf("%s", password);
    int index = -1;
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, id) == 0 && strcmp(students[i].password, password) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("ѧ�Ż��������\n");
    }
    else {
        printf("��ӭ��%s��\n", students[index].name);
        // ����ѧ��ѡ�ι���
        studentSelectCourse();
    }
}
void studentViewCourses() {
    printf("��ѡ�γ��б�\n");
    for (int i = 0; i < num_courses; i++) {
        printf("%s %s %d/%d\n", courses[i].code, courses[i].name, courses[i].selected, courses[i].max_num);
    }
}

void studentSelectCourse() {
    char id[20];
    printf("������ѧ��ѧ�ţ�");
    scanf("%s", id);

    // ����ѧ���Ƿ����
    int i, found = 0;
    for (i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, id) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("ѧ�������ڣ����������ѧ���Ƿ���ȷ��\n");
        return;
    }

    // ��ʾ��ѡ�γ��б�
    printf("��ѡ�γ��б�\n");
    for (i = 0; i < num_courses; i++) {
        if (courses[i].selected < courses[i].max_num) {
            printf("%s\t%s\t%d\t%d/%d\n", courses[i].code, courses[i].name, courses[i].credit, courses[i].selected, courses[i].max_num);
        }
    }

    // ��ѧ��ѡ��γ�
    char code[10];
    printf("������Ҫѡ�Ŀγ̱�ţ�");
    scanf("%s", code);

    // ���ҿγ��Ƿ����
    found = 0;
    int index;
    for (i = 0; i < num_courses; i++) {
        if (strcmp(courses[i].code, code) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    if (!found) {
        printf("�γ̲����ڣ���������ı���Ƿ���ȷ��\n");
        return;
    }

    // ���γ��Ƿ��Ѿ�ѡ��
    int j;
    for (j = 0; j < students[i].num_courses; j++) {
        if (strcmp(students[i].courses[j], code) == 0) {
            printf("���Ѿ�ѡ�����ſγ��ˡ�\n");
            return;
        }
    }

    // ���γ��Ƿ�����
    if (courses[index].selected >= courses[index].max_num) {
        printf("�γ���������ѡ�������γ̡�\n");
        return;
    }

    // ѡ�γɹ������¿γ̺�ѧ����Ϣ
    courses[index].selected++;
    strcpy(students[i].courses[students[i].num_courses], code);
    students[i].num_courses++;
    printf("ѡ�γɹ���\n");
}

const char* getCourseName(char* code) {
    int i;
    for (i = 0; i < num_courses; i++) {
        if (strcmp(courses[i].code, code) == 0) {
            return courses[i].name;
        }
    }
    return "δ֪�γ�";
}

//�˿�ģ��
void studentDropCourse() {
    char id[20];
    printf("������ѧ��ѧ�ţ�");
    scanf("%s", id);

    // ����ѧ���Ƿ����
    int i, found = 0;
    for (i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, id) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("ѧ�������ڣ����������ѧ���Ƿ���ȷ��\n");
        return;
    }

    // ��ʾ��ѡ�γ��б�
    printf("��ѡ�γ��б�\n");
    for (i = 0; i < students[i].num_courses; i++) {
        printf("%s\t%s\n", students[i].courses[i], getCourseName(students[i].courses[i]));
    }

    // ��ѧ��ѡ��Ҫ�˵Ŀγ�
    char code[10];
    printf("������Ҫ�˵Ŀγ̱�ţ�");
    scanf("%s", code);

    // ���ҿγ��Ƿ����
    found = 0;
    int index;
    for (i = 0; i < num_courses; i++) {
        if (strcmp(courses[i].code, code) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    if (!found) {
        printf("�γ̲����ڣ���������ı���Ƿ���ȷ��\n");
        return;
    }

    // ���ѧ���Ƿ���ѡ���ÿγ�
    int j;
    found = 0;
    for (j = 0; j < students[i].num_courses; j++) {
        if (strcmp(students[i].courses[j], code) == 0) {
            found = 1;
            index = j;
            break;
        }
    }

    if (!found) {
        printf("��δѡ�����ſγ̡�\n");
        return;
    }

    // �˿γɹ������¿γ̺�ѧ����Ϣ
   courses[index].selected--;
    /*for (j = index; j < courses[index].selected; j++) {
        strcpy(courses[index].students[j], courses[index].students[j+1]);
    }
    courses[index].students[courses[index].selected][0] = '\0';*/

    for (j = index; j < students[i].num_courses-1; j++) {
        strcpy(students[i].courses[j], students[i].courses[j+1]);
    }
    students[i].courses[students[i].num_courses-1][0] = '\0';
    students[i].num_courses--;
    printf("�˿γɹ���\n");
}




// ��ѯ����ģ��
void queryByCredit() {
    int min_credit, max_credit;
    printf("������ѧ�ַ�Χ����Сѧ�� ���ѧ�֣���");
    scanf("%d %d", &min_credit, &max_credit);

    printf("ѧ����%d-%d֮��Ŀγ��У�\n", min_credit, max_credit);
    for (int i = 0; i < num_courses; i++) {
        if (courses[i].credit >= min_credit && courses[i].credit <= max_credit) {
            printf("%s %s %d/%d\n", courses[i].code, courses[i].name, courses[i].selected, courses[i].max_num);
        }
    }
}



void queryStudentCourses() {
    char student_id[20];
    printf("������ѧ��ѧ�ţ�");
    scanf("%s", student_id);
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, student_id) == 0) {
            printf("%s��ѡ�γ����£�\n", students[i].name);
            for (int j = 0; j < students[i].num_courses; j++) {
                printf("%s\n", students[i].courses[j]);
            }
            return;
        }
    }
    printf("δ�ҵ���ѧ�������������롣\n");
    queryStudentCourses();
}

// ͳ�ƹ���ģ��
void countCourseSelected() {
    printf("�γ̱��\t��ѡ����\n");
    for (int i = 0; i < num_courses; i++) {
        printf("%s\t\t%d\n", courses[i].code, courses[i].selected);
    }
}

void countCourseCredit() {
    char id[20];
    printf("������ѧ��ѧ�ţ�");
    scanf("%s", id);
    int total_credit = 0;
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, id) == 0) {
            for (int j = 0; j < students[i].num_courses; j++) {
                for (int k = 0; k < num_courses; k++) {
                    if (strcmp(students[i].courses[j], courses[k].code) == 0) {
                        total_credit += courses[k].credit;
                    }
                }
            }
            printf("%s����ѧ����Ϊ��%d\n", students[i].name, total_credit);
            return;
        }
    }
    printf("δ�ҵ�ѧ��Ϊ%s��ѧ����\n", id);
}


// �ļ�����ģ��

void saveToFile() {
    FILE* fp;
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�\n");
        return;
    }
    // ����γ���Ϣ
    fprintf(fp, "�γ���Ϣ\n");
    fprintf(fp, "�γ̱��\t�γ�����\tѧ��\t��ѡ����\t�γ���������\n");
    for (int i = 0; i < num_courses; i++) {
        fprintf(fp, "%s\t%s\t%d\t%d\t%d\n", courses[i].code, courses[i].name, courses[i].credit, courses[i].selected, courses[i].max_num);
    }
    // ����ѧ����Ϣ
    fprintf(fp, "\nѧ����Ϣ\n");
    fprintf(fp, "����\tѧ��\t����\n");
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s\t%s\t%s\t", students[i].name, students[i].id, students[i].password);
       
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("����ɹ���\n");
}

void loadFromFile() {
    FILE* fp;
    fp = fopen("data.txt", "r"); // ��data.txt�ļ�
    if (fp == NULL) {// �ж��ļ��Ƿ�򿪳ɹ�
        printf("�ļ���ʧ�ܣ�\n");
        return;
    }
    char buffer[256];
    char* token;
    // ��ȡ�γ���Ϣ
    fgets(buffer, 256, fp);  // ��ȡ"�γ���Ϣ"��һ��
    fgets(buffer, 256, fp);  // ��ȡ��ͷ
    while (fgets(buffer, 256, fp) != NULL) {
        // ��ȡÿһ�пγ���Ϣ����������ӵ�courses������
        token = strtok(buffer, "\t");
        if (token == NULL) {
            continue;
        }
        strcpy(courses[num_courses].code, token);
        token = strtok(NULL, "\t");
        if (token == NULL) {
            continue;
        }
        strcpy(courses[num_courses].name, token);
        token = strtok(NULL, "\t");
        if (token == NULL) {
            continue;
        }
        courses[num_courses].credit = atoi(token);
        token = strtok(NULL, "\t");
        if (token == NULL) {
            continue;
        }
        courses[num_courses].selected = atoi(token);
        token = strtok(NULL, "\t");
        if (token == NULL) {
            continue;
        }
        courses[num_courses].max_num = atoi(token);
        num_courses++;// ��������1
    }
    // ��ȡѧ����Ϣ
    fgets(buffer, 256, fp);  // ��ȡ"ѧ����Ϣ"��һ��
    fgets(buffer, 256, fp);  // ��ȡ��ͷ
    while (fgets(buffer, 256, fp) != NULL) {
        // ��ȡÿһ��ѧ����Ϣ����������ӵ�students������
        token = strtok(buffer, "\t");// ʹ��tab�ַ��ָ�ÿ���ֶ�
        if (token == NULL) {
            continue;
        }
        strcpy(students[num_students].name, token);
        token = strtok(NULL, "\t");
        if (token == NULL) {
            continue;
        }
        strcpy(students[num_students].id, token);
        token = strtok(NULL, "\t");
        if (token == NULL) {
            continue;
        }
        strcpy(students[num_students].password, token);
        num_students++;
    }
    fclose(fp);
    printf("��ȡ�ɹ���\n");
}



void menu()
{
    printf("1. ����Ա����\n");
    printf("2. ѧ������\n");
    printf("3. �˳�\n");
}
void studentMenu()
{
    printf("1. ѧ����¼����\n");
    printf("2. ѧ������γ���Ϣ����\n");
    printf("3. ѧ��ѡ�ι���\n");
    printf("4. �������˵�\n");
    printf("5. �˿ι���\n");
}
void teacherMenu()
{
    printf("��ѡ��Ҫִ�еĹ��ܣ�\n");
    printf("1. ��ӿγ�\n");
    printf("2. ����γ�\n");
    printf("3. ɾ���γ�\n");
    printf("4. ��ѧ�ֲ�ѯ����\n");
    printf("5. ѧ��ѡ�޿γ̲�ѯ����\n");
    printf("6. ͳ��ÿ���γ̵�ѡ������\n");
    printf("7. ͳ��ÿ��ѧ������ѧ����\n");
    printf("8. ���γ̺�ѧ����Ϣ���浽�ļ���\n");
    printf("9. ���ļ��ж�ȡ�γ̺�ѧ����Ϣ\n");
    printf("10. ¼��ѧ����Ϣ\n");
    printf("11. �������˵�\n");
    printf("12. �޸Ŀγ���Ϣ\n");
  
}
void teacher()
{
    int choice;
    do
    {
        teacherMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addCourse();
            break;
        case 2:
            viewCourses();
            break;
        case 3:
            deleteCourse();
            break;
        case 4:
            queryByCredit();
            break;
        case 5:
            queryStudentCourses();
            break;
        case 6:
            countCourseSelected();
            break;
        case 7:
            countCourseCredit();
            break;
        case 8:
            saveToFile();
            break;
        case 9:
            loadFromFile();
            break;
        case 10:
            addStudent();
            break;
        case 11:
            system("cls");
            return;
            break;
        case 12:
            modifyCourse();
            break;
        default:
            printf("��������ʽ������������\n");
        }
    } while (choice);
}
void student()
{
    int choice;
    do
    {
        studentMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        
        case 1:
            studentLogin();
            break;
        case 2:
            studentViewCourses();
            break;
        case 3:
            studentSelectCourse();
            break;
        case 4:
            system("cls");

            return;
            break;
        case 5:
            studentDropCourse();
            break;
        default:
            printf("��������ʽ������������\n");
        }
    } while (choice);
}

// ������
int main()
{
    const char* code = "123456";
    int choice;
    do
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            char arr[30];
            printf("����������:");
            scanf("%s", arr);
            if (strcmp(code, arr) == 0)
            {
                teacher();
            }
            else
            {
                printf("�����������\n");
            }
            break;
        case 2:
            student();
            break;
        case 3:
            printf("�˳�����\n");
            exit(-1);
            break;
        default:
            printf("��������ʽ������������\n");
        }
    } while (choice);
}