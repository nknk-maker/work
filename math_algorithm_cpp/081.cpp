#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    long long ans = 0;
    ans += N / 10000;
    N %= 10000;
    ans += N / 5000;
    N %= 5000;
    ans += N / 1000;
    N %= 1000;
    if (N != 0) ans++;
    cout << ans << endl;
    return 0;
}