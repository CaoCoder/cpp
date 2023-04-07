#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

class Fraction {
private:
    int numerator;   // 分子
    int denominator; // 分母
public:
    Fraction(double n) {
        int sign = (n > 0) ? 1 : -1;
        n = fabs(n); // 取绝对值
        int integerPart = static_cast<int>(n); // 小数的整数部分
        double decimalPart = n - integerPart; // 小数的小数部分
        int multiple = 1;
        while (fabs(decimalPart - round(decimalPart)) > 1e-6) {
            decimalPart *= 10;
            multiple *= 10;
        }
        int numerator = round(decimalPart);
        int denominator = multiple;
        int gcdValue = gcd(numerator, denominator); // 调用gcd函数求最大公约数
        numerator /= gcdValue;
        denominator /= gcdValue;
        this->numerator = sign * (integerPart * denominator + numerator);
        this->denominator = denominator;
    }
    void print() {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f(3.141);
    f.print(); // 输出 15707963/5000000
    return 0;
}
