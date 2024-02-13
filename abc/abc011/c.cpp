// このゲームは「0から「1，2，3」の数字を足していって100回以内にNにすることはできるか？と言い換えられる
#include <iostream>
#include <vector>
using namespace std;

int N;
int ng[4];

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= 3; i++) cin >> ng[i];

    // dp する配列の用意
    vector<vector<bool>> dp(101, vector<bool> (301, false)); // dp[i][j] : i 番目の操作で j にすることは可能か。

    // 配列の初期化
    dp[0][0] = true;

    // dp
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 300; j++) {
            for (int k = 1; k <= 3; k++) {
                if (j >= k && j != ng[1] && j != ng[2] && j != ng[3]) dp[i][j] = dp[i][j] || dp[i-1][j-k];
            }
        }
    }

    // 答えを出力
    for (int i = 1; i <= 100; i++) {
        if (dp[i][N]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}