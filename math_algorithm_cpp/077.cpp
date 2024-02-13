#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    vector<long long> x(N);
    vector<long long> y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += (-N + 2 * i - 1) * (x[i - 1] + y[i - 1]);
    }
    cout << ans << endl;
    return 0;
}