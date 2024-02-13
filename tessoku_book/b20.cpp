#include <bits/stdc++.h>
using namespace std;

int N, M, dp[2009][2009];
string S, T;

int main() {
    // 入力
    cin >> S; N = S.size();
    cin >> T; M = T.size();
    S = ' ' + S;
    T = ' ' + T;

    // DP
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) dp[i][0] = i;
    for (int j = 1; j <= M; j++) dp[0][j] = j;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (S.at(i) == T.at(j)) dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1]});
            else dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}