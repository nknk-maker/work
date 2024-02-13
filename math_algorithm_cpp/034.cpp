#include <bits/stdc++.h>
using namespace std;
double dist(long long ax, long long ay, long long bx, long long by) {
    return sqrt((pow(ax - bx, 2)) + pow(ay - by, 2));
}
long long N;
long long X[2009], Y[2009];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    double ans = 1e300;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            ans = min(ans, dist(X[i], Y[i], X[j], Y[j]));
        }
    }
    printf("%.12lf\n", ans);
}