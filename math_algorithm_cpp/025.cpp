#include <bits/stdc++.h>
using namespace std;
long long N, A[200009], B[200009];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    long long A_sum = 0, B_sum = 0;
    for (int i = 0; i < N; i++) {
        A_sum += A[i];
        B_sum += B[i];
    }
    double ans = 0.0;
    ans += 1.0 * A_sum / 3;
    ans += 1.0 * B_sum / 3 * 2;
    printf("%.12lf\n", ans);
}