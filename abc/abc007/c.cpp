#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    pair<int, int> s, g;
    cin >> s.first >> s.second >> g.first >> g.second;
    char C[H + 1][W + 1];
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) cin >> C[i][j];
    }
    queue<pair<int, int>> q;
    q.push(s);
    pair<int, int> pos;
    int dist[H + 1][W + 1];
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) dist[i][j] = -1000000000;
    }
    dist[s.first][s.second] = 0;
    // BFS
    while (!q.empty()) {
        pos = q.front();
        q.pop();
        for (pair<int, int> p : {make_pair(pos.first - 1, pos.second), make_pair(pos.first + 1, pos.second), make_pair(pos.first, pos.second - 1), make_pair(pos.first, pos.second + 1)}) {
                if (dist[p.first][p.second] == -1000000000 && C[p.first][p.second] == '.') {
                    q.push(make_pair(p.first, p.second));
                    dist[p.first][p.second] = dist[pos.first][pos.second] + 1;
                }
        }
    }
    cout << dist[g.first][g.second] << endl;
    return 0;
}