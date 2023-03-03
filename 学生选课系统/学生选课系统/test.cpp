//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//
//#include <stdio.h>
//#include <string.h>
//
//#define MAX_COURSES 100
//#define MAX_STUDENTS 100
//
//// 课程信息结构体
//struct Course {
//    int id; // 课程编号
//    char name[50]; // 课程名称
//    int credit; // 课程学分
//    int selectedCount; // 课程已选人数
//    int maxCount; // 课程人数上限
//    int selectedStudents[MAX_STUDENTS]; // 已选该课程的学生学号数组
//};
//
//// 学生信息结构体
//struct Student {
//    char name[50]; // 学生姓名
//    int id; // 学生学号
//    int selectedCourses[MAX_COURSES]; // 学生已选课程数组，存储课程编号
//    int selectedCount; // 学生已选课程数目
//};
//
//// 课程数组和学生数组
//struct Course courses[MAX_COURSES];
//struct Student students[MAX_STUDENTS];
//
//int courseCount = 0; // 当前课程数目
//int studentCount = 0; // 当前学生数目
//
//// 课程管理模块
//void addCourse() {
//    // 如果当前课程数目已经达到上限，则无法添加新课程
//    if (courseCount >= MAX_COURSES) {
//        printf("无法添加新课程，已达到课程数目上限！\n");
//        return;
//    }
//
//    // 输入新课程信息
//    printf("请输入新课程信息：\n");
//    struct Course newCourse;
//    printf("课程编号：");
//    scanf("%d", &newCourse.id);
//    printf("课程名称：");
//    scanf("%s", newCourse.name);
//    printf("课程学分：");
//    scanf("%d", &newCourse.credit);
//    printf("课程人数上限：");
//    scanf("%d", &newCourse.maxCount);
//    newCourse.selectedCount = 0; // 初始化已选人数为0
//
//    // 将新课程添加到课程数组中
//    courses[courseCount] = newCourse;
//    courseCount++;
//
//    printf("新课程添加成功！\n");
//}
//void menu()
//{
//    printf("请选择要执行的功能：\n");
//    printf("1. 添加课程\n");
//    printf("2. 浏览课程\n");
//    printf("3. 删除课程\n");
//    printf("3. 删除课程\n");
//    printf("3. 删除课程\n");
//    printf("3. 删除课程\n");
//    printf("3. 删除课程\n");
//    printf("3. 删除课程\n");
//    printf("3. 删除课程\n");
//    printf("3. 删除课程\n");
//
//}
//
//void viewCourses() {
//    if (courseCount == 0) {
//        printf("当前没有课程信息，请先添加课程\n");
//        return;
//    }
//    printf("课程编号\t课程名称\t课程学分\t已选人数\t人数上限\n");
//    for (int i = 0; i < courseCount; i++) {
//        printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n",
//            courses[i].id, courses[i].name, courses[i].credit,
//            courses[i].selectedCount, courses[i].maxCount);
//    }
//}
//
//// 将学生id添加到指定课程的已选学生数组中
//void addSelectedStudentToCourse(int courseId, int studentId) {
//    for (int i = 0; i < courseCount; i++) {
//        if (courses[i].id == courseId) {
//            if (courses[i].selectedCount < courses[i].maxCount) {
//                courses[i].selectedStudents[courses[i].selectedCount++] = studentId;
//                students[studentId].selectedCourses[students[studentId].selectedCount++] = courseId;
//                printf("学生 %s 成功选修了课程 %s。\n", students[studentId].name, courses[i].name);
//            }
//            else {
//                printf("课程 %s 的人数已满，无法再选修。\n", courses[i].name);
//            }
//            break;
//        }
//    }
//}
//
//
//
//void removeSelectedStudentFromCourse(int courseId, int studentId) {
//    int i;
//    struct Course* course = &courses[courseId];
//    for (i = 0; i < course->selectedCount; i++) {
//        if (course->selectedStudents[i] == studentId) {
//            break;
//        }
//    }
//    if (i == course->selectedCount) {
//        // 没有找到该学生，直接返回
//        return;
//    }
//    // 将后面的学生id向前移动一个位置
//    for (; i < course->selectedCount - 1; i++) {
//        course->selectedStudents[i] = course->selectedStudents[i + 1];
//    }
//    course->selectedCount--;
//}
//
//
//void deleteCourse() {
//    int courseId;
//    printf("请输入要删除的课程编号：");
//    scanf("%d", &courseId);
//
//    int i, j;
//    for (i = 0; i < courseCount; i++) {
//        if (courses[i].id == courseId) {
//            // 将该课程从数组中删除，并将数组中的其他元素向前移动
//            for (j = i; j < courseCount - 1; j++) {
//                courses[j] = courses[j + 1];
//            }
//            // 更新当前课程数目
//            courseCount--;
//            printf("课程删除成功！\n");
//            return;
//        }
//    }
//    printf("未找到该课程，删除失败！\n");
//}
//
//
//// 学生管理模块
//void studentLogin() {
//    int studentId;
//    printf("请输入学号：");
//    scanf("%d", &studentId);
//    for (int i = 0; i < studentCount; i++) {
//        if (students[i].id == studentId) {
//            printf("欢迎登录，%s同学！\n", students[i].name);
//            return;
//        }
//    }
//    printf("未找到该学号对应的学生信息，请确认输入是否正确。\n");
//}
//
//
//void studentViewCourses() {
//    // 遍历课程数组，输出所有课程信息
//    for (int i = 0; i < courseCount; i++) {
//        printf("课程编号：%d\n", courses[i].id);
//        printf("课程名称：%s\n", courses[i].name);
//        printf("课程学分：%d\n", courses[i].credit);
//        printf("课程已选人数：%d\n", courses[i].selectedCount);
//        printf("课程人数上限：%d\n", courses[i].maxCount);
//        printf("\n");
//    }
//}
//
//
//void studentSelectCourse() {
//    int studentId;
//    printf("请输入您的学号：");
//    scanf("%d", &studentId);
//
//    // 查找对应学生
//    int studentIndex = -1;
//    for (int i = 0; i < studentCount; i++) {
//        if (students[i].id == studentId) {
//            studentIndex = i;
//            break;
//        }
//    }
//    if (studentIndex == -1) {
//        printf("没有找到该学生！\n");
//        return;
//    }
//
//    // 打印所有课程信息
//    printf("所有可选课程信息如下：\n");
//    for (int i = 0; i < courseCount; i++) {
//        printf("%d\t%s\t%d\t%d/%d\n", courses[i].id, courses[i].name, courses[i].credit, courses[i].selectedCount, courses[i].maxCount);
//    }
//
//    // 让学生选择课程
//    printf("请输入您要选修的课程编号：");
//    int courseId;
//    scanf("%d", &courseId);
//    int courseIndex = -1;
//    for (int i = 0; i < courseCount; i++) {
//        if (courses[i].id == courseId) {
//            courseIndex = i;
//            break;
//        }
//    }
//    if (courseIndex == -1) {
//        printf("没有找到该课程！\n");
//        return;
//    }
//    if (courses[courseIndex].selectedCount >= courses[courseIndex].maxCount) {
//        printf("该课程已经选满，请选择其他课程！\n");
//        return;
//    }
//
//    // 添加课程
//    courses[courseIndex].selectedStudents[courses[courseIndex].selectedCount++] = studentId;
//    students[studentIndex].selectedCourses[students[studentIndex].selectedCount++] = courseId;
//    printf("选课成功！\n");
//}
//
//
//// 查询功能模块
//void queryByCredit() {
//    int credit;
//    printf("请输入要查询的学分数：");
//    scanf("%d", &credit);
//    printf("学分为 %d 的课程如下：\n", credit);
//    for (int i = 0; i < courseCount; i++) {
//        if (courses[i].credit == credit) {
//            printf("课程编号：%d，课程名称：%s，学分：%d，已选人数：%d，人数上限：%d\n",
//                courses[i].id, courses[i].name, courses[i].credit, courses[i].selectedCount, courses[i].maxCount);
//        }
//    }
//}
//
//
//void queryByProperty() {
//    char property[20];
//    printf("请输入要查询的课程姓名：");
//    scanf("%s", property);
//    for (int i = 0; i < courseCount; i++) {
//        if (strcmp(courses[i].name, property) == 0) {
//            printf("课程编号：%d，课程名称：%s，学分：%d\n", courses[i].id, courses[i].name, courses[i].credit);
//        }
//    }
//}
//
//
//void queryStudentCourses() {
//    // 学生选修课程查询功能
//}
//
//// 统计功能模块
//void countCourseSelected() {
//    int numCourses = sizeof(courses) / sizeof(courses[0]); // 获取课程总数
//    for (int i = 0; i < numCourses; i++) {
//        int count = courses[i].selectedCount; // 获取选课人数
//        printf("课程名称：%s，选课人数：%d\n", courses[i].name, count);
//    }
//}
//
//bool isStudentSelected(Course course, int studentId) {
//    for (int i = 0; i < MAX_STUDENTS; i++) {
//        if (course.selectedStudents[i] == studentId) {
//            return true;
//        }
//    }
//    return false;
//}
//
//void countCourseCredit() {
//    int numCourses = sizeof(courses) / sizeof(courses[0]); // 获取课程总数
//    int studentId;
//    printf("请输入要查询总学分数的学生的ID：");
//    scanf("%d", &studentId);
//
//    int totalCredit = 0;
//    for (int i = 0; i < numCourses; i++) {
//        Course course = courses[i];
//        if (isStudentSelected(course, studentId)) {
//            totalCredit += course.credit;
//        }
//    }
//
//    printf("学生%d的总学分数为：%d\n", studentId, totalCredit);
//}
//
//
//
//
//// 文件保存模块
//void saveToFile() {
//    int numCourses = sizeof(courses) / sizeof(courses[0]); // 获取课程总数
//    int numStudents = sizeof(students) / sizeof(students[0]); // 获取课程总数
//
//    FILE* fp = fopen("data.txt", "w"); // 打开文件
//    if (fp == NULL) {
//        printf("Error opening file.\n");
//        return;
//    }
//
//    // 写入课程信息
//    for (int i = 0; i < numCourses; i++) {
//        Course course = courses[i];
//        fprintf(fp, "%d %s %d %d %d\n", course.id, course.name, course.credit, course.maxCount, course.selectedCount);
//        for (int j = 0; j < course.selectedCount; j++) {
//            fprintf(fp, "%d ", course.selectedStudents[j]);
//        }
//        fprintf(fp, "\n");
//    }
//
//    // 写入学生信息
//    for (int i = 0; i < numStudents; i++) {
//        Student student = students[i];
//        fprintf(fp, "%d %s %d\n", student.id, student.name, student.selectedCount);
//        for (int j = 0; j < student.selectedCount; j++) {
//            fprintf(fp, "%d ", student.selectedCourses[j]);
//        }
//        fprintf(fp, "\n");
//    }
//
//    fclose(fp); // 关闭文件
//}
//
//
//
//
//// 读取学生信息
//void readFromFile() {
//    FILE* fp = fopen("data.txt", "r"); // 打开文件
//    if (fp == NULL) {
//        printf("Error opening file.\n");
//        return;
//    }
//
//    // 读取课程信息
//    int numCourses = sizeof(courses) / sizeof(courses[0]); // 获取课程总数
//    for (int i = 0; i < numCourses; i++) {
//        Course course;
//        fscanf(fp, "%d %s %d %d %d", &course.id, course.name, &course.credit, &course.maxCount, &course.selectedCount);
//        for (int j = 0; j < course.selectedCount; j++) {
//            fscanf(fp, "%d", &course.selectedStudents[j]);
//        }
//        courses[i] = course;
//    }
//
//    // 读取学生信息
//    int numStudents = sizeof(students) / sizeof(students[0]); // 获取学生总数
//    for (int i = 0; i < numStudents; i++)
//    {
//        Student student;
//        fscanf(fp, "%d %s %d", &student.id, student.name, &student.selectedCount);
//        for (int j = 0; j < student.selectedCount; j++) {
//            fscanf(fp, "%d", &student.selectedCourses[j]);
//        }
//        students[i] = student;
//    }
//
//    fclose(fp); // 关闭文件
//}
//
//
//
//
//// 主函数
//int main()
//{
//    int choice;
//    do
//    {
//        menu();
//        scanf("%d", &choice);
//        switch (choice)
//        {
//        case 1:
//            addCourse();
//            break;
//        case 2:
//            viewCourses();
//            break;
//        case 3:
//          
//            break;
//        case 4:
//         
//            break;
//        case 5:
//         
//            break;
//        case 6:
//            break;
//        default:
//            printf("输入错误格式，请重新输入\n");
//        }
//    } while (choice);
//}
//
