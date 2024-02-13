#include <iostream>
using namespace std;

long long N, K;
long long A[100009];

// 答えが x 以下かを判定
bool check(long long x) {
    long long sum = 0;
    for (int i = 1; i <= N; i++) sum += x / A[i]; // 「x ÷ A[i]」の床関数
    if (sum >= K) return true;
    return false;
}

int main() {
    // 入力
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // 二分探索
    // L は探索範囲の左端、R は探索範囲の右端
    long long L = 1, R = 1000000000;
    while (L < R) {
        long long M = (L + R) / 2;
        if (check(M)) R = M; // 答えは M 以下
        else L = M + 1; // 答えは M+1 以上
    }

    // 出力 (この時L = R)
    cout << L << endl;
    return 0;
}
