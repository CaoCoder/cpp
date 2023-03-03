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
//// �γ���Ϣ�ṹ��
//struct Course {
//    int id; // �γ̱��
//    char name[50]; // �γ�����
//    int credit; // �γ�ѧ��
//    int selectedCount; // �γ���ѡ����
//    int maxCount; // �γ���������
//    int selectedStudents[MAX_STUDENTS]; // ��ѡ�ÿγ̵�ѧ��ѧ������
//};
//
//// ѧ����Ϣ�ṹ��
//struct Student {
//    char name[50]; // ѧ������
//    int id; // ѧ��ѧ��
//    int selectedCourses[MAX_COURSES]; // ѧ����ѡ�γ����飬�洢�γ̱��
//    int selectedCount; // ѧ����ѡ�γ���Ŀ
//};
//
//// �γ������ѧ������
//struct Course courses[MAX_COURSES];
//struct Student students[MAX_STUDENTS];
//
//int courseCount = 0; // ��ǰ�γ���Ŀ
//int studentCount = 0; // ��ǰѧ����Ŀ
//
//// �γ̹���ģ��
//void addCourse() {
//    // �����ǰ�γ���Ŀ�Ѿ��ﵽ���ޣ����޷�����¿γ�
//    if (courseCount >= MAX_COURSES) {
//        printf("�޷�����¿γ̣��Ѵﵽ�γ���Ŀ���ޣ�\n");
//        return;
//    }
//
//    // �����¿γ���Ϣ
//    printf("�������¿γ���Ϣ��\n");
//    struct Course newCourse;
//    printf("�γ̱�ţ�");
//    scanf("%d", &newCourse.id);
//    printf("�γ����ƣ�");
//    scanf("%s", newCourse.name);
//    printf("�γ�ѧ�֣�");
//    scanf("%d", &newCourse.credit);
//    printf("�γ��������ޣ�");
//    scanf("%d", &newCourse.maxCount);
//    newCourse.selectedCount = 0; // ��ʼ����ѡ����Ϊ0
//
//    // ���¿γ���ӵ��γ�������
//    courses[courseCount] = newCourse;
//    courseCount++;
//
//    printf("�¿γ���ӳɹ���\n");
//}
//void menu()
//{
//    printf("��ѡ��Ҫִ�еĹ��ܣ�\n");
//    printf("1. ��ӿγ�\n");
//    printf("2. ����γ�\n");
//    printf("3. ɾ���γ�\n");
//    printf("3. ɾ���γ�\n");
//    printf("3. ɾ���γ�\n");
//    printf("3. ɾ���γ�\n");
//    printf("3. ɾ���γ�\n");
//    printf("3. ɾ���γ�\n");
//    printf("3. ɾ���γ�\n");
//    printf("3. ɾ���γ�\n");
//
//}
//
//void viewCourses() {
//    if (courseCount == 0) {
//        printf("��ǰû�пγ���Ϣ��������ӿγ�\n");
//        return;
//    }
//    printf("�γ̱��\t�γ�����\t�γ�ѧ��\t��ѡ����\t��������\n");
//    for (int i = 0; i < courseCount; i++) {
//        printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n",
//            courses[i].id, courses[i].name, courses[i].credit,
//            courses[i].selectedCount, courses[i].maxCount);
//    }
//}
//
//// ��ѧ��id��ӵ�ָ���γ̵���ѡѧ��������
//void addSelectedStudentToCourse(int courseId, int studentId) {
//    for (int i = 0; i < courseCount; i++) {
//        if (courses[i].id == courseId) {
//            if (courses[i].selectedCount < courses[i].maxCount) {
//                courses[i].selectedStudents[courses[i].selectedCount++] = studentId;
//                students[studentId].selectedCourses[students[studentId].selectedCount++] = courseId;
//                printf("ѧ�� %s �ɹ�ѡ���˿γ� %s��\n", students[studentId].name, courses[i].name);
//            }
//            else {
//                printf("�γ� %s �������������޷���ѡ�ޡ�\n", courses[i].name);
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
//        // û���ҵ���ѧ����ֱ�ӷ���
//        return;
//    }
//    // �������ѧ��id��ǰ�ƶ�һ��λ��
//    for (; i < course->selectedCount - 1; i++) {
//        course->selectedStudents[i] = course->selectedStudents[i + 1];
//    }
//    course->selectedCount--;
//}
//
//
//void deleteCourse() {
//    int courseId;
//    printf("������Ҫɾ���Ŀγ̱�ţ�");
//    scanf("%d", &courseId);
//
//    int i, j;
//    for (i = 0; i < courseCount; i++) {
//        if (courses[i].id == courseId) {
//            // ���ÿγ̴�������ɾ�������������е�����Ԫ����ǰ�ƶ�
//            for (j = i; j < courseCount - 1; j++) {
//                courses[j] = courses[j + 1];
//            }
//            // ���µ�ǰ�γ���Ŀ
//            courseCount--;
//            printf("�γ�ɾ���ɹ���\n");
//            return;
//        }
//    }
//    printf("δ�ҵ��ÿγ̣�ɾ��ʧ�ܣ�\n");
//}
//
//
//// ѧ������ģ��
//void studentLogin() {
//    int studentId;
//    printf("������ѧ�ţ�");
//    scanf("%d", &studentId);
//    for (int i = 0; i < studentCount; i++) {
//        if (students[i].id == studentId) {
//            printf("��ӭ��¼��%sͬѧ��\n", students[i].name);
//            return;
//        }
//    }
//    printf("δ�ҵ���ѧ�Ŷ�Ӧ��ѧ����Ϣ����ȷ�������Ƿ���ȷ��\n");
//}
//
//
//void studentViewCourses() {
//    // �����γ����飬������пγ���Ϣ
//    for (int i = 0; i < courseCount; i++) {
//        printf("�γ̱�ţ�%d\n", courses[i].id);
//        printf("�γ����ƣ�%s\n", courses[i].name);
//        printf("�γ�ѧ�֣�%d\n", courses[i].credit);
//        printf("�γ���ѡ������%d\n", courses[i].selectedCount);
//        printf("�γ��������ޣ�%d\n", courses[i].maxCount);
//        printf("\n");
//    }
//}
//
//
//void studentSelectCourse() {
//    int studentId;
//    printf("����������ѧ�ţ�");
//    scanf("%d", &studentId);
//
//    // ���Ҷ�Ӧѧ��
//    int studentIndex = -1;
//    for (int i = 0; i < studentCount; i++) {
//        if (students[i].id == studentId) {
//            studentIndex = i;
//            break;
//        }
//    }
//    if (studentIndex == -1) {
//        printf("û���ҵ���ѧ����\n");
//        return;
//    }
//
//    // ��ӡ���пγ���Ϣ
//    printf("���п�ѡ�γ���Ϣ���£�\n");
//    for (int i = 0; i < courseCount; i++) {
//        printf("%d\t%s\t%d\t%d/%d\n", courses[i].id, courses[i].name, courses[i].credit, courses[i].selectedCount, courses[i].maxCount);
//    }
//
//    // ��ѧ��ѡ��γ�
//    printf("��������Ҫѡ�޵Ŀγ̱�ţ�");
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
//        printf("û���ҵ��ÿγ̣�\n");
//        return;
//    }
//    if (courses[courseIndex].selectedCount >= courses[courseIndex].maxCount) {
//        printf("�ÿγ��Ѿ�ѡ������ѡ�������γ̣�\n");
//        return;
//    }
//
//    // ��ӿγ�
//    courses[courseIndex].selectedStudents[courses[courseIndex].selectedCount++] = studentId;
//    students[studentIndex].selectedCourses[students[studentIndex].selectedCount++] = courseId;
//    printf("ѡ�γɹ���\n");
//}
//
//
//// ��ѯ����ģ��
//void queryByCredit() {
//    int credit;
//    printf("������Ҫ��ѯ��ѧ������");
//    scanf("%d", &credit);
//    printf("ѧ��Ϊ %d �Ŀγ����£�\n", credit);
//    for (int i = 0; i < courseCount; i++) {
//        if (courses[i].credit == credit) {
//            printf("�γ̱�ţ�%d���γ����ƣ�%s��ѧ�֣�%d����ѡ������%d���������ޣ�%d\n",
//                courses[i].id, courses[i].name, courses[i].credit, courses[i].selectedCount, courses[i].maxCount);
//        }
//    }
//}
//
//
//void queryByProperty() {
//    char property[20];
//    printf("������Ҫ��ѯ�Ŀγ�������");
//    scanf("%s", property);
//    for (int i = 0; i < courseCount; i++) {
//        if (strcmp(courses[i].name, property) == 0) {
//            printf("�γ̱�ţ�%d���γ����ƣ�%s��ѧ�֣�%d\n", courses[i].id, courses[i].name, courses[i].credit);
//        }
//    }
//}
//
//
//void queryStudentCourses() {
//    // ѧ��ѡ�޿γ̲�ѯ����
//}
//
//// ͳ�ƹ���ģ��
//void countCourseSelected() {
//    int numCourses = sizeof(courses) / sizeof(courses[0]); // ��ȡ�γ�����
//    for (int i = 0; i < numCourses; i++) {
//        int count = courses[i].selectedCount; // ��ȡѡ������
//        printf("�γ����ƣ�%s��ѡ��������%d\n", courses[i].name, count);
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
//    int numCourses = sizeof(courses) / sizeof(courses[0]); // ��ȡ�γ�����
//    int studentId;
//    printf("������Ҫ��ѯ��ѧ������ѧ����ID��");
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
//    printf("ѧ��%d����ѧ����Ϊ��%d\n", studentId, totalCredit);
//}
//
//
//
//
//// �ļ�����ģ��
//void saveToFile() {
//    int numCourses = sizeof(courses) / sizeof(courses[0]); // ��ȡ�γ�����
//    int numStudents = sizeof(students) / sizeof(students[0]); // ��ȡ�γ�����
//
//    FILE* fp = fopen("data.txt", "w"); // ���ļ�
//    if (fp == NULL) {
//        printf("Error opening file.\n");
//        return;
//    }
//
//    // д��γ���Ϣ
//    for (int i = 0; i < numCourses; i++) {
//        Course course = courses[i];
//        fprintf(fp, "%d %s %d %d %d\n", course.id, course.name, course.credit, course.maxCount, course.selectedCount);
//        for (int j = 0; j < course.selectedCount; j++) {
//            fprintf(fp, "%d ", course.selectedStudents[j]);
//        }
//        fprintf(fp, "\n");
//    }
//
//    // д��ѧ����Ϣ
//    for (int i = 0; i < numStudents; i++) {
//        Student student = students[i];
//        fprintf(fp, "%d %s %d\n", student.id, student.name, student.selectedCount);
//        for (int j = 0; j < student.selectedCount; j++) {
//            fprintf(fp, "%d ", student.selectedCourses[j]);
//        }
//        fprintf(fp, "\n");
//    }
//
//    fclose(fp); // �ر��ļ�
//}
//
//
//
//
//// ��ȡѧ����Ϣ
//void readFromFile() {
//    FILE* fp = fopen("data.txt", "r"); // ���ļ�
//    if (fp == NULL) {
//        printf("Error opening file.\n");
//        return;
//    }
//
//    // ��ȡ�γ���Ϣ
//    int numCourses = sizeof(courses) / sizeof(courses[0]); // ��ȡ�γ�����
//    for (int i = 0; i < numCourses; i++) {
//        Course course;
//        fscanf(fp, "%d %s %d %d %d", &course.id, course.name, &course.credit, &course.maxCount, &course.selectedCount);
//        for (int j = 0; j < course.selectedCount; j++) {
//            fscanf(fp, "%d", &course.selectedStudents[j]);
//        }
//        courses[i] = course;
//    }
//
//    // ��ȡѧ����Ϣ
//    int numStudents = sizeof(students) / sizeof(students[0]); // ��ȡѧ������
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
//    fclose(fp); // �ر��ļ�
//}
//
//
//
//
//// ������
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
//            printf("��������ʽ������������\n");
//        }
//    } while (choice);
//}
//
