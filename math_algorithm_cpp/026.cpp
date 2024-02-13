#include <bits/stdc++.h>
using namespace std;
long long N;
int main() {
    cin >> N;
    double ans = 0;
    for (int r = 0; r < N; r++) {
        ans += 1.0 / (N - r);
    }
    ans *= N;
    printf("%.12lf\n", ans);
}