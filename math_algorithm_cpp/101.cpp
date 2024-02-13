#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
int N; long long fact[100009];

long long modpow(long long a, long long b, long long m) {
    long long p = a, ans = 1;
    for (int i = 0; i < 30; i++) {
        if ((b & (1 << i)) != 0) {
            ans *= p;
            ans %= m;
        }
        p *= p;
        p %= m;
    }
    return ans;
}
long long division(long long a, long long b, long long m) {
    return (a * modpow(b, m - 2, m)) % m;
}
long long ncr(int n, int r) {
    return division(fact[n], fact[r] * fact[n - r] % mod, mod);
}
int main() {
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = 1LL * i * fact[i - 1] % mod;
    }
    cin >> N;
    for (int i = 1; i <= N; i++) {
        long long ans = 0;
        for (int j = 1; j <= (N + i - 1) / i; j++) {
            ans += ncr(N - (i - 1) * (j - 1), j);
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}