// 浮動小数点型の変数の値を表示

#define FL 123456789012345678901234567890.0
#include <stdio.h>

int main(void) {
    float a = FL;
    double b = FL;
    long double c = FL;

    printf("a = %f\n", a);
    printf("b = %f\n", b);
    printf("c = %lf\n", c);

    return 0;
}