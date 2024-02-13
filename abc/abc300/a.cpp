#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c.at(i);
    }
    auto iter = find(c.begin(), c.end(), a + b);
    long long ans = distance(c.begin(), iter) + 1;
    cout << ans << endl;
}