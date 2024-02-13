#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long K, A[39], R[33009], L[33009];

int main() {
    // 入力
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // コーナー
    if (N == 1) {
        if (K == A[1]) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }

    // RとLを計算
    for (int bit = 0; bit < (1<<(N/2)); bit++) {
        for (int i = 1; i <= (N/2); i++) {
            if (bit & (1<<(i-1))) L[bit + 1] += A[i];
        }
    }

    for (int bit = 0; bit < (1<<(N-N/2)); bit++) {
        for (int i = 1; i <= (N-N/2); i++) {
            if (bit & (1<<(i-1))) R[bit + 1] += A[N/2 + i];
        }
    }

    // 配列Rをソート
    sort(R+1, R+(1<<(N-N/2)));

    // 二分探索
    for (int i = 1; i < (1<<(N/2)); i++) {
        long long pos1 = lower_bound(R+1, R+(1<<(N-N/2)), K-L[i]) - R;
        if (pos1 <= (1<<(N-N/2)) && R[pos1] == K-L[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    // 見つからなかった場合
    cout << "No" << endl;
    return 0;
}
