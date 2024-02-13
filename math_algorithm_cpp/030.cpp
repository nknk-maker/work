#include <bits/stdc++.h>
using namespace std;
long long N, W;
long long INF = 1LL << 30;
int main() {
    cin >> N >> W;
    vector<long long> w(N + 1), v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }
    vector<vector<long long>> dp(N + 1, vector<long long> (W + 1, -INF));
    // dp[i][j] はi個目までの品物を入れてに重さjにした時の価値の最大値(-INFで初期化)
    dp[0][0] = 0; // 何も入れていないとき、重さは0、価値も0
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            long long element2 = -INF;
            if (j >= w[i]) {element2 = dp[i - 1][j - w[i]] + v[i];}
            dp[i][j] = max(dp[i - 1][j], element2);
        }
    }
    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;

}