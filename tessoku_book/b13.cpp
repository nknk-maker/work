#include <iostream>
using namespace std;

int N, K;
long long A[100009], B[100009], R[100009];

int main() {
    // 入力
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // 累積和を計算
    B[0] = 0;
    for (int i = 1; i <= N; i++) B[i] = B[i - 1] + A[i];

    // 累積和に対してしゃくとり法
    for (int i = 0; i <= N-1; i++) {
        if (i == 0) R[i] = 0;
        else R[i] = R[i-1];

        // ギリギリまで増やしていく
        while (R[i] < N && B[R[i]+1] - B[i] <= K) {
            R[i]++;
        }
    }

    // 出力
    long long ans = 0;
    for (int i = 0; i <= N-1; i++) ans += R[i] - i;
    cout << ans << endl;
    return 0;
}