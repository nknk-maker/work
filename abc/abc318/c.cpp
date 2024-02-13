#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, D, P;
    cin >> N >> D >> P;
    vector<long long> f(N);
    for (int i = 0; i < N; i++) cin >> f[i];
    sort(f.begin(), f.end(), greater<long long>());
    vector<long long> g(N + 1, 0);
    for (int i = 1; i <= N; i++) g[i] = g[i - 1] + f[i - 1];
    long long ans = (1LL << 62);
    for (int i = 0; i <= N / D + 1; i++) {
        // i枚周遊券を使う
        long long tmp = P * i;
        tmp += g[N] - g[min(D * i, N)];
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}