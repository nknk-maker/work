#include <iostream>
using namespace std;

int N, A[100009], B[100009], C[100009], D[100009];
int X[1509][1509], Z[1509][1509];

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    // 配列の初期化
    for (int i = 0; i <= 1500; i++) {
        for (int j = 0; j <= 1500; j++) {
            X[i][j] = 0;
            Z[i][j] = 0;
        }
    }

    // 配列に加算
    for (int i = 1; i <= N; i++) {
        X[A[i] + 1][B[i] + 1]++;
        X[C[i] + 1][D[i] + 1]++;
        X[A[i] + 1][D[i] + 1]--;
        X[C[i] + 1][B[i] + 1]--;
    }

    // 累積和を計算
    for (int i = 1; i <= 1501; i++) {
        for (int j = 1; j <= 1501; j++) Z[i][j] = Z[i][j - 1] + X[i][j];
    }
    for (int j = 1; j <= 1501; j++) {
        for (int i = 1; i <= 1501; i++) Z[i][j] = Z[i - 1][j] + Z[i][j];
    }

    // 答えを計算し、出力
    long ans = 0;
    for (int i = 1; i <= 1501; i++) {
        for (int j = 1; j <= 1501; j++) {
            if (Z[i][j] > 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}