#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[1009][1009];
string S;

int main() {
    // input
    cin >> N >> S;
    S = ' ' + S;

    // DP(len is the value of r-l)
    for (int i = 1; i <= N; i++) dp[i][i] = 1;
    for (int len = 1; len <= N-1; len++) {
        for (int l = 1; l <= N-len; l++) {
            int r = l + len;
            if (S[l] == S[r]) dp[l][r] = max({dp[l+1][r], dp[l][r-1], dp[l+1][r-1] + 2});
            else dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
        }
    }
    cout << dp[1][N] << endl;
    return 0;
}