#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    deque<pair<int, int>> d;
    for (int i = 1; i <= N; i++) d.push_back({i, 0});

    for (int i = 1; i <= Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            char c;
            cin >> c;
            pair<int, int> pos = d[0];
            if (c == 'R') pos.first++;
            if (c == 'L') pos.first--;
            if (c == 'U') pos.second++;
            if (c == 'D') pos.second--;
            d.push_front(pos);
            d.pop_back();
        }
        else {
            int x;
            cin >> x;
            x--;
            cout << d[x].first << ' ' << d[x].second << endl;
        }
    }
    return 0;
}