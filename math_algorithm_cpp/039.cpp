#include <bits/stdc++.h>
using namespace std;
long long N, Q;
int main() {
    cin >> N >> Q;
    vector<long long> A(N + 2, 0); // 階差
    int L, R, X;
    for (int i = 1; i <= Q; i++) {
        cin >> L >> R >> X;
        A[L] += X;
        A[R + 1] -= X;
    }
    // output
    for (int i = 2; i <= N; i++) {
        if (A[i] > 0) cout << '<';
        if (A[i] == 0) cout << '=';
        if (A[i] < 0) cout << '>';
    }
    cout << endl;
    return 0;
}