#include <iostream>
using namespace std;

int cal(int n) {
    int  minus = 0;
    int m = n;
    while (m > 0) {
        minus += m % 10;
        m /= 10;
    }
    return n - minus;
}

int  main() {
    int N, K;
    cin >> N >> K;
    int dp[49][300009]; // dp[i][j] ... 数字 j を 1, 2, 4, 8, ... 回操作を行った後の値


    // dp[i][j] の前計算
    for (int i = 0; i <= N; i++) dp[0][i] = cal(i);

    // ダブリング
    for (int i = 1; i <= 39; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }

    // 答えを出力
    for (int i = 1; i <= N; i++) {
        int CurrentNum = i;
        for (int j = 39; j >= 0; j--) {
            if (K & (1LL << j)) CurrentNum = dp[j][CurrentNum];
        }
        cout << CurrentNum << endl;
    }
    return 0;
}