#include <iostream>
using namespace std;

int N, X, A[100009];

// 整数Xが何番目に存在するかを返す
int search(int x) {
    int L = 1, R = N;
    while (L <= R) {
        // 探索場にがなくなるまで比較を続ける
        int M = (L + R) / 2;
        if (x < A[M]) R = M - 1;
        if (x == A[M]) return M;
        if (x > A[M]) L = M + 1;
    }
    return -1; // 整数xが存在しない
}

int main() {
    // 入力
    cin >> N >> X;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // 二分探索を行う
    int Answer = search(X);
    cout << Answer << endl;
    return 0;
}