#include <bits/stdc++.h>
using namespace std;
long long N;
void solve(long long N, vector<long long>& v) {
    for (int i = 2; i * i <= N; i++) {
        if (v.at(i) == 1) {
            for (int j = 1; i * j <= N; j++) {
                v.at(i * j)++;
            }
        }
    }
}
int main() {
    cin >> N;
    vector<long long> v(N + 1, 1);
    solve(N, v);
    long long ans = 0;
    for (int k = 1; k <= N; k++) {
        cout << v.at(k) << endl;
        ans += 1LL * v.at(k) * k;
    }
    ans--;
    cout << ans << endl;
}