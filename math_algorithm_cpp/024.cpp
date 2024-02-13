#include <bits/stdc++.h>
using namespace std;
long long N;
int P[59], Q[59];
int main() {
    cin >> N;
    double ans = 0.0;
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> Q[i];
        ans += 1.0 * Q[i] / P[i];
    }
    printf("%.12lf\n", ans);
}