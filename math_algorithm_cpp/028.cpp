#include <bits/stdc++.h>
using namespace std;
long long N, h[100009], dp[100009];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    // dp[i] = min(dp[i - 1] + |h[i] - h[i-1]|, dp[i - 2] + |h[i] - h[i - 3]|)
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[N - 1] << endl;
}