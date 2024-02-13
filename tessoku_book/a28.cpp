#include <iostream>
using namespace std;

int main() {
    long long N, A[100009]; char t[100009];
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> t[i] >> A[i];

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        if (t[i] == '+') ans += A[i];
        if (t[i] == '-') ans -= A[i];
        if (t[i] == '*') ans *= A[i];
        if (ans < 0) ans += 10000;
        ans %= 10000;
        cout << ans << endl;
    }
    return 0;
}