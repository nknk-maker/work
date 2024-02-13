#include <bits/stdc++.h>
using namespace std;
bool solve(pair<int, int> e1, pair<int, int> e2, pair<int, int> e3, vector<vector<int>> p1, vector<vector<int>> p2, vector<vector<int>> p3) {
    vector<vector<vector<int>>> dot(4, vector<vector<int>> (10, vector<int> (10, 0)));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (p1[i][j] == 1) {
                dot[0][e1.first + i][e1.second + j] ++;
                dot[1][e1.first + j][e1.second + 3 - i] ++;
                dot[2][e1.first + 3 - j][e1.second + i] ++;
                dot[3][e1.first + 3 - i][e1.second + 3 - j] ++;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (p2[i][j] == 1) {
                dot[0][e2.first + i][e2.second + j] ++;
                dot[1][e2.first + j][e2.second + 3 - i] ++;
                dot[2][e2.first + 3 - j][e2.second + i] ++;
                dot[3][e2.first + 3 - i][e2.second + 3 - j] ++;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (p3[i][j] == 1) {
                dot[0][e3.first + i][e3.second + j] ++;
                dot[1][e3.first + j][e3.second + 3 - i] ++;
                dot[2][e3.first + 3 - j][e3.second + i] ++;
                dot[3][e3.first + 3 - i][e3.second + 3 - j] ++;
            }
        }
    }
    vector<bool> flag(4, true);
    for (int k = 0; k < 4; k++) {
        for (int i = 3; i <= 6; i++) {
            for (int j = 3; j <= 6; j++) {
                if (!dot[k][i][j] != 1) flag[k] = false;
            }
        }
    }
    return (flag[0] || flag[1] || flag[2] || flag[3]);
}
int main() {
    vector<vector<int>> p1(4, vector<int> (4));
    vector<vector<int>> p2(4, vector<int> (4));
    vector<vector<int>> p3(4, vector<int> (4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> c;
            if (c == '#') p1[i][j] = 1;
            else p1[i][j] = 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> c;
            if (c == '#') p2[i][j] = 1;
            else p2[i][j] = 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> c;
            if (c == '#') p3[i][j] = 1;
            else p3[i][j] = 0;
        }
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            pair<int, int> edge1 = make_pair(i, j);
            for (int i2 = 0; i2 < 10; i2++) {
                for (int j2 = 0; j2 < 10; j2++) {
                    pair<int, int> edge2 = make_pair(i2, j2);
                    for (int i3 = 0; i3 < 10; i3++) {
                        for (int j3 = 0; j3 < 10; j3++) {
                            pair<int, int> edge3 = make_pair(i3, j3);
                            solve(edge1, edge2, edge3, p1, p2, p3);
                        }
                    }
                }
            }
        }
    }
}