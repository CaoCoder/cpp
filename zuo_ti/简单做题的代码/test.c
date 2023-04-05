//#include?<stdio.h>
//#include?<stdlib.h>
//int?main()
//{
//	long?long????int?x, l, j = 0, c, i = 0;
//	int?a[100], b[100];
//	scanf("%lld", &x);//有几组数据
//p:
//	while (j < x) {
//		scanf("%lld", &l);
//		goto?s;
//	}
//s:
//	for (int?i = 0; i < l; i++) {
//		scanf("%d", &a[i]);
//
//	}
//	c = 0;
//	for (int?i = 0; i < l; i++) {
//		if (a[i] % 2 != 0) {
//			c++;
//		}
//	}
//	if (i < l) {
//		b[i] = c;
//		i++;
//	}
//	j++;
//	while (j < x) {
//		goto?p;
//	}
//
//	for (int?i = 0; i < x; i++) {
//		printf("%d\t", b[i]);
//	}
//
//	return?0;
//}