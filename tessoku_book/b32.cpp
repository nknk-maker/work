#include <iostream>
using namespace std;

int main() {
    int N, K, a[109];
    bool dp[100009];

    // 入力
    cin >> N >> K;
    for (int i = 1; i <= K; i++) cin >> a[i];

    // 初期化→dp
    dp[0] = false;
    for (int i = 1; i <= N; i++) {
        dp[i] = false;
        for (int j = 1; j <= K; j++) {
            if (i >= a[j] && !dp[i-a[j]]) dp[i] = true;
        }
    }

    // 出力
    if (dp[N]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}