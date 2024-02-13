#include <bits/stdc++.h>
using namespace std;
long long N, dp[50];
int main() {
    cin >> N;
    dp[0] = 1;
    for (int i = 0; i <= N - 2; i++) {
        dp[i + 2] += dp[i];
        dp[i + 1] += dp[i];
    }
    dp[N] += dp[N - 1];
    cout << dp[N] << endl;
}