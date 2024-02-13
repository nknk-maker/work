#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long N;
long long modpow(long long a, long long b, long long m) {
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
int main() {
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += modpow(2, i, mod) * (A[i] % mod);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}