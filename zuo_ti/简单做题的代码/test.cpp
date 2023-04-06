#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Fraction {

private:
    int numerator;          // 分子
    int denominator;        // 分母

public:
    int _gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        else {
            return _gcd(b, a % b);
        }
    }
    // 构造函数
    Fraction() {
        numerator = 0;
        denominator = 1;
    }
    //小数转化为分数
    Fraction(double n) 
    {
        int sign = (n > 0) ? 1 : -1;
        n = fabs(n); // 取绝对值
        int integerPart = static_cast<int>(n); // 小数的整数部分
        double decimalPart = n - integerPart; // 小数的小数部分
        int multiple = 1;
        while (fabs(decimalPart - round(decimalPart)) > 2e8) {
            decimalPart *= 10;
            multiple *= 10;
        }
        int numerator = round(decimalPart);
        int denominator = multiple;
        int gcd = _gcd(numerator, denominator); // 求最大公约数
        numerator /= gcd;
        denominator /= gcd;
        this->numerator = sign * (integerPart * denominator + numerator);
        this->denominator = denominator;
    }
    // 有参数的构造函数
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
        reduce();           // 将该分数约分为最简分数形式
    }

    // 求取两数的最大公因数（欧几里得算法）
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // 约分函数，将该分数约分为最简分数形式
    void reduce() {
        int gcd_val = gcd(numerator, denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;

        // 如果分母为负数，则将分子和分母都取反，保证分数为负数形式
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // 返回分数的double类型表示
    double to_double() const {
        return numerator / (double)denominator;
    }

    // 输出分数
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    // 输入分数
    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        f.reduce();
        return is;
    }

    // 分数加法重载
    friend Fraction operator+(const Fraction& f1, const Fraction& f2) {
        int n = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
        int d = f1.denominator * f2.denominator;
        return Fraction(n, d);
    }

    // 分数减法重载
    friend Fraction operator-(const Fraction& f1, const Fraction& f2) {
        int n = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
        int d = f1.denominator * f2.denominator;
        return Fraction(n, d);
    }
    // 分数乘法重载
    friend Fraction operator*(const Fraction& f1, const Fraction& f2) {
        int n = f1.numerator * f2.numerator;
        int d = f1.denominator * f2.denominator;
        return Fraction(n, d);
    }

    // 分数除法重载
    friend Fraction operator/(const Fraction& f1, const Fraction& f2) {
        int n1 = f1.numerator * f2.denominator;
        int d1 = f1.denominator * f2.numerator;
        return Fraction(n1, d1);
    }

    // 分数加上整数重载
    friend Fraction operator+(const Fraction& f1, int n) {
        Fraction f2(n, 1);
        return f1 + f2;
    }

    // 分数减去整数重载
    friend Fraction operator-(const Fraction& f1, int n) {
        Fraction f2(n, 1);
        return f1 - f2;
    }

    // 分数乘以整数重载
    friend Fraction operator*(const Fraction& f1, int n) {
        Fraction f2(n, 1);
        return f1 * f2;
    }

    // 分数除以整数重载
    friend Fraction operator/(const Fraction& f1, int n) {
        Fraction f2(1, n);
        return f1 / f2;
    }

    // 整数加上分数重载
    friend Fraction operator+(int n, const Fraction& f1) {
        Fraction f2(n, 1);
        return f2 + f1;
    }

    // 整数减去分数重载
    friend Fraction operator-(int n, const Fraction& f1) {
        Fraction f2(n, 1);
        return f2 - f1;
    }

    // 整数乘以分数重载
    friend Fraction operator*(int n, const Fraction& f1) {
        Fraction f2(n, 1);
        return f2 * f1;
    }

    // 整数除以分数重载
    friend Fraction operator/(int n, const Fraction& f1) {
        Fraction f2(n, 1);
        return f2 / f1;
    }
};
// 主函数
int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(0.6);

    // 输出分数
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f3 = " << f3 << endl;

    // 输出分数运算结果
    cout << "f1 + f2 = " << f1 + f2 << endl;
    cout << "f1 - f2 = " << f1 - f2 << endl;
    cout << "f1 * f2 = " << f1 * f2 << endl;
    cout << "f1 / f2 = " << f1 / f2 << endl;

    // 输出分数与整数运算结果
    cout << "f1 + 1 = " << f1 + 1 << endl;
    cout << "f1 - 1 = " << f1 - 1 << endl;
    cout << "f1 * 2 = " << f1 * 2 << endl;
    cout << "f1 / 2 = " << f1 / 2 << endl;

    // 输出整数与分数运算结果
    cout << "1 + f2 = " << 1 + f2 << endl;
    cout << "1 - f2 = " << 1 - f2 << endl;
    cout << "2 * f1 = " << 2 * f1 << endl;
    cout << "2 / f1 = " << 2 / f1 << endl;

    // 将分数的值赋给f3
    f3 = f1 + f2 * 2;
    cout << "f3 = " << f3 << endl;

    // 将复合运算结果赋给f3
    f3 = 2 * f1 + 3 / f2;
    cout << "f3 = " << f3 << endl;

    // 输出分数的double表示
    double d = f1.to_double();
    cout << "double value of f1 = " << d << endl;

    return 0;
}
