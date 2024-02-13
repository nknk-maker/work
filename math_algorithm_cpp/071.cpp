#include <bits/stdc++.h>
using namespace std;
long long N, a[509], b[509], c[509];
bool check(double x, double y) {
    for (int i = 0; i < N; i++) {
        if (a[i] * x + b[i] * y > c[i]) return false;
    }
    return true;
}
int main() {
    // input
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];
    // 二つ式を選び、その交点の座標を評価する
    double ans = -1e30;
    for (int i = 0; i <= N - 2; i++) {
        for (int j = i + 1; j <= N - 1; j++) {
            // 交点を持たない場合
            if (a[i] * b[j] == a[j] * b[i]) continue;

            // i番目の直線とj番目の直線の交点を求める
            double px = -1.0 * (b[i] * c[j] - b[j] * c[i]) / (a[i] * b[j] - a[j] * b[i]);
            double py = 1.0 * (a[i] * c[j] - a[j] * c[i]) / (a[i] * b[j] - a[j] * b[i]);

            bool ret = check(px - 0.000000001, py - 0.000000001);
            if (!ret) continue;

            // ansを更新
            ans = max(ans, px + py);
        }
    }
    // output
    printf("%.12lf\n", ans);
    return 0;
}