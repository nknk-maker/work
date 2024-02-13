#include <bits/stdc++.h>
using namespace std;
long long N, K;
long long X[59], Y[59];
long long judge(long long lx, long long rx, long long ly, long long ry) {
    long long ret = 0;
    for (int i = 0; i < N; i++) {
        if ((lx <= X[i] && X[i] <= rx) && (ly <= Y[i] && Y[i] <= ry)) ret++;
    }
    return ret;
}
int main() {
    // input
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    long long ans = 1LL << 62;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    long long lx = X[i], rx = X[j], ly = Y[k], ry = Y[l];
                    if (rx < lx) swap(lx, rx);
                    if (ry < ly) swap(ly, ry);
                    if (judge(lx, rx, ly, ry) >= K) ans = min(ans, (rx - lx) * (ry - ly));
                }
            }
        }
    }
    cout << ans << endl;
}