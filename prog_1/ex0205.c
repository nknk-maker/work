// 二つの整数値を読み込んで、前者の値が後者の何%科を実数で表示

#include <stdio.h>

int main(void) {
    int a, b;

    puts("二つの整数を入力せよ。");
    printf("整数a : "); scanf("%d", &a);
    printf("整数b : "); scanf("%d", &b);

    printf("aの値はbの%f％です\n", (double) a * 100 / b);

    return 0;
}