#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    long long m = 1000000007;
    cin >> N;
    long long ans = (N * (N + 1) / 2) % m;
    ans *= ans;
    ans %= m;
    cout << ans << endl;
}