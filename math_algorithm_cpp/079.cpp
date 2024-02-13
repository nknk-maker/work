#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    long long ans;
    if (N % 2 == 0) ans = N / 2 * (N - 1);
    else ans = (N - 1) / 2 * N;
    cout << ans << endl;
    return 0;
}