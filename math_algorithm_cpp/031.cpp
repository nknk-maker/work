#include <bits/stdc++.h>
using namespace std;
long long N, A[500009], dp[500009];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // dp[i] = max(dp[i - 2] + A[i], dp[i - 3] + A[i])
    dp[0] = A[0]; dp[1] = A[1]; dp[2] = dp[0] + A[2];
    for (int i = 3; i < N; i++) {
        dp[i] = max(max(dp[i - 2] + A[i], dp[i - 3] + A[i]), dp[i - 1]);
    }
    cout << dp[N - 1] << endl;
}