#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // INPUT
    int N, x[100009], y[100009];
    cin >> N;
    vector<pair<int, int>> xy(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i]; // とりあえずx[i], y[i] で読み込む
    int dp[100009];

    // y は降順でソートをすることで、途中でLISが途切れるので、結果的に重複を消せる
    // ソートして重複を消す
    for (int i = 0; i < N; i++) xy[i] = {x[i], -y[i]};
    sort(xy.begin(), xy.end());

    // LISをする配列Aを作成
    vector<int> A;
    for (int i = 0; i < N; i++) A.push_back(-xy[i].second);
    
    // LIS
    // DP
    int len = 0, L[100009]; // L[x] はdp[k] = x を満たすkで最小の値
    for (int i = 0; i < N; i++) L[i] = 0;
    for (int i = 0; i < N; i++) {
        int pos = lower_bound(L + 1, L + len + 1, A[i]) - L;
        dp[i] = pos;

        // 配列 L を更新
        L[dp[i]] = A[i];
        if (dp[i] > len) len++;
    }

    // 答えを出力
    cout << len << endl;
    return 0;
}