#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 定义课程信息结构体
struct course {
    char code[10]; // 课程编号
    char name[50]; // 课程名称
    int credit;    // 学分
    int selected;  // 已选人数
    int max_num;   // 课程人数上限
};

// 存储所有课程的数组
struct course courses[100];
int num_courses = 0; // 当前课程数

// 存储学生信息的结构体
typedef struct student {
    char name[50];   // 学生姓名
    char id[20];     // 学生学号
    char password[20];// 学生密码
    int num_courses; // 已选课程数
    char courses[10][10]; // 已选课程编号
}Student;


// 存储所有学生的数组
struct student students[100];
int num_students = 0; // 当前学生数


// 录入学生信息函数
void addStudent()
{
    Student s;
    printf("请输入学生姓名：");
    scanf("%s", s.name);
    printf("请输入学生学号：");
    scanf("%s", s.id);
    printf("请输入学生密码：");
    scanf("%s", s.password);
    s.num_courses = 0; //初始化为0
 
    students[num_students++] = s;
    printf("录入成功！\n");
}

// 课程管理模块

// 实现课程信息的录入和添加功能
void addCourse() {
    struct course c;
    printf("请输入课程编号: ");
    scanf("%s", c.code);
    printf("请输入课程名称: ");
    scanf("%s", c.name);
    printf("请输入课程学分: ");
    scanf("%d", &c.credit);
    printf("请输入课程人数上限: ");
    scanf("%d", &c.max_num);
    c.selected = 0; // 已选人数初始化为0
    courses[num_courses++] = c; // 将课程信息添加到数组中
    printf("课程信息添加成功！\n");
}

// 实现课程信息的浏览功能
void viewCourses() {
    printf("课程编号\t课程名称\t学分\t已选人数\t人数上限\n");
    for (int i = 0; i < num_courses; i++) {
        printf("%s\t\t%s\t\t%d\t%d\t\t%d\n", courses[i].code, courses[i].name,
            courses[i].credit, courses[i].selected, courses[i].max_num);
    }
}

// 实现课程信息的删除功能
void deleteCourse() {
    char code[10];
    printf("请输入要删除的课程编号: ");
    scanf("%s", code);
    int index = -1;
    for (int i = 0; i < num_courses; i++) {
        if (strcmp(courses[i].code, code) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("未找到该课程！\n");
    }
    else {
        for (int i = index; i < num_courses - 1; i++) {
            courses[i] = courses[i + 1];
        }
        num_courses--;
        printf("课程删除成功！\n");
    }
}
// 修改课程信息的函数
void modifyCourse() {
    char code[10];
    printf("请输入要修改的课程编号: ");
    scanf("%s", code);
    int index = -1;
    for (int i = 0; i < num_courses; i++) {
        if (strcmp(courses[i].code, code) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("未找到该课程！\n");
    }
    else {
        printf("请输入修改后的课程名称: ");
        scanf("%s", courses[index].name);
        printf("请输入修改后的课程学分: ");
        scanf("%d", &courses[index].credit);
        printf("请输入修改后的课程人数上限: ");
        scanf("%d", &courses[index].max_num);
        printf("课程信息修改成功！\n");
    }
}

// 学生管理模块
void studentSelectCourse();
// 学生登录功能
void studentLogin() {
    char id[20], password[20];
    printf("请输入学生学号: ");
    scanf("%s", id);
    printf("请输入学生密码: ");
    scanf("%s", password);
    int index = -1;
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, id) == 0 && strcmp(students[i].password, password) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("学号或密码错误！\n");
    }
    else {
        printf("欢迎，%s！\n", students[index].name);
        // 调用学生选课功能
        studentSelectCourse();
    }
}
void studentViewCourses() {
    printf("可选课程列表：\n");
    for (int i = 0; i < num_courses; i++) {
        printf("%s %s %d/%d\n", courses[i].code, courses[i].name, courses[i].selected, courses[i].max_num);
    }
}

void studentSelectCourse() {
    char id[20];
    printf("请输入学生学号：");
    scanf("%s", id);

    // 查找学生是否存在
    int i, found = 0;
    for (i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, id) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("学生不存在，请检查输入的学号是否正确。\n");
        return;
    }

    // 显示可选课程列表
    printf("可选课程列表：\n");
    for (i = 0; i < num_courses; i++) {
        if (courses[i].selected < courses[i].max_num) {
            printf("%s\t%s\t%d\t%d/%d\n", courses[i].code, courses[i].name, courses[i].credit, courses[i].selected, courses[i].max_num);
        }
    }

    // 让学生选择课程
    char code[10];
    printf("请输入要选的课程编号：");
    scanf("%s", code);

    // 查找课程是否存在
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
        printf("课程不存在，请检查输入的编号是否正确。\n");
        return;
    }

    // 检查课程是否已经选过
    int j;
    for (j = 0; j < students[i].num_courses; j++) {
        if (strcmp(students[i].courses[j], code) == 0) {
            printf("你已经选过这门课程了。\n");
            return;
        }
    }

    // 检查课程是否已满
    if (courses[index].selected >= courses[index].max_num) {
        printf("课程已满，请选择其他课程。\n");
        return;
    }

    // 选课成功，更新课程和学生信息
    courses[index].selected++;
    strcpy(students[i].courses[students[i].num_courses], code);
    students[i].num_courses++;
    printf("选课成功。\n");
}

const char* getCourseName(char* code) {
    int i;
    for (i = 0; i < num_courses; i++) {
        if (strcmp(courses[i].code, code) == 0) {
            return courses[i].name;
        }
    }
    return "未知课程";
}

//退课模块
void studentDropCourse() {
    char id[20];
    printf("请输入学生学号：");
    scanf("%s", id);

    // 查找学生是否存在
    int i, found = 0;
    for (i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, id) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("学生不存在，请检查输入的学号是否正确。\n");
        return;
    }

    // 显示已选课程列表
    printf("已选课程列表：\n");
    for (i = 0; i < students[i].num_courses; i++) {
        printf("%s\t%s\n", students[i].courses[i], getCourseName(students[i].courses[i]));
    }

    // 让学生选择要退的课程
    char code[10];
    printf("请输入要退的课程编号：");
    scanf("%s", code);

    // 查找课程是否存在
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
        printf("课程不存在，请检查输入的编号是否正确。\n");
        return;
    }

    // 检查学生是否已选过该课程
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
        printf("你未选过该门课程。\n");
        return;
    }

    // 退课成功，更新课程和学生信息
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
    printf("退课成功。\n");
}




// 查询功能模块
void queryByCredit() {
    int min_credit, max_credit;
    printf("请输入学分范围（最小学分 最大学分）：");
    scanf("%d %d", &min_credit, &max_credit);

    printf("学分在%d-%d之间的课程有：\n", min_credit, max_credit);
    for (int i = 0; i < num_courses; i++) {
        if (courses[i].credit >= min_credit && courses[i].credit <= max_credit) {
            printf("%s %s %d/%d\n", courses[i].code, courses[i].name, courses[i].selected, courses[i].max_num);
        }
    }
}



void queryStudentCourses() {
    char student_id[20];
    printf("请输入学生学号：");
    scanf("%s", student_id);
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, student_id) == 0) {
            printf("%s已选课程如下：\n", students[i].name);
            for (int j = 0; j < students[i].num_courses; j++) {
                printf("%s\n", students[i].courses[j]);
            }
            return;
        }
    }
    printf("未找到该学生，请重新输入。\n");
    queryStudentCourses();
}

// 统计功能模块
void countCourseSelected() {
    printf("课程编号\t已选人数\n");
    for (int i = 0; i < num_courses; i++) {
        printf("%s\t\t%d\n", courses[i].code, courses[i].selected);
    }
}

void countCourseCredit() {
    char id[20];
    printf("请输入学生学号：");
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
            printf("%s的总学分数为：%d\n", students[i].name, total_credit);
            return;
        }
    }
    printf("未找到学号为%s的学生！\n", id);
}


// 文件保存模块

void saveToFile() {
    FILE* fp;
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    // 保存课程信息
    fprintf(fp, "课程信息\n");
    fprintf(fp, "课程编号\t课程名称\t学分\t已选人数\t课程人数上限\n");
    for (int i = 0; i < num_courses; i++) {
        fprintf(fp, "%s\t%s\t%d\t%d\t%d\n", courses[i].code, courses[i].name, courses[i].credit, courses[i].selected, courses[i].max_num);
    }
    // 保存学生信息
    fprintf(fp, "\n学生信息\n");
    fprintf(fp, "姓名\t学号\t密码\n");
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s\t%s\t%s\t", students[i].name, students[i].id, students[i].password);
       
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("保存成功！\n");
}

void loadFromFile() {
    FILE* fp;
    fp = fopen("data.txt", "r"); // 打开data.txt文件
    if (fp == NULL) {// 判断文件是否打开成功
        printf("文件打开失败！\n");
        return;
    }
    char buffer[256];
    char* token;
    // 读取课程信息
    fgets(buffer, 256, fp);  // 读取"课程信息"这一行
    fgets(buffer, 256, fp);  // 读取表头
    while (fgets(buffer, 256, fp) != NULL) {
        // 读取每一行课程信息，并将其添加到courses数组中
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
        num_courses++;// 计数器加1
    }
    // 读取学生信息
    fgets(buffer, 256, fp);  // 读取"学生信息"这一行
    fgets(buffer, 256, fp);  // 读取表头
    while (fgets(buffer, 256, fp) != NULL) {
        // 读取每一行学生信息，并将其添加到students数组中
        token = strtok(buffer, "\t");// 使用tab字符分隔每个字段
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
    printf("读取成功！\n");
}



void menu()
{
    printf("1. 管理员界面\n");
    printf("2. 学生界面\n");
    printf("3. 退出\n");
}
void studentMenu()
{
    printf("1. 学生登录功能\n");
    printf("2. 学生浏览课程信息功能\n");
    printf("3. 学生选课功能\n");
    printf("4. 返回主菜单\n");
    printf("5. 退课功能\n");
}
void teacherMenu()
{
    printf("请选择要执行的功能：\n");
    printf("1. 添加课程\n");
    printf("2. 浏览课程\n");
    printf("3. 删除课程\n");
    printf("4. 按学分查询功能\n");
    printf("5. 学生选修课程查询功能\n");
    printf("6. 统计每个课程的选课人数\n");
    printf("7. 统计每个学生的总学分数\n");
    printf("8. 将课程和学生信息保存到文件中\n");
    printf("9. 从文件中读取课程和学生信息\n");
    printf("10. 录入学生信息\n");
    printf("11. 返回主菜单\n");
    printf("12. 修改课程信息\n");
  
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
            printf("输入错误格式，请重新输入\n");
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
            printf("输入错误格式，请重新输入\n");
        }
    } while (choice);
}

// 主函数
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
            printf("请输入密码:");
            scanf("%s", arr);
            if (strcmp(code, arr) == 0)
            {
                teacher();
            }
            else
            {
                printf("密码输入错误\n");
            }
            break;
        case 2:
            student();
            break;
        case 3:
            printf("退出程序\n");
            exit(-1);
            break;
        default:
            printf("输入错误格式，请重新输入\n");
        }
    } while (choice);
}