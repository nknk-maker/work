#include <bits/stdc++.h>
using namespace std;
void dfs(long long v, vector<vector<long long>>& G, vector<long long>& dp, vector<bool>& visited) {
    visited[v] = true;
    dp[v] ++;
    for (int u : G[v]) {
        if (dp[u] == false) {
            dfs(u, G, dp, visited);
            dp[v] += dp[u];
        }
    }
}
int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    vector<vector<long long>> G(n + 1, vector<long long> (0));
    for (int i = 0; i < n; i++) {
        cin >> a.at(i) >> b.at(i);
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    vector<long long> dp(n + 1);
    vector<bool> visited(n + 1);
    dfs(1, G, dp, visited);
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += (dp[i] * (n - dp[i]));
    }
    cout << ans << endl;
}