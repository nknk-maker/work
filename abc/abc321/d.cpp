#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, M, P;
    cin >> N >> M >> P;
    vector<long long> A(N), B(M), AminB(N), BminA(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) {
        AminB[i] = lower_bound(B.begin(), B.end(), P - A[i] + 1) - B.begin();
    }
    for (int i = 0; i < M; i++) {
        BminA[i] = lower_bound(A.begin(), A.end(), P - B[i] + 1) - A.begin();
    }
    long long ans = 0;
    long long cnt_p = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i] * AminB[i];
        cnt_p += (M - AminB[i]);
    }
    for (int i = 0; i < M; i++) {
        ans += B[i] * BminA[i];
        cnt_p += (N - BminA[i]);
    }
    ans += (cnt_p / 2)* P;
    cout << ans << endl;
}