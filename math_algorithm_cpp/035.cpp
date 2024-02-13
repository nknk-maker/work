#include <bits/stdc++.h>
using namespace std;
int main() {
    long long x1, x2, y1, y2, r1, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    int ans;
    if (a < abs(r1 - r2)) ans = 1;
    if (a == abs(r1 - r2)) ans = 2;
    if (abs(r1 - r2) < a && a < r1 + r2) ans = 3;
    if (a == r1 + r2) ans = 4;
    if (a > r1 + r2) ans = 5;
    cout << ans << endl;
}