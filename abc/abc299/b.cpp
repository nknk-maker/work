#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, t;
    cin >> n >> t;
    vector<int> c(n), r(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> r[i];
    long long x = 0;
    long long ans = 0;
    // tが出された場合
    if (find(c.begin(), c.end(), t) != c.end()) {
        for (int i = 0; i < n; i++) {
            if (c.at(i) == t) {
                if (r.at(i) > x) {
                    x = r.at(i);
                    ans = i + 1;
                }
            }
        }
    }
    else {
        t = c.at(0);
        for (int i = 0; i < n; i++) {
            if (c.at(i) == t) {
                if (r.at(i) > x) {
                    x = r.at(i);
                    ans = i + 1;
                }
            }
        }
    }
    cout << ans << endl;
}