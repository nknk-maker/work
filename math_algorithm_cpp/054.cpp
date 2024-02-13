#include <bits/stdc++.h>
using namespace std;
struct Matrix{
    vector<vector<long long>> p = {{0, 0}, {0, 0}};
};
void coutmatrix(Matrix A) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << A.p[i][j] << endl;
        }
    }
}
Matrix multiplication(Matrix A, Matrix B) {
    Matrix C;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C.p[i][j] += A.p[i][k] * B.p[k][j];
                C.p[i][j] %= 1000000000;
            }
        }
    }
    return C;
}
Matrix modpow(Matrix A, long long b) {
    Matrix p = A, ret;
    bool flag = false;
    for (int i = 0; i < 60; i++) {
        if ((b & (1LL << i)) != 0LL) {
            if (flag == false) {
                ret = p;
                flag = true;
            }
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
    Matrix A = {{{1, 1}, {1, 0}}};
    Matrix B = modpow(A, N - 2);
    //coutmatrix(B);
    long long ans = B.p[0][0] + B.p[0][1];
    ans %= 1000000000;
    cout << ans << endl;
    return 0;
}
