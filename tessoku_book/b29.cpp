#include <bits/stdc++.h>
using namespace std;

long long modpow(long long a, long long b, long long m) {
    long long p = a, ans = 1;
    for (int i = 0; i <= 63; i++) {
        if (b & 1LL << i) {ans *= p; ans %= m;}
        p *= p;
        p %= m;
    }
    return ans;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << modpow(a, b, 1000000007) << endl;
    return 0;
}