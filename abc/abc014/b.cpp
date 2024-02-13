#include <iostream>
using namespace std;

int main() {
    long long n, X;
    int a[29];
    cin >> n >> X;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (X & (1LL << i)) ans += a[i];
    }
    cout << ans << endl;
    return 0;
}