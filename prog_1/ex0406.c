#include <stdio.h>
int main() {
    int a, x = 0;
    
    printf("正の整数値を入力せよ。");
    scanf("%d", &a);
    if (a < 0) {
        printf("入力された値は負の値です。\n");
        return 1;
    } else if (a == 1) {
        printf("1以下の偶数はありません。\n");
        return 1;
    }
    
    while (x + 2 < a) {
        x += 2;
        printf("%d ", x);
    }

    printf("\n");
    return 0;
}