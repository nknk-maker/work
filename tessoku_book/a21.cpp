#include <iostream>
#include <algorithm>
using namespace std;

int N, P[2009], A[2009];
int dp[2009][2009];

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> P[i] >> A[i];

    // DP (LEN is the value of r-l)
    dp[1][N] = 0;
    for (int LEN = N-2; LEN >= 0; LEN--) {
        for (int l = 1; l <= N - LEN; l++) {
            int r = l + LEN;

            // find the value of score 1(the score for removing the l-1st block)
            int score1 = 0;
            if (l <= P[l-1] && P[l-1] <= r) score1 = A[l-1];

            // fint the value of score 2(the score for remobing the r+1st block)
            int score2 = 0;
            if (l <= P[r+1] && P[r+1] <= r) score2 = A[r+1];

            // find dp[l][r]
            if(l == 1) {
                dp[l][r] = dp[l][r+1] + score2;
            }
            else if (r == N) {
                dp[l][r] = dp[l-1][r] + score1;
            }
            else {
                dp[l][r] = max(dp[l-1][r] + score1, dp[l][r+1] + score2);
            }
        }
    }
    // output
    int ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, dp[i][i]);
    cout << ans << endl;
    return 0;
}