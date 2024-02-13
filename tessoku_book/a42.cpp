#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int A[309], B[309], C[109][109], D[209][209]; // C, D は二次元累積和用の配列

// 整数の組 (a, b) が決まった時の、参加k能な生徒数を返す関数
int GetScore(int a, int b) {
    return D[a+K][b+K] + D[a-1][b-1] - D[a-1][b+K] - D[a+K][b-1];
}

int main() {
    // 入力
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

    // 二次元累積和を計算
    for (int i = 1; i <= N; i++) D[A[i]][B[i]]++;
    for (int i = 1; i <= 209; i++) {
        for (int j = 1; j <= 209; j++) {
            D[i][j] += D[i][j-1];
        }
    }
    for (int j = 1; j <= 209; j++) {
        for (int i = 1; i <= 209; i++) {
            D[i][j] += D[i-1][j];
        }
    }

    // (a, b) の組を全探索
    int Answer = 0;
    for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            int Score = GetScore(a, b);
            Answer = max(Answer, Score);
        }
    }

    // 出力
    cout << Answer << endl;
    return 0;
}