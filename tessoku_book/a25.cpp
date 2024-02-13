#include <iostream>
using namespace std;

int H, W;
char c[39][39];
long long dp[39][39];

int main() {
    // 入力
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> c[i][j];
        }
    }

    // 配列の初期化
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) dp[i][j] = 0;
    }

    // DP
    dp[1][1] = 1;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (c[i][j] == '#') continue;
            if (c[i][j+1] == '.') dp[i][j+1] += dp[i][j];
            if (c[i+1][j] == '.') dp[i+1][j] += dp[i][j];
        }
    }

    
    cout << dp[H][W] << endl;
    return 0;
}