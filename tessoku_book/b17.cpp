#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, h[100009], dp[100009];
vector<int> ans;

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> h[i];

    // DP
    dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);
    for (int i = 3; i <= N; i++) dp[i] = min(dp[i-1] + abs(h[i-1] - h[i]), dp[i-2] + abs(h[i-2] - h[i]));

    // 復元
    int pos = N;
    while (pos > 0) {
        ans.push_back(pos);
        if (dp[pos] == dp[pos - 1] + abs(h[pos - 1] - h[pos])) pos--;
        else pos -= 2;
    }

    // 答えを出力
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}