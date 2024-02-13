#include <bits/stdc++.h>
using namespace std;
long long N, M;
int main() {
    cin >> N;
    vector<long long> A(N + 1, 0);
    vector<long long> B(N + 1, 0);
    for (int i = 2; i <= N; i++) {
        cin >> A.at(i);
    }
    for (int i = 1; i <= N; i++) {
        B[i] = B[i - 1] + A[i];
    }
    int L, R;
    cin >> M;
    cin >> L;
    long long ans = 0;
    for (int i = 1; i < M; i++) {
        cin >> R;
        ans += B[max(R, L)] - B[min(R, L)];
        L = R;
    }
    cout << ans << endl;
}