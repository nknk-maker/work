// 適正体重を表示

#include <stdio.h>

int main(void) {
    int height;
    printf("身長を入力せよ。：");   scanf("%d", &height);
    printf("適正体重は%.1fです。\n", (height - 100) * 0.9);
    return 0;
}