#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    // a + b  + 2sqrt(a * b) < c
    // c - a - b < 0のときは両辺二乗できない！
    // 4(a * b) < (c - a - b) ^ 2;
    if (c - a - b < 0) cout << "No" << endl;
    else if (4LL * a * b < (c - a - b) * (c - a - b)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}