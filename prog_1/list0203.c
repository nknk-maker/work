// 二つの整数値を読みこんで商と剰余を表示

#include <stdio.h>

int main(void) {
    int a, b;

    puts("二つの整数を入力せよ。");
    scanf("%d%d", &a, &b);
    printf("aをbで割ると%dあまり%dです。\n", a / b, a % b);

    return 0;
}