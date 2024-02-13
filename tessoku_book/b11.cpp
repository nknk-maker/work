#include <iostream>
#include <algorithm>
using namespace std;

int N, Q;
int A[100009], X[100009];

int binary_search(int x) {
    int L = 0, R = N + 1;
    while (L < R - 1) {
        int M = (L + R) / 2;
        if (A[M] >= x) R = M;
        if (A[M] < x) L = M;
    }
    return L;
}

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    cin >> Q;
    for (int i = 1; i <= Q; i++) cin >> X[i];

    // 配列のソート
    sort(A + 1, A + N + 1);

    // クエリに答える
    for (int i = 1; i <= Q; i++) {
        cout << binary_search(X[i]) << endl;
    }
    return 0;
}