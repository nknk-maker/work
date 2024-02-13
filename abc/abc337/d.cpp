#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 入力
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H + 1);
    vector<vector<int>> A(H + 10, vector<int> (W + 10));
    vector<vector<int>> B(H + 10, vector<int> (W + 10));
    vector<vector<int>> C(H + 10, vector<int> (W + 10));
    vector<vector<int>> D(H + 10, vector<int> (W + 10)); // A, B は横。C,D は縦
    for (int i = 1; i <= H; i++) {
        cin >> S[i];
        S[i] = " " + S[i];
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (S[i][j] == 'o') {
                A[i][j]++;
                C[i][j]++;
            }
            else if (S[i][j] == 'x') {
                B[i][j]++;
                D[i][j]++;
            }
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            A[i][j] += A[i][j-1];
            B[i][j] += B[i][j-1];
        }
    }
    for (int j = 1; j <= W; j++) {
        for (int i = 1; i <= H; i++) {
            C[i][j] += C[i-1][j];
            D[i][j] += D[i-1][j];
        }
    }

    int ans = 1000000000;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W - K + 1; j++) {
            int tmp = 0;
            if (B[i][j+K-1] - B[i][j-1] > 0) continue;
            int ok = A[i][j+K-1] - A[i][j-1];
            tmp = K - ok;
            ans = min(ans, tmp);
        }
    }

    for (int i = 1; i <= H - K + 1; i++) {
        for (int j = 1; j <= W; j++) {
            int tmp = 0;
            if (D[i+K-1][j] - D[i-1][j] > 0) continue;
            int ok = C[i+K-1][j] - C[i-1][j];
            tmp = K - ok;
            ans = min(ans, tmp);
        }
    }
    if (ans >= 1000000000) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}