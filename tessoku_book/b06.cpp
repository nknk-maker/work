#include <iostream>
using namespace std;

int N, A[100009], S[100009];
int Q, R[100009], L[100009];

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] == 0) A[i]--;
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) cin >> L[i] >> R[i];

    // 累積和の計算
    S[0] = 0;
    for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

    // 質問に答える
    for (int i = 1; i <= Q; i++) {
        if (S[R[i]] - S[L[i] - 1] == 0) cout << "draw" << endl;
        if (S[R[i]] - S[L[i] - 1] > 0) cout << "win" << endl;
        if (S[R[i]] - S[L[i] - 1] < 0) cout << "lose" << endl;
    }
    return 0;
}