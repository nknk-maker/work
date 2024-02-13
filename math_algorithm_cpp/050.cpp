#include <bits/stdc++.h>
using namespace std;
long long a, b, ans;
long long mod = 1000000007;
int main() {
    cin >> a >> b;
    ans = 1;
    // 繰り返し二乗法
    for (int i = 0; i < 30; i++) {
        if ((b & (1 << i)) != 0) {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
    }
    cout << ans << endl;
}