#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000  // ���洢�ĵ�����
#define MAX_WORD_LEN 50  // ���ʵ���󳤶�

char words[MAX_WORDS][50];  // �洢���ʵĶ�ά����
int num_words = 0;  // �Ѵ洢�ĵ�����

// ����¼��ģ��
void input_words();
int check_word(char* word);
void remove_duplicate_words();
void sort_words();

// �ļ��洢ģ��
void save_words_to_file();
void load_words_from_file();

// �������ģ��
void display_words();
void search_word(char* word);

int main() {
    int choice;
    while (1) {
        // ��ʾ�˵�
        printf("��ѡ�������\n");
        printf("1. ¼�뵥��\n");
        printf("2. �洢����\n");
        printf("3. ���ص���\n");
        printf("4. ��ʾ����\n");
        printf("5. ��������\n");
        printf("6. �˳�\n");

        // ��ȡ�û�ѡ��
        printf("��ѡ�������ţ�");
        scanf("%d", &choice);

        // �����û�ѡ��ִ����Ӧ�Ĳ���
        switch (choice) {
        case 1:
            input_words();
            break;
        case 2:
            save_words_to_file();
            break;
        case 3:
            load_words_from_file();
            break;
        case 4:
            display_words();
            break;
        case 5:
            char search_wor[MAX_WORD_LEN];
            printf("������Ҫ�����ĵ��ʣ�");
            scanf("%s", search_wor);
            search_word(search_wor);
            break;
        case 6:
            printf("ллʹ�ã��ټ���\n");
            return 0;
        default:
            printf("��Ч�Ĳ�����ţ�������ѡ��\n");
            break;
        }
    }
    return 0;
}

void input_words() {
    char word[50]; // �洢����ĵ���
    int i;
    while (1) {
        printf("�����뵥�ʣ�����0�������룩��");
        scanf("%s", word);
        if (strcmp(word, "0") == 0) {
            break; // ����0��������
        }
        if (check_word(word) == 0) {
            printf("�����Ѵ��ڣ����������룡\n");
            continue; // �����Ѵ��ڣ���������
        }
        strcpy(words[num_words], word); // �����ʴ洢��words������
        num_words++; // ���µ�������
        if (num_words == MAX_WORDS) {
            printf("���������Ѵﵽ���ޣ��޷��������룡\n");
            break; // ���������Ѵﵽ���ޣ���������
        }
    }
}

int check_word(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i], word) == 0) {
            return 0; // �����Ѵ���
        }
    }
    return 1; // ���ʲ�����
}

void remove_duplicate_words() {
    int i, j, k;
    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words;) {
            if (strcmp(words[i], words[j]) == 0) {
                for (k = j; k < num_words - 1; k++) {
                    strcpy(words[k], words[k + 1]); // ������ĵ�����ǰ�ƶ�
                }
                num_words--; // ���µ�������
            }
            else {
                j++;
            }
        }
    }
}

void sort_words() {
    int i, j;
    char temp[50];
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                strcpy(temp, words[i]); // �����������ʵ�λ��
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

void save_words_to_file() {
    FILE* fp;
    fp = fopen("data.txt", "w"); // ���ļ�����д��ģʽ�򿪣�����ļ����������½��ļ�
    if (fp == NULL) {
        printf("�޷����ļ���\n");
        return;
    }
    for (int i = 0; i < num_words; i++) {
        fprintf(fp, "%s\n", words[i]); // ������д���ļ���ÿ��һ������
    }
    fclose(fp); // �ر��ļ�
    printf("�ѽ����ʱ��浽data.txt�ļ��С�\n");
}

void load_words_from_file() {
    FILE* fp;
    fp = fopen("data.txt", "r"); // ���ļ����Զ�ȡģʽ��
    if (fp == NULL) {
        printf("�޷����ļ���\n");
        return;
    }
    char word[20];
    while (fscanf(fp, "%s", word) != EOF) { // ���ж�ȡ�ļ��еĵ��ʣ�ֱ���ļ�����
    
           strcpy(words[num_words], word); // ������ʲ����ڣ��򽫵��ʴ���������
           num_words++;
    }
    fclose(fp); // �ر��ļ�
    printf("�Ѵ�data.txt�ļ��ж�ȡ%d�����ʡ�\n", num_words);
}


void display_words() {
    printf("��ǰ�����б�\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }
}

void search_word(char* word) {
    int found = 0;
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], word) == 0) {
            printf("%s �Ѿ��ڵ����б����ˣ�\n", word);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("%s ���ڵ����б��С�\n", word);
    }
}
