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
            printf("地点列表：\n");
            for (int i = 0; i < VERTICES; i++) {
                printf("%d: %s\n", locations[i].id, locations[i].name);
            }
            break;
        case 3:
            printf("请输入出发地点ID: ");
            scanf("%d", &source);
            printf("请输入目的地ID: ");
            scanf("%d", &destination);
            findShortestPath(source, destination, graph);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("输入错误，请重新输入。\n");
            break;
        }
    }
    return 0;
}



