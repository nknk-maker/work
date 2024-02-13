#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, x[19], y[19];
double dp[1 << 15][19];

int main() {
    // 入力
    cin >> N;
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

    // 配列の初期化
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = 1e9;
        }
    }

    //DP
    dp[0][0] = 0;
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            // もし都市jがiの中に含まれているなら、すでに更新されているはず
            if (dp[i][j] >= 1e9) continue;
            for (int k = 0; k < N; k++) {
                if (i & (1 << k)) continue;
                int v = i | (1 << k);
                double dist = sqrt(1.0 * (x[j]-x[k])*(x[j]-x[k]) + (y[j]-y[k])*(y[j]-y[k]));
                dp[v][k] = min(dp[v][k], dp[i][j] + dist);
            }
        }
    }

    // 出力（０からスタートしたので０で終わる）
    cout << dp[(1<<N)-1][0] << endl;
    return 0;
}