#define _CRT_SECURE_NO_WARNINGS 1
#include "print.h"
#include "location.h"
#include "mindistance.h"
#include "find.h"




int main() {
    int choice;
    int source, destination;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printCampusMap();
            break;
        case 2:
            printf("�ص��б�\n");
            for (int i = 0; i < VERTICES; i++) {
                printf("%d: %s\n", locations[i].id, locations[i].name);
            }
            break;
        case 3:
            printf("����������ص�ID: ");
            scanf("%d", &source);
            printf("������Ŀ�ĵ�ID: ");
            scanf("%d", &destination);
            findShortestPath(source, destination, graph);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("����������������롣\n");
            break;
        }
    }
    return 0;
}



