#include <iostream>
#include <algorithm>
using namespace std;

int N, W, w[109], v[109];
long long dp[109][100009]; // dp[i][j] ... i番目までの品物からいくつかを選んで、価値がjになるもののうち、重さの最小値

int main() {
    // 入力・配列の初期化
    cin >> N >> W;
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 100000; j++) dp[i][j] = 1000000000000000LL;
    }

    // DP
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 100000; j++) {
            if (j < v[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
        }
    }

    // 答えの出力
    for (int j = 100000; j >= 0; j--) {
        if (dp[N][j] <= W) {
            cout << j << endl;
            return 0;
        }
    }
}