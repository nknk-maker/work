#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, M;
    cin >> N >> M;
    vector<long long> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) {
        cout << *lower_bound(A.begin(), A.end(), i) - i << endl;
    }
}