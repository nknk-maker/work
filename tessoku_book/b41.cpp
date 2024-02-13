#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    pair<int, int> p;
    cin >> p.first >> p.second;
    vector<pair<int, int>> ans;
    while (p.first > 1 || p.second > 1) {
        ans.push_back(p);
        if (p.first >= p.second) p.first -= p.second;
        else if (p.second > p.first) p.second -= p.first;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto P : ans) {
        cout << P.first << ' ' << P.second << endl;
    }
}