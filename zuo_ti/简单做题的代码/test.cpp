#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cmath>
//1.当已知K时, 通过公式, 求出附录图纵坐标X_j，公式为X_j = K / ((π ^ 4 EI) / l ^ 3)求出X_j
//2.再通过附录表格查询对应的n时，X_j在图中对应的，再通过λ公式求出T_E的数据
//3.当已知T_E时，求出λ为附录图横坐标，公式为λ = T_E / T_0 公式求出λ
//4.再通过附录表格查询对应n时，入对应的X_j，通过X_j = K / ((π ^ 4 EI) / l ^ 3)公式求出K的数据
//其中l，n，I，E都是输入的数据，X_j和T_E和λ和K都是要输出的数据。其中K是要自动算出来的，不需要我手动去查询附录的那种
//#define M_PI 3.14
//#include <stdio.h>
//#include <math.h>
//
//#define XJ_MIN 0
//#define XJ_MAX 0.4
//#define XJ_STEP 0.1
//
//#define LAMBDA_MIN 0
//#define LAMBDA_MAX 1
//#define LAMBDA_STEP 0.2
//
//#define N_MIN 2
//#define N_MAX 10
//
//double calc_Xj(double K, double l, double I, double E) {
//    double denominator = pow(M_PI, 2) * E * I / pow(l, 2);
//    return K / denominator;
//}
//
//double calc_lambda(double TE, double l, double I, double E) {
//    double T0 = pow(M_PI, 2) * E * I / l;
//    return TE * pow(l, 2) / T0 / pow(M_PI, 2) / E / I;
//}
//
//int main() {
//    // 输入数据
//    double l, I, E, TE;
//    int n;
//    printf("请输入连续压杆跨度数n：");
//    scanf("%d", &n);
//    if (n < N_MIN || n > N_MAX) {
//        printf("n不在附录表格范围内！\n");
//        return 1;
//    }
//    printf("请输入每跨长度l：");
//    scanf("%lf", &l);
//    printf("请输入断面惯性矩I：");
//    scanf("%lf", &I);
//    printf("请输入弹性模数E：");
//    scanf("%lf", &E);
//
//    // 已知K求Xj和lambda
//    double K, Xj, lambda;
//    printf("请输入弹性支座的刚性系数K：");
//    scanf("%lf", &K);
//    Xj = calc_Xj(K, l, I, E);
//    printf("请查询附录表格，输入对应的n：");
//    scanf("%d", &n);
//    if (n < N_MIN || n > N_MAX) {
//        printf("n不在附录表格范围内！\n");
//        return 1;
//    }
//    Xj = (n - 1) * XJ_STEP + XJ_MIN;
//    printf("对应的Xj在图中的纵坐标为：%.1lf\n", (Xj - XJ_MIN) / XJ_STEP);
//    lambda = calc_lambda(Xj * pow(M_PI, 2) * E * I / l, l, I, E);
//    printf("lambda = %.2lf\n", lambda);
//
//    // 已知TE求lambda和K
//    printf("请输入欧拉力TE：");
//    scanf("%lf", &TE);
//    lambda = calc_lambda(TE * pow(M_PI, 2) * E * I / l, l, I, E);
//    printf("请查询附录表格，输入对应的n：");
//    scanf("%d", &n);
//    if (n < N_MIN || n > N_MAX) {
//        printf("n不在附录表格范围内！\n");
//        return 1;
//    }
//    Xj = (n - 1) * XJ_STEP + XJ_MIN;
//    K = Xj * pow(M_PI, 2) * E * I / pow(l, 2) / 10000;
//    printf("K = %.4lf\n", K);
//
//    return 0;
//
//}
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	printf("请输入一个不小于6的偶数：");
	scanf("%d", &n);
	if (n < 6 || n % 2 != 0) {
		printf("输入不合法！\n");
		return 1;
	}
	for (int i = 2; i <= n / 2; i++) {
		if (is_prime(i) && is_prime(n - i)) {
			printf("%d=%d+%d\n", n, i, n - i);
		}
	}
	return 0;
}