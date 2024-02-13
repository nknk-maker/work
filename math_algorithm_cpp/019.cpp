#include <bits/stdc++.h>
using namespace std;
long long N, A[4];
int main() {
    cin >> N;
    int color;
    for (int i = 0; i < N; i++) {
        cin >> color;
        A[color]++;
    }
    long long ans = 0;
    for (int i = 1; i < 4; i++) {
        ans += A[i] * (A[i] - 1) / 2;
    }
    cout << ans << endl;
}