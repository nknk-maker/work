#include <bits/stdc++.h>
using namespace std;
long long N, Q, A[100009], B[100009];
int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    B[0] = 0;
        for (int i = 1; i <= N; i++) {
        B[i] = B[i - 1] + A[i];
    }
    int L, R;
    for (int i = 0; i < Q; i++) {
        cin >> L >> R;
        cout << B[R] - B[L - 1] << endl;
    }
    return 0;
}