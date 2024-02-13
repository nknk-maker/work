#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += (-N + 2 * i - 1) * A[i - 1];
    }
    cout << ans << endl;
    return 0;
}