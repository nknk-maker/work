#include <bits/stdc++.h>
using namespace std;
long long fact[1000009];
long long mod = 1000000007;
long long power(long long a, long long b, long long m) {
    long long p = a, ret = 1;
    for (int i = 0; i < 40; i++) {
        if ((b & (1LL << i)) != 0) {
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
long long ncr(long long n, long long r, long long m) {
    long long top = fact[n];
    long long bottom = fact[r] * fact[n - r];
    return moddivision(top, bottom % m, m);
}
int main() {
    long long X, Y;
    cin >> X >> Y;
    fact[0] = 1;
    for (int i = 1; i < 1000000; i++) {
        fact[i] = i * fact[i - 1] % mod;
    }
    // 上、右それぞれの移動回数の合計を求める i * (1, 2), j * (2, 1), X = i + 2j, Y = 2i + j, i + j = (X + Y) / 3, i = 2Y / 3 - X / 3
    if ((X + Y) % 3 != 0 || 2 * min(X, Y) < max(X, Y)) {
        cout << 0 << endl;
        return 0;
    }
    long long i, j;
    i = Y - (X + Y) / 3;
    j = X - (X + Y) / 3;
    long long ans = ncr(i + j, i, mod);
    cout << ans << endl;
    return 0;
}