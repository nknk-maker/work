#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j =i + 1; j < n; j++) {
            cin >> d[i][j];
        }
    }

    vector<long long> dp(1 << n, 0LL);

    for (int b = 0; b < (1 << n) - 1; b++) {
        int l = -1;
        for (int i = 0; i < n; i++) {
            if (!(b >> i & 1)) {
                l = i;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!(b >> i & 1)) {
                int nb = b | (1 << l) | (1 << i);
                dp[nb] = max(dp[nb], dp[b] + d[l][i]);
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}