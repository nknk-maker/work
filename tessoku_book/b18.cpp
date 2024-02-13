#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, S, A[69];
bool dp[69][10009];

int main() {
    // 入力
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // DP (i = 0)
    dp[0][0] = true;
    for (int j = 1; j <= S; j++) dp[0][j] = false;

    // DP (i >= 1) 
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            if (j >= A[i]) dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i]];
            else dp[i][j] = dp[i-1][j];
        }
    }

    // 答えが存在しない場合、‐1を出力
    if (!dp[N][S]) {
        cout << -1 << endl;
        return 0;
    }

    // 復元
    vector<int> R;
    int pos = S;
    for (int i = N; i >= 1; i--) {
        if (dp[i-1][pos]) continue;
        else if (dp[i-1][pos-A[i]]) R.push_back(i);
        pos -= A[i];
    }
    reverse(R.begin(), R.end());

    // 出力
    cout << R.size() << endl;
    for (int i = 0; i < R.size(); i++) {
        if (i > 0) cout << ' ';
        cout << R[i];
    }
    cout << endl;
    return 0;
}