#include <bits/stdc++.h>
#define graph vector<vector<long long>>
using namespace std;
void dfs(graph& G, vector<bool>& visited, int pos) {
    visited[pos] = true;
    for (int i : G[pos]) {
        if (!visited[i]) {
            dfs(G, visited, i);
        }
    }
}
int main() {
    long long N, M;
    cin >> N >> M;
    graph G(N + 1);
    vector<bool> visited(N + 1, false);
    vector<int> a(M), b(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    dfs(G, visited, 1);
    bool flag = true;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            flag = false;
            break;
        }
    }
    if (flag) cout << "The graph is connected." << endl;
    else cout << "The graph is not connected." << endl;
    return 0;
}

