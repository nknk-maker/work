#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    vector<vector<long long>> p = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
};

Matrix multiplication(Matrix A, Matrix B) {
    Matrix C;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                C.p[i][j] += A.p[i][k] * B.p[k][j];
                C.p[i][j] %= 1000000007;
            }
        }
    }
    return C;
}

Matrix modpow(Matrix A, long long B) {
    Matrix p = A, ret;
    bool flag = false;
    for (int i = 0; i < 60; i++) {
        if ((B & (1LL << i)) != 0) {
            if (!flag) { flag = true; ret = p; }
            else {
                ret = multiplication(ret, p);
            }
        }
        p = multiplication(p, p);
    }
    return ret;
}

int main() {
    long long N;
    cin >> N;
    Matrix A = {{{1, 1, 1}, {1, 0, 0}, {0, 1, 0}}};
    Matrix B = modpow(A, N - 3);
    long long ans = 0;
    ans += 2 * B.p[0][0] % 1000000007;
    ans += B.p[0][1];
    ans %= 1000000007;
    ans += B.p[0][2];
    ans %= 1000000007;
    cout << ans << endl;
    return 0;
}