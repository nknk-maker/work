#include <bits/stdc++.h>
#define graph vector<vector<long long>> 
using namespace std;
long long N, M;
int main() {
    cin >> N >> M;
    vector<long long> A(M), B(M);
    graph G(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    // bfs
    vector<long long> dist(N + 1, -1);
    queue<long long> q;
    q.push(1);
    dist[1] = 0;
    long long pos;
    while (!q.empty()) {
        pos = q.front();
        q.pop();
        for (int i = 0; i < G[pos].size(); i++) {
            int nex = G[pos][i];
            if (dist[nex] == -1) {
                q.push(nex);
                dist[nex] = dist[pos] + 1;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << dist[i] << endl;
    }
    return 0;
}