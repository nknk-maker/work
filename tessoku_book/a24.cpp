#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009], dp[100009];
int LEN=0, L[100009]; // LEN は L の長さ

int main() {
    // Input
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // DP
    for (int i = 1; i <= N; i++) {
        int pos = lower_bound(L + 1, L + LEN + 1, A[i]) - L;
        dp[i] = pos;

        // 配列 L を更新
        L[dp[i]] = A[i];
        if (dp[i] > LEN) LEN += 1;
    }

    // 答えを出力
    cout << LEN << endl;
    return 0;
}