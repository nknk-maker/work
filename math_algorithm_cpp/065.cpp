#include <bits/stdc++.h>
using namespace std;
int main() {
    long long H, W;
    cin >> H >> W;
    long long ans;
    if (H == 1 || W == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (W % 2 == 1 && H % 2 == 1) {
        ans = (H - 1) / 2 * W + (W + 1) / 2;
    }
    else {
        if (H % 2 == 1) {
            swap(H, W);
        }
        ans = H / 2 * W;
    }
    cout << ans << endl;
}