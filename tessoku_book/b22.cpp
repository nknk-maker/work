#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009], B[100009], dp[100009];

int main() {
    // input
    cin >> N;
    for (int i = 2; i <= N; i++) cin >> A[i];
    for (int i = 3; i <= N; i++) cin >> B[i];

    // initialize array
    dp[0] = 0;
    for (int i = 2; i <= N; i++) dp[i] = 1000000000;

    // DP
    for (int i = 1; i <= N-2; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + A[i + 1]);
        dp[i + 2] = min(dp[i + 2], dp[i] + B[i + 2]);
    }
    dp[N] = min(dp[N], dp[N-1] + A[N]);
    cout << dp[N] << endl;
    return 0;
}