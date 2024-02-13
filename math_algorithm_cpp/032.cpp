#include <bits/stdc++.h>
using namespace std;
long long N, X;
int main() {
    cin >> N >> X;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int l = 0, r = N + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (A[m] > X) r = m;
        else if (A[m] < X) l = m;
        else  {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}