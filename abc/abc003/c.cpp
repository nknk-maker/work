#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int R[4009];
    for (int i = 1; i <= N; i++) cin >> R[i];
    sort(R + 1, R + N + 1);
    double ans = 0;
    for (int i = N-K+1; i <= N; i++) {
        ans = (ans + R[i]) / 2;
    }
    printf("%.12lf\n", ans);
    return 0;
}