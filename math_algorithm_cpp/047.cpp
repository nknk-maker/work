#include <bits/stdc++.h>
using namespace std;
long long N, M;
bool bfs(int x, vector<vector<long long>>& G, vector<int>& dist) {
    int pos, nex;
    queue<int> Q;
    dist[x] = 0;
    Q.push(x);
    bool flag = true;
    while (!Q.empty()) {
        pos = Q.front();
        Q.pop();
        for (int i = 0; i < (int) G[pos].size(); i++) {
            nex = G[pos][i];
            if (dist[nex] == -1) {
                Q.push(nex);
                dist[nex] = 1 - dist[pos];
            }
            if (dist[nex] != -1) {
                if (dist[pos] == dist[nex]) {
                    flag = false;
                }
            }
        }
    }
    return flag;
}
int main() {
    cin >> N >> M;
    vector<long long> A(M), B(M);
    vector<vector<long long>> G(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    // bfs, 未訪問 = -1, 白 = 0, 黒 = 1. 1 - 1 || 0 - 0で即アウト
    vector<int> dist(N + 1, -1);
    bool flag = true;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == -1) {
            if (bfs(i, G, dist) == false) {
                flag = false;
            }
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
