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
//    int* trees = (int*)malloc((L + 1) * sizeof(int));  // ��̬�����ڴ�
//    for (int i = 0; i <= L; i++) {
//        trees[i] = 1;  // ѭ����ʼ�����飬��������λ�ö�Ϊ1
//    }
//
//    int start, end;
//    for (int i = 1; i <= M; i++) {
//        scanf("%d %d", &start, &end);
//        for (int j = start; j <= end; j++) {
//            trees[j] = 0;  // ����Ҫ�Ƴ�������λ�ñ��Ϊ0
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
//    free(trees);  // �ͷ��ڴ�
//
//    return 0;
