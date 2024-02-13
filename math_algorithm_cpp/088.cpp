#include <bits/stdc++.h>
using namespace std;
int main() {
    long long m = 998244353;
    long long a, b, c;
    cin >> a >> b >> c;
    long long a_sum = a * (a + 1) / 2;
    long long b_sum = b * (b + 1) / 2;
    long long c_sum = c * (c + 1) / 2;
    a_sum %= m;
    b_sum %= m;
    c_sum %= m;
    long long ans = ((a_sum * b_sum) % m * c_sum % m);
    cout << ans << endl;
    return 0;
}