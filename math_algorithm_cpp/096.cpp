#include <bits/stdc++.h>
using namespace std;
// dpテーブルの作成
// オーブンA,Bとする
// dp[i][j] はオーブンAに品目までで、j分使うような方法があるかどうか。
// そうすると、オーブンAの総稼働時間 <= オーブンBの総稼働時間としても一般性を失わない。
// オーブンAの総稼働時間の上界は、100 * 1000 / 2 = 50000
long long N;
int main() {
    cin >> N;
    vector<long long> T(N + 1);
    vector<vector<bool>> dp(N + 1, vector<bool> (50001, false));
    for (int i = 1; i <= N; i++) cin >> T[i];
    // dp[i][j] = dp[i - 1][j] , dp[i - 1][j - T[i]](j >= T[i])
    // 初期化
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 50000; j++) {
            dp[i][j] = dp[i][j] || dp[i - 1][j];
            if (j >= T[i]) dp[i][j] = dp[i][j] || dp[i - 1][j - T[i]];
        }
    }
    // output : sum(T) - dp[N][j] == trueとなるjの最大値
    long long sum_T = 0;
    for (int i = 1; i <= N; i++) sum_T += T[i];
    for (int j = sum_T / 2; j >= 0; j--) {
        if (dp[N][j] == true) {
            cout << sum_T - j << endl;
            return 0;
        }
    }
}