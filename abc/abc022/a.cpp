#include <iostream>
using namespace std;

int main() {
    int N, S, T;
    int W, A[1009];
    cin >> N >> S >> T >> W;
    for (int i = 2; i <= N; i++) cin >> A[i];
    int ans = 0;
    if (S <= W && W <= T) ans++;
    for (int i = 2; i <= N; i++) {
        W += A[i];
        if (S <= W && W <= T) ans++;
    }
    cout << ans << endl;
    return 0;
}