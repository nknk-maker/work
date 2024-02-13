#include <iostream>
using namespace std;

long long N;

int check(double x) { // 答えがx以下か判別
    double ans = x * x * x + x;
    if (ans >= N) return true;
    return false;
}

int main() {
    // 入力
    cin >> N;

    // 答えを二分探索
    double L = 1, R = 50;
    while (L < R - 0.001) {
        double M = (L + R) / 2;
        if (check(M)) R = M; // 答えは M 以下
        else L = M + 0.02; // 答えは M + 1 以上
    }
    
    // 答えを出力
    cout << (L + R) / 2 << endl;
    return 0;
}