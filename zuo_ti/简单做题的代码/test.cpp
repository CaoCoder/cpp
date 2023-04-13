#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cmath>
//1.当已知K时, 通过公式, 求出附录图纵坐标X_j，公式为X_j = K / ((π ^ 4 EI) / l ^ 3)求出X_j
//2.再通过附录表格查询对应的n时，X_j在图中对应的，再通过λ公式求出T_E的数据
//3.当已知T_E时，求出λ为附录图横坐标，公式为λ = T_E / T_0 公式求出λ
//4.再通过附录表格查询对应n时，入对应的X_j，通过X_j = K / ((π ^ 4 EI) / l ^ 3)公式求出K的数据
//其中l，n，I，E都是输入的数据，X_j和T_E和λ和K都是要输出的数据。其中K是要自动算出来的，不需要我手动去查询附录的那种
#define M_PI 3.14
//#include <stdio.h>
//#include <math.h>
//
//// 附录数据
//double lookup_table[9][5] = {
//    
//};
//
//// 查找附录表格，返回对应的X_j
//double lookup_Xj(int n, double lambda) {
//    // 遍历二维数组，查找对应的X_j
//    for (int i = 0; i < 9; i++) {
//        if (lookup_table[i][0] == n && lookup_table[i][1] == lambda) {
//            return lookup_table[i][2];
//        }
//    }
//    // 没有找到对应的X_j，返回0
//    return 0;
//}
//
//// 已知K时，求X_j
//double calculate_Xj(double K, double l, double E, double I) {
//    return K / (pow(M_PI, 4) * E * I / pow(l, 3));
//}
//
//// 已知T_E时，求λ
//double calculate_lambda(double T_E, double l, double E, double I) {
//    return T_E / ((pow(M_PI, 2) * E * I) / pow(l, 2));
//}
//
//
//
//// 使用X_j求K
//double calculate_K(double X_j, double l, double E, double I) {
//    return X_j * (pow(M_PI, 4) * E * I / pow(l, 3));
//}
//
//int main() {
//    int mode, n;
//    double l, E, I, T_E, K, X_j, lambda;
//
//    printf("选择计算模式 (1: 已知K求T_E, 2: 已知T_E求K): ");
//    scanf("%d", &mode);
//    printf("请输入连续压杆跨度数 n: ");
//    scanf("%d", &n);
//    printf("请输入每跨的长度 l: ");
//    scanf("%lf", &l);
//    printf("请输入材料的弹性模数 E: ");
//    scanf("%lf", &E);
//    printf("请输入压杆的断面惯性矩 I: ");
//    scanf("%lf", &I);
//
//    if (mode == 1) {
//        printf("请输入弹性支座的刚性系数 K: ");
//        scanf("%lf", &K);
//        X_j = calculate_Xj(K, l, E, I);
//        lambda = lookup_Xj(n, X_j);
//        T_E = lambda * (pow(M_PI, 2) * E * I) / pow(l, 2);
//        printf("结果: T_E = %.2lf\n", T_E);
//    }
//    else if (mode == 2) {
//        printf("请输入欧拉力 T_E: ");
//        scanf("%lf", &T_E);
//        lambda = calculate_lambda(T_E, l, E, I);
//        X_j = lookup_Xj(n, lambda);
//        K = calculate_K(X_j, l, E, I);
//        printf("结果: K = %.2lf\n", K);
//    }
//    else {
//        printf("无效的计算模式！\n");
//    }
//
//    return 0;
//}
/*情况1*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

int main() {
	double l = 800.0; // mm
	double I = 267000; // mm^4
	double E = 200000; // N/mm^2
	double lambda = 0;

	int n = 0;
	cout << "请输入 n:";
	scanf("%d", &n);
	if (n > 10 || n < 0)
	{
		cout << "输入错误,请重新输入" << endl;
		return 0;
	}
	srand(time(NULL));
	double randNum = (double)rand() / RAND_MAX;
	// (1) 已知弹性支座刚性系数 K，求压杆欧拉力
	double K = 4.8; // N/mm
	cout << "请输入弹性支座刚性系数 K:";
	scanf("%lf", &K);
	double X = K / pow(M_PI, 4);


	double F = (randNum * pow(M_PI, 2) * E * I / pow(l, 2)) / 1000;
	printf("弹性支座刚性系数 K = %lf N/mm\n", K);
	printf("压杆欧拉力 F = %lf KN\n", F);

	// (2) 已知压杆欧拉力，求必需弹性支座刚性系数
	double T_E = 0; // N
	cout << "请输入压杆欧拉力:";
	scanf("%lf", &T_E);
	double T_0 = (pow(M_PI, 2) * E * I) / pow(l, 2);
	lambda = T_E / T_0;
	X = randNum; // 
	K = X * ((pow(M_PI, 4) * E * I) / pow(l, 3));
	printf("所需弹性支座刚性系数 K = %lf N/mm\n", K);

	return 0;

}
//
//#include <stdio.h>
//#include <math.h>
//
//double calculate_K(double l, double n, double I, double E, double T_E) {
//    double pi = M_PI;
//    double T_0 = 0.5 * pi * pi * E * I / pow(l * n, 2);
//    double Fcr = pi * pi * E * I / pow(l * n, 2);
//    double T = sqrt(T_E * Fcr);
//    double X_j = pow(pi * T / (l * sqrt(E * I * T_0 / T_E)), 2);
//    double K = X_j * pow(Fcr / T_0, 3) / pow(T_0, 2);
//    return K;
//}

/*情况2*/
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    double l, I, E, X_j, lambda_val, T_E;
//    int n;
//
//    // 输入梁的每跨长度l、附录表格中对应的n、压杆的断面惯性矩I、材料的弹性模数E、以及附录图中对应的X_j值
//    printf("请输入梁的每跨长度l：");
//    scanf("%lf", &l);
//    printf("请输入附录表格中对应的n：");
//    scanf("%d", &n);
//    printf("请输入压杆的断面惯性矩I：");
//    scanf("%lf", &I);
//    printf("请输入材料的弹性模数E：");
//    scanf("%lf", &E);
//    printf("请输入附录图中对应的X_j：");
//    scanf("%lf", &X_j);
//
//    // 根据公式计算λ值
//    lambda_val = sqrt(pow(M_PI, 2) * E * I / pow(l, 2));
//
//    // 根据公式计算欧拉力T_E
//    T_E = n * pow(M_PI, 2) * E * I / pow(l, 2) * X_j / pow(lambda_val, 4);
//
//    // 输出结果
//    printf("欧拉力T_E的值为：%lf\n", T_E);
//
//    return 0;
//}

/*情况3*/

//#include <stdio.h>
//
//int main() {
//    double T_0, T_E, lambda_val;
//
//    // 输入临界欧拉力T_0和已知的欧拉力T_E
//    printf("请输入临界欧拉力T_0：");
//    scanf("%lf", &T_0);
//    printf("请输入已知的欧拉力T_E：");
//    scanf("%lf", &T_E);
//
//    // 根据公式计算λ
//    lambda_val = T_E / T_0;
//
//    // 输出结果
//    printf("λ的值为：%lf\n", lambda_val);
//
//    return 0;
//}

/*情况4*/
//
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    double l, I, E, X_j, lambda_val, T_E, K;
//    int n;
//
//    // 输入梁的每跨长度l、压杆的断面惯性矩I、材料的弹性模数E、X_j值和已知的欧拉力T_E
//    printf("请输入梁的每跨长度l：");
//    scanf("%lf", &l);
//    printf("请输入压杆的断面惯性矩I：");
//    scanf("%lf", &I);
//    printf("请输入材料的弹性模数E：");
//    scanf("%lf", &E);
//    printf("请输入已知的X_j值：");
//    scanf("%lf", &X_j);
//
//    // 根据公式计算K的值
//    K = X_j * pow((M_PI * M_PI * E * I) / pow(l, 3), -1);
//
//    // 定义表格数据
//    double X_j_array[5][6] = {
//        {0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000},
//        {0.0000, 0.0170, 0.0341, 0.0511, 0.0681, 0.0852},
//        {0.0000, 0.0341, 0.0681, 0.1022, 0.1362, 0.1703},
//        {0.0000, 0.0511, 0.1022, 0.1533, 0.2043, 0.2554},
//        {0.0000, 0.0681, 0.1362, 0.2043, 0.2724, 0.3405}
//    };
//
//    int n_array[9] = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//    // 使用循环查找对应的n值
//    int i, j, n_index;
//    for (i = 0; i < 9; i++) {
//        for (j = 0; j < 6; j++) {
//            if (fabs(X_j_array[i][j] - X_j) < 0.0001) {
//                n_index = i;
//                goto found;
//            }
//        }
//    }
//
//    // 如果没有找到对应的X_j值，输出错误信息并退出程序
//    printf("输入的X_j值不在表格中，请重新输入！\n");
//    return 1;
//
//found:
//    // 获取对应的n值
//    n = n_array[n_index];
//
//    // 输出结果
//    printf("K的值为：%lf\n", K);
//    printf("对应的n值为：%d\n", n);
//
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//double calculate_K(double l, double n, double I, double E, double X_j, double T_E) {
//    double pi = M_PI;
//    double T_0 = 0.5 * pi * pi * E * I / pow(l * n, 2);
//    double Fcr = pi * pi * E * I / pow(l * n, 2);
//    double T = sqrt(T_E * Fcr);
//    double K = X_j * pow(Fcr / T_0, 3) / pow(T_0, 2);
//    return K;
//}
//
//int main() {
//    double l, n, I, E, X_j, T_E, K;
//    printf("请输入每跨的长度 l：");
//    scanf("%lf", &l);
//    printf("请输入连续压杆的跨度数 n：");
//    scanf("%lf", &n);
//    printf("请输入压杆的截面惯性矩 I：");
//    scanf("%lf", &I);
//    printf("请输入材料的弹性模量 E：");
//    scanf("%lf", &E);
//    printf("请输入中间弹性支座上连续压杆的稳定性曲线参数 X_j：");
//    scanf("%lf", &X_j);
//    printf("请输入中间弹性支座上连续压杆的稳定性曲线参数 T_E：");
//    scanf("%lf", &T_E);
//    K = calculate_K(l, n, I, E, X_j, T_E);
//    printf("计算得到的稳定性曲线参数 K 为：%lf\n", K);
//    return 0;
//}