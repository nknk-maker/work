#include <iostream>
#include <complex>
using namespace std;

int N, h[100009], dp[100009];

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> h[i];

    // DP
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);
    for (int i = 3; i <= N; i++) dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));

    // 出力
    cout << dp[N] << endl;
    return 0;
}