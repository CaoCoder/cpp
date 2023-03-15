#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000  // 最多存储的单词数
#define MAX_WORD_LEN 50  // 单词的最大长度

char words[MAX_WORDS][50];  // 存储单词的二维数组
int num_words = 0;  // 已存储的单词数

// 单词录入模块
void input_words();
int check_word(char* word);
void remove_duplicate_words();
void sort_words();

// 文件存储模块
void save_words_to_file();
void load_words_from_file();

// 单词浏览模块
void display_words();
void search_word(char* word);

int main() {
    int choice;
    while (1) {
        // 显示菜单
        printf("请选择操作：\n");
        printf("1. 录入单词\n");
        printf("2. 存储单词\n");
        printf("3. 加载单词\n");
        printf("4. 显示单词\n");
        printf("5. 搜索单词\n");
        printf("6. 退出\n");

        // 读取用户选择
        printf("请选择操作编号：");
        scanf("%d", &choice);

        // 根据用户选择执行相应的操作
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
            printf("请输入要搜索的单词：");
            scanf("%s", search_wor);
            search_word(search_wor);
            break;
        case 6:
            printf("谢谢使用，再见！\n");
            return 0;
        default:
            printf("无效的操作编号，请重新选择。\n");
            break;
        }
    }
    return 0;
}

void input_words() {
    char word[50]; // 存储输入的单词
    int i;
    while (1) {
        printf("请输入单词（输入0结束输入）：");
        scanf("%s", word);
        if (strcmp(word, "0") == 0) {
            break; // 输入0结束输入
        }
        if (check_word(word) == 0) {
            printf("单词已存在，请重新输入！\n");
            continue; // 单词已存在，重新输入
        }
        strcpy(words[num_words], word); // 将单词存储到words数组中
        num_words++; // 更新单词数量
        if (num_words == MAX_WORDS) {
            printf("单词数量已达到上限，无法继续输入！\n");
            break; // 单词数量已达到上限，结束输入
        }
    }
}

int check_word(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i], word) == 0) {
            return 0; // 单词已存在
        }
    }
    return 1; // 单词不存在
}

void remove_duplicate_words() {
    int i, j, k;
    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words;) {
            if (strcmp(words[i], words[j]) == 0) {
                for (k = j; k < num_words - 1; k++) {
                    strcpy(words[k], words[k + 1]); // 将后面的单词向前移动
                }
                num_words--; // 更新单词数量
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
                strcpy(temp, words[i]); // 交换两个单词的位置
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

void save_words_to_file() {
    FILE* fp;
    fp = fopen("data.txt", "w"); // 打开文件，以写入模式打开，如果文件不存在则新建文件
    if (fp == NULL) {
        printf("无法打开文件！\n");
        return;
    }
    for (int i = 0; i < num_words; i++) {
        fprintf(fp, "%s\n", words[i]); // 将单词写入文件，每行一个单词
    }
    fclose(fp); // 关闭文件
    printf("已将单词保存到data.txt文件中。\n");
}

void load_words_from_file() {
    FILE* fp;
    fp = fopen("data.txt", "r"); // 打开文件，以读取模式打开
    if (fp == NULL) {
        printf("无法打开文件！\n");
        return;
    }
    char word[20];
    while (fscanf(fp, "%s", word) != EOF) { // 逐行读取文件中的单词，直到文件结束
    
           strcpy(words[num_words], word); // 如果单词不存在，则将单词存入数组中
           num_words++;
    }
    fclose(fp); // 关闭文件
    printf("已从data.txt文件中读取%d个单词。\n", num_words);
}


void display_words() {
    printf("当前单词列表：\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }
}

void search_word(char* word) {
    int found = 0;
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], word) == 0) {
            printf("%s 已经在单词列表中了！\n", word);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("%s 不在单词列表中。\n", word);
    }
}
