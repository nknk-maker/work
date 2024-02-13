#include <bits/stdc++.h>
using namespace std;

int H, W;
int sx, sy, start;
int gx, gy, goal;
char c[59][59];

int dist[2509];
vector<int> G[2509];

int main() {
    cin >> H >> W;
    cin >> sx >> sy;
    start = sx * W + sy;
    cin >> gx >> gy;
    goal = gx * W + gy;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> c[i][j];
        }
    }
    //横方向の辺[(i,j) - (i, j + 1)]をグラフに追加
    for (int i = 1; i <= H; i++) {
        for (int j =1; j <= W - 1; j++) {
            int idx1 = i * W + j; // (i, j)
            int idx2 = i * W + (j + 1); //(i, j + 1)
            if (c[i][j] == '.' && c[i][j + 1] == '.') {
                G[idx1].push_back(idx2);
                G[idx2].push_back(idx1);
            }
        }
    }

    // 縦方向の辺 [(i, j) - (i + 1, j)] をグラフに追加
    for (int i = 1; i <= H - 1; i++) {
        for (int j = 1; j <= W; j++) {
            int idx1 = i * W + j; // 頂点(i, j) の頂点番号
            int idx2 = (i + 1) * W + j; // 頂点(i + 1, j)の頂点番号
            if (c[i][j] == '.' && c[i + 1][j] == '.') {
                G[idx1].push_back(idx2);
                G[idx2].push_back(idx1);
            }
        }
    }

    // 以降は、bfs
    for (int i = 1; i <= H * W; i++) {
        dist[i] = -1;
    }
    queue<int> Q;
    Q.push(start);
    dist[start] = 0;

    // 幅有線探索
    while (!Q.empty()) {
        int pos = Q.front(); // Qの先頭を調べる
        Q.pop();
        for (int i = 0; i < (int)G[pos].size(); i++) {
            int nex = G[pos][i];
            if (dist[nex] == -1) {
                dist[nex] = dist[pos] + 1;
                Q.push(nex);
            }
        }
    }

    cout << dist[goal] << endl;
    return 0;
}
