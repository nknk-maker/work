#include <iostream>
using namespace std;

int main() {
    int N, A[509][509], Q, line[509];
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> A[i][j];
    }
    cin >> Q;
    for (int i = 1; i <= N; i++) line[i] = i;

    // クエリを処理する
    int q, x, y;
    for (int i = 1; i <= Q; i++) {
        cin >> q >> x >> y;
        if (q == 1) {
            swap(line[x], line[y]);
        }
        if (q == 2) {
            cout << A[line[x]][y] << endl;
        }
    }
    return 0;
}