#include <bits/stdc++.h>
using namespace std;

int K, dist[100009];
bool used[100009];
vector<pair<int, int>> G[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

// ダイクストラ法
void djikstra() {
    for (int i = 0; i < K; i++) {
        dist[i] = (1 << 30);
    }
    for (int i = 0; i < K; i++) {
        used[i] = false;
    }
    Q.push(make_pair(0,0));

    while (!Q.empty()) {
        int pos = Q.top().second;
        Q.pop();
        if (used[pos] == true) continue;
        used[pos] = true;
        for (pair<int, int> i : G[pos]) {
            int to = i.first;
            int cost = dist[pos] + i.second;
            if (pos == 0) cost = i.second;
            if (dist[to] > cost) {
                dist[to] = cost;
                Q.push(make_pair(dist[to], to));
            }
        }
    }
}

int main() {
    cin >> K;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 && j == 0) continue;
            G[i].push_back(make_pair((i * 10 + j) % K, j));
        }
    }

    djikstra();
    cout << dist[0] << endl;
    return 0;
}