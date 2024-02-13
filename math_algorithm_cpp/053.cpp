#include <bits/stdc++.h>
using namespace std;
long long N;
long long mod = 1000000007;
long long power(long long a, long long b, long long m) {
    long long p = a, ret = 1;
    for (int i = 0; i < 60; i++) {
        if ((b & (1LL << i)) != 0LL) {
            ret *= p;
            ret %= m;
        }
        p *= p;
        p %= m;
    }
    return ret;
}
long long moddivision(long long a, long long b, long long m) {
    return a * power(b, m - 2, m) % m;
}
int  main() {
    cin >> N;
    // 等比数列
    long long top = power(4, N + 1, mod) - 1;
    long long bottom = 3;
    long long ans = moddivision(top, bottom, mod);
    cout << ans << endl;
}