#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, ans = 0;
    long long y;
    map<int, long long> mp;
    map<int, long long>::iterator itr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        while ((x & 1) == 0) {
            x >>= 1, y <<= 1;
        }
        mp[x] += y;
    }
    itr = mp.begin();
    while (itr != mp.end()) {
        y = (*itr).second;
        while (y > 0) {
            if (y & 1) ans++;
            y >>= 1;
        }
        itr++;
    }
    cout << ans << endl;
    return 0;
}