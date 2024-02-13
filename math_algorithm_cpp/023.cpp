#include <bits/stdc++.h>
using namespace std;
long long N, A[100009], B[100009];
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
    double ans = 0;
    ans += 1.0 * A_sum / N;
    ans += 1.0 * B_sum / N;
    printf("%.12lf\n", ans);
}