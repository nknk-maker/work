// 選挙区iで高橋君が当選するために必要な議席の数をWiとすると、xi > Yiの時、Wi = 0, xi <= yiの時、wi = yi - xi
// すると、iこめの選挙区についてWi人の鞍替えが必要な時、高橋君が議席をsum(z) / 2 以上獲得するのに必要な鞍替えの最小人数を求める問題に帰着できる
// これはナップザック問題に帰着した。

#include <bits/stdc++.h>
using namespace std;
int main() {
    long long INF = 1LL << 50;
    int N;
    cin >> N;
    vector<long long> W(N + 1), Z(N + 1);
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y >> Z[i];
        W[i] = max(0, (y - x + 1) / 2);
    }
    long long  max_num = 0;
    for (int i = 1; i <= N; i++) {
        max_num += Z[i];
    }
    vector<vector<long long>> dp(N + 1, vector<long long> (max_num + 1, INF)); 
    // dp[i][j] : i個目までの選挙区について、高橋君が議席をj個獲得するのに必要な鞍替えの人数の総和
    // dpテーブルの初期化：dp[0][0]は全て0,それ以外はINF
    dp[0][0] = 0;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j <= max_num; j++) {
            // 鞍替えなしバージョン
            dp[i][j] =  dp[i - 1][j];
            // 鞍替えありバージョン
            if (j >= Z[i]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - Z[i]] + W[i]);
            }
        }
    }
    long long ans = INF;
    for (int j = (max_num + 1) / 2; j <= max_num; j++) {
        ans = min(dp[N][j], ans);
    }
    cout << ans << endl;
}