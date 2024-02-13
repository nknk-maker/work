#include <bits/stdc++.h>
using namespace std;
long long N, A[100000];
int main() {
    cin >> N;
    int ind;
    for (int i = 0; i < N; i++) {
        cin >> ind;
        A[ind] ++;
    }
    long long ans = 0;
    for (int i = 1; i < 50000; i++) {
        ans += A[i] * A[100000 - i];
    }
    ans += A[50000] * (A[50000] - 1) / 2;
    cout << ans << endl;
}
