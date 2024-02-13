#include <iostream>
#include <algorithm>
using namespace std;

int N, M, A[109];
long long dp[109][1024];

int main() {
    // input
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        A[i] = 0; int tmp;
        for (int j = 1; j <= N; j++) {
            cin >> tmp;
            A[i] += (tmp << (N-j));
        }
    }

    // initialize array
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j < (1 << N); j++) dp[i][j] = 1000000000;
    }

    // DP
    dp[0][0] = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < (1 << N); j++) {
            int v = (A[i] | j);
            // make a transition
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            dp[i][v] = min(dp[i][v], dp[i-1][j] + 1);
        }
    }
    // output (integer representation is 2^N-1 if all are chosen)
    if (dp[M][(1 << N) - 1] == 1000000000) cout << "-1" << endl;
    else cout << dp[M][(1 << N) - 1] << endl;
    return 0;
}