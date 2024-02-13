#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, M;
    cin >> N >> M;
    vector<vector<long long>> G(N + 1);
    vector<long long> A(M);
    vector<long long> B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    // 人iの年齢は絶対に人1から人iまでの最短距離長を超えない。
    // 最短経路長をBFSで求める
    vector<long long> dist(N + 1, -1);
    dist[1] = 0;
    queue<long long> Q;
    long long pos;
    Q.push(1);
    while (!Q.empty()) {
        pos = Q.front();
        Q.pop();
        for (int i = 0; i < G[pos].size(); i++) {
            long long nex = G[pos][i];
            if (dist[nex] == -1) {
                dist[nex] = min(dist[pos] + 1, 120LL);
                Q.push(nex);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (dist[i] == -1) cout << 120 << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}