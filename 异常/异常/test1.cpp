#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main()
{
 
    char  b = 'a', c = 'A';
    for (int i = 0; i < 6; i++)

        if (i % 2) cout << (char)(i + b);
    else cout << (char)(i + c);
    
       
    return 0;
}