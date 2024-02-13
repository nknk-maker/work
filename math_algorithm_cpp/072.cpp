#include <bits/stdc++.h>
using namespace std;
long long A, B;
int main() {
    // input
    cin >> A >> B;

    // floor(B / k) - ceil(A / k) >= 1か？
    long long ans = 0;
    for (int k = 1; k <= B; k++) {
        if (B / k - ((A - 1) / k + 1) >= 1) ans = k;
    }
    cout << ans << endl;
    return 0;
    
}