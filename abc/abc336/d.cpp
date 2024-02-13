#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1), m1(N + 1), m2(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    // m1, m2 を計算
    m1[1] = 0;
    for (int i = 2; i <= N; i++) m1[i] = min(m1[i-1], A[i] - i);
    m2[N] = N + 1;
    for (int i = N-1; i >= 1; i--) m2[i] = min(m2[i+1], A[i] + i);
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, min(m1[i] + i, m2[i] - i));
    }
    cout << min(ans, (N + 1) / 2) << endl;
    return 0;
}