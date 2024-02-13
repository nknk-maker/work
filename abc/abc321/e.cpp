#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    N = 1000000000000000000;
    vector<vector<long long>> G(N + 1);
    for (int i = 1; 2 * i + 1 <= N; i++) {
        if (2 * i > N) continue;
        G[i].push_back(2 * i);
        G[2 * i].push_back(i);
        if (2 * i + 1 > N) continue;
        G[i].push_back(2 * i + 1);
        G[2 * i + 1].push_back(i);
    }
    long long T;
    cin >> T;
    // bfsでクエリに答える
    long long X, K; 
    for (int i = 0; i < T; i++) {
        cin >> N >> X >> K;
        // 頂点Xとの距離がK未満、頂点番号がN以下で来れる頂点の数。BFS
        vector<long long> dist(10000, -1);
        queue<int> Q;
        dist[X] = 0;
        Q.push(X);
        while (!Q.empty()) {
            int pos = Q.front();
            Q.pop();
            for (int j = 0; j < G[pos].size(); j++) {
                int nex = G[pos][j];
                if (dist[nex] == -1) {
                    if (nex <= N) {
                        Q.push(nex);
                        dist[nex] = dist[pos] + 1;
                    }
                }
            }
        }
        long long ans = 0;
        for (int j = 0; j <= N; j++) {
            if (dist[j] == K) {
                ans++;
            }
        }
        cout << ans << endl;
    }

}