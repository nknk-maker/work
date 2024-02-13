#include <bits/stdc++.h>
using namespace std;

int H, W, N;

int main() {
    cin >> H >> W >> N;
    vector<vector<bool>> MAP(H, vector<bool> (W, false));
    vector<pair<int, int>> muki = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    pair<int, int> pos = {0, 0};
    int m = 0;
    for (int i = 0; i < N; i++) {
        if (!MAP[pos.first][pos.second]) {
            MAP[pos.first][pos.second] = true;
            m++;
            m %= 4;
            pos = {(pos.first + muki[m].first + H) % H, (pos.second + muki[m].second + W) % W};
        }
        else {
            MAP[pos.first][pos.second] = false;
            m--;
            if (m < 0) m += 4;
            pos = {(pos.first + muki[m].first + H) % H, (pos.second + muki[m].second + W) % W};
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (MAP[i][j]) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
    return 0;
}