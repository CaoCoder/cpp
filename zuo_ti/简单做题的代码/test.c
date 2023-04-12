//#define  _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdio.h>
////int func(int x)
////{
////	int count = 0;
////	while (x)
////	{
////		count++;
////		x = x & (x - 1);
////	}
////	return count;
////}
////int main() {
////	
////	printf("%d", func(9999));
////	return 0;
////}
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int L, M;
//    scanf("%d %d", &L, &M);
//
//    int* trees = (int*)malloc((L + 1) * sizeof(int));  // 动态分配内存
//    for (int i = 0; i <= L; i++) {
//        trees[i] = 1;  // 循环初始化数组，所有树的位置都为1
//    }
//
//    int start, end;
//    for (int i = 1; i <= M; i++) {
//        scanf("%d %d", &start, &end);
//        for (int j = start; j <= end; j++) {
//            trees[j] = 0;  // 将需要移除的树的位置标记为0
//        }
//    }
//
//    int count = 0;
//    for (int i = 0; i <= L; i++) {
//        if (trees[i] == 1) {
//            count++;
//        }
//    }
//
//    printf("%d\n", count);
//
//    free(trees);  // 释放内存
//
//    return 0;
