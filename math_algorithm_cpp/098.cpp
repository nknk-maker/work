#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    vector<long long> x(n);
    vector<long long> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x.at(i) >> y.at(i);
    }
    long long xc, yc;
    long long cnt = 0;
    cin >> xc >> yc;
    for (int i = 0; i < n; i++) {
        long long xa = x.at(i % n), ya = y.at(i % n), xb = x.at((i + 1) % n), yb = y.at((i + 1) % n);
        if (yb > ya) {
            swap(ya, yb);
            swap(xa, xb);
        }
        if ((yb <= yc && yc < ya) && (((xa - xc) * (yb - yc) - (ya - yc) * (xb - xc)) >= 0)) cnt++;
    }
    if (cnt % 2 == 1) cout << "INSIDE" << endl;
    else cout << "OUTSIDE" << endl;
}