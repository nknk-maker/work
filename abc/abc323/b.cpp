#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    char c;
    vector<pair<int, int>> s(N); // プレイヤー番号、勝ち点
    for (int i = 0; i < N; i++) {
        s[i] = make_pair(0, -i);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            if (c == 'o') s[i].first ++;
            if (c == 'x') s[i].first --;
        }
    }
    sort(s.begin(), s.end(), greater<pair<int, int>>());
    for (int i = 0; i < N; i++) {
        cout << -s[i].second + 1 << ' ';
    }
    cout << endl;
}