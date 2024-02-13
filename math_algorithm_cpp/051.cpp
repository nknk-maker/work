#include <bits/stdc++.h>
using namespace std;
long long fact[200009];
long long mod = 1000000007;
// 繰り返し二乗法
long long modpower(long long a, long long b, long long m) {
    long long p = a, ret = 1;
    for (int i = 0; i < 63; i++) {
        if ((b & (1LL << i)) != 0LL) {
            ret *= p;
            ret %= m;
        }
        p *= p;
        p %= m;
    }
    return ret;
}
// モジュラ逆数を使った割り算
long long moddivision(long long a, long long b, long long m)  {
    return a * modpower(b, m - 2, m) % m;
}
// ncr関数
long long ncr(long long n, long long r, long long m) {
    long long top = fact[n];
    long long bottom = fact[n - r] * fact[r] % m;
    return moddivision(top, bottom, m);
}
// main関数
int main() {
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
    }
    long long X, Y;
    cin >> X >> Y;
    cout << ncr(X + Y, X, mod) << endl;
}