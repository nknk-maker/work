#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    vector<long long> B(N + 1), A(N + 1);
    for (int i = 1; i < N; i++) {
        cin >> B[i];
    }
    // A[i]は絶対にB[i], B[i - 1]を超えた値にならない。-> A[i] <= min(B[i], B[i - 1]);
    long long INF = (1LL << 60);
    B[0] = INF;
    B[N] = INF;
    for (int i = 1; i <= N; i++) {
        A[i] = min(B[i], B[i - 1]);
    }
    // 総和を計算
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}