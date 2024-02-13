#include <iostream>
using namespace std;
int main() {
    int n;
    int a[109];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 0) {
            ans += a[i];
            cnt++;
        }
    }
    printf("%d\n", (ans + cnt - 1) / cnt);
    return 0;
}