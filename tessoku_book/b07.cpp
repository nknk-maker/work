#include <iostream>
using namespace std;

int T, A[500009], B[500009];
int N, R[500009], L[500009];

int main() {
    // 入力
    cin >> T >> N;
    for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

    // 前時間の比に加算（+0.5で考えているので、R[i]に-1)
    for (int i = 1; i <= N; i++) {
        A[L[i]]++;
        A[R[i]]--;
    }

    // 累積和をとる（0時だけ別）
    B[0] = A[0];
    for (int i = 1; i <= T - 1; i++) B[i] = B[i - 1] + A[i];

    // 答えを出力
    for (int i = 0; i <= T - 1; i++) cout << B[i] << endl;
    return 0;
}