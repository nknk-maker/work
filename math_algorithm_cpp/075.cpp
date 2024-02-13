#include <bits/stdc++.h>
using namespace std;
long long N;
long long mod = 1000000007;
long long fact[200009];
long long modpow(long long a, long long b, long long m) {
    long long p = a, ret = 1;
    for (int i = 0; i < 62; i++) {
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
    return a * modpow(b, m - 2, m) % m;
}
long long ncr(long long n, long long r, long long m) {
    long long top = fact[n];
    long long bottom = fact[n - r] * fact[r] % m;
    return moddivision(top, bottom, m);
}
int main() {
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fact[i] = i * fact[i - 1] % mod;
    }
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += ncr(N - 1, i, mod) * A[i];
        ans %= mod;
    }
    cout << ans << endl;
}