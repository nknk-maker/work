#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double dist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(1.0 * (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int main() {
    int T, V;
    pair<int, int> ta, tb;
    cin >> ta.first >> ta.second >> tb.first >> tb.second;
    cin >> T >> V;
    int n;
    cin >> n;
    pair<int, int> p;
    for (int i = 1; i <= n; i++) {
        cin >> p.first >> p.second;
        if (dist(ta, p) + dist(p, tb) <= 1.0 * T * V) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}