
#include <stdio.h>
#include <windows.h> 
#include <math.h>
#include <mmsystem.h>
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
//定义全局变量

int rosesize = 500;
int h = -250;

//定义结构体
struct DOT
{
    double x;
    double y;
    double z;
    double r;
    double g;
};

bool calc(double a, double b, double c, DOT& d)
{
    double j, n, o, w, z;

    if (c > 60)
    {
        d.x = sin(a * 20) * (13 + 5 / (0.2 + pow(b * 4, 4))) - sin(b) * 70;
        d.y = b * rosesize + 50;
        d.z = 900 + cos(a * 7) * (13 + 30 / (0.2 + pow(b * 4, 4))) + b * 60;
        d.r = a * 3 - b / 30;
        d.g = a;
        return true;
    }
    double A = a * 2 - 1;
    double B = b * 2 - 1;
    if (A * A + B * B < 1)
    {
        if (c > 37)
        {
            j = (int(c) & 1);
            n = j ? 6 : 4;
            o = 0.5 / (a + 0.01) + cos(b * 125) * 3 - a * 300;
            w = b * h;
            d.x = o * cos(n) + w * sin(n) + j * 600 - 390;
            d.y = o * sin(n) - w * cos(n) + 550 - j * 50;
            d.z = 1700 + cos(B + A) * 99 - j * 100;
            d.r = 0.1 - a * 0.1 + pow(1 - B * B, -h * 6) * 0.15 - a * b * 0.4 + cos(a + b) / 5 +
                pow(cos((o * (a + 1) + (B > 0 ? w : -w)) / 25), 30) * 0.1 * (1 - B * B);
            d.g = o / 500 + 0.7 - o * w * 0.000004;
            return true;


        }


        o = A * (1.5 - b) * (130 - c * 2);
        w = 90 - cos(A) * 120 - cos(b) * (-h - c * 4.9) + cos(pow(1 - b, 7)) * 50 + c * 2;
        z = o * sin(c) + w * cos(c) + 700;
        d.x = o * cos(c) - w * sin(c);
        d.y = B * 99 - cos(pow(b, 7)) * 50 - c / 3 - z / 1.35 + 450;
        d.z = z;
        d.r = (1 - b / 1) * 0.8 + a * 0.3;
        d.g = pow((1 - b), 20) / 4 + 0.05;
        return true;
    }
    return false;
}

int main()
{

    short* zBuffer;

    int x, y, z, zBufferIndex;

    DOT dot;

    zBuffer = new short[rosesize * rosesize];

    memset(zBuffer, 0, sizeof(short) * rosesize * rosesize);

    //显示图像
    HWND hwnd = GetForegroundWindow();//窗口句柄
    HDC hdc = GetDC(hwnd);//绘图句柄
    BYTE b, g, r, rgb;

    for (int j = 0; j < 1000 && !_kbhit(); j++)// && !_kbhit()
    {


        for (int i = 0; i < 2222; i++)
            if (calc(double(rand()) / RAND_MAX, double(rand()) / RAND_MAX, rand() % 46 / 0.74, dot))
            {


                z = int(dot.z + 0.5);

                x = int(dot.x * rosesize / z - h + 0.5);

                y = int(dot.y * rosesize / z - h + 0.5);

                if (y > rosesize) continue;

                zBufferIndex = y * rosesize + x;

                if (!zBuffer[zBufferIndex] || zBuffer[zBufferIndex] > z)

                {

                    zBuffer[zBufferIndex] = z;
                    //画点
                    int r = ~int((dot.r * h));
                    if (r < 0)r = 0;
                    if (r > 255)r = 255;

                    int g = ~int((dot.g * h));
                    if (g < 0)g = 0;
                    if (g > 255)g = 255;

                    int b = ~int((dot.r * dot.r * -80));
                    if (b < 0)b = 0;
                    if (b > 255)b = 255;

                    SetPixel(hdc, x - 60, y + 100, RGB(r, g, b));
                }
            }
        Sleep(5);
    }

    delete[]zBuffer;
    return 0;
}
