#include <bits/stdc++.h>
using namespace std;
long long N, S, A[60];
bool dp[69][10009];
int main() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    // dp[i][j] -> i個目まで選んで、合計がjにできるか。
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= A[i]) {
                dp[i][j] = (dp[i][j] || dp[i - 1][j - A[i]]);
            }
        }
    }
    if (dp[N][S]) cout << "Yes" << endl;
    else cout << "No" << endl;
}