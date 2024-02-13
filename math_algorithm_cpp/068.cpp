#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    if (a < b) swap(a, b);
    return a / gcd(a, b) * b;
}
int main() {
    long long N, K;
    cin >> N >> K;
    vector<long long> v(K);
    for (int i = 0; i < K; i++) cin >> v[i];
    // bit全探索
    long long ans = 0;
    for (int i = 1; i < (1 << K); i++) {
        long long lc = 1, cnt = 0;
        for (int j = 0; j < K; j++) {
            if ((i & (1 << j)) != 0) {
                lc = lcm(lc, v[j]);
                cnt++;
            }
        }
        if (cnt % 2 == 1) {
            ans += N / lc;
        }
        else {
            ans -= N / lc;
        }
    }
    cout << ans << endl;
}