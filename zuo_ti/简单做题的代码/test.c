//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct list {
//    int data;
//    struct list* next;
//} list;
//
//void creatlist(list** head, int n) {
//    list* p = NULL;
//    list* tail = *head;
//    for (int i = 0; i < n; i++) {
//        p = (list*)malloc(sizeof(list));
//        scanf("%d", &(p->data));
//        p->next = NULL;
//        tail->next = p;
//        tail = p;
//    }
//}
//
//void printlist(list* head) {
//    list* p = head->next;
//    while (p != NULL) {
//        printf("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//int main() {
//    list* head = (list*)malloc(sizeof(list));
//    head->next = NULL;
//    int n;
//    scanf("%d", &n);
//    creatlist(&head, n);
//    printlist(head);
//    return 0;
//}