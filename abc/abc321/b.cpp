#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, X;
    cin >> N >> X;
    vector<long long> A(N - 1);
    for (int i = 0; i < N - 1; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int pattern = 0;
    long long sum_1 = 0, sum_2 = 0, sum_3 = 0;
    for (int i = 0; i < N - 2; i++) sum_1 += A[i];
    for (int i = 1; i < N - 1; i++) sum_3 += A[i];
    if (X <= sum_1) pattern = 1;
    else if (X < sum_3) pattern = 2;
    else if (X == sum_3) pattern = 3;
    // 無理な場合
    if (pattern == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (pattern == 1) {
        cout <<  0 << endl;
        return 0;
    }
    if (pattern == 2) {
        // X - sum_2
        for (int i = 1; i < N - 2; i++) sum_2 += A[i];
        cout << X - sum_2 << endl;
        return 0;
    }
    if (pattern == 3) {
        cout << A[N - 2] << endl;
        return 0;
    }
}