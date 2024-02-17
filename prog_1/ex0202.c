// 二つの整数値を読み込んで、その輪と積を表示するプログラム

#include <stdio.h>

int main(void) {
    int a, b;
    puts("二つの整数を入力せよ。");
    scanf("%d%d", &a, &b);
    printf("それらの和は%dで積は%dです。\n", a + b, a * b);
    return 0;
}