#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<unsigned long long> R(N);
    for (int i = 0; i < N; i++) cin >> R[i];
    sort(R.begin(), R.end());
    vector<unsigned long long> B(N + 1);
    B[0] = 0;
    for (int i = 1; i <= N; i++) B[i] = B[i-1] + R[i-1];
    long long q;
    for (int i = 0; i < Q; i++) {
        cin >> q;
        cout << upper_bound(B.begin(), B.end(), q) - B.begin() - 1 << endl;
    }
    return 0;
}           