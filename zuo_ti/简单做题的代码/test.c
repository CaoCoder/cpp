#define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
int main() {
    long long int x, y;
    long long int sum = 0;
    scanf("%lld", &x);//ÓÐ¼¸×é
    long long int* a = (long long int* )malloc(sizeof(int) * 100001 * 3);

    for (int i = 0; i < x * 3; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < 3 * x; i++)
    {
        for (int j = i + 1; j < 3 * x; j++) {
            if (a[j] > a[i]) {
                y = a[i];
                a[i] = a[j];
                a[j] = y;
            }
        }
    }
    for (int i = 1; 2 * i <= 2 * x; i++)
    {
        sum = a[2 * i - 1] + sum;
    }
    printf("%lld", sum);

    free(a);
    a = NULL;
    return 0;
}