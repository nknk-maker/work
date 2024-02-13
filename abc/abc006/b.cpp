#include <iostream>
using namespace std;

struct Matrix {
    long long p[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
};

Matrix multiplication(Matrix A, Matrix B) {
    Matrix C;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                C.p[i][j] += A.p[i][k] * B.p[k][j];
                C.p[i][j] %= 10007;
            }
        }
    }
    return C;
}

Matrix modpow(Matrix A, int b) {
    Matrix p = A, ret;
    bool flag = false;
    for (int i = 0; i < 30; i++) {
        if (b & (1 << i)) {
            if (!flag) {
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
    int N;
    cin >> N;
    Matrix A = {{{1, 1, 1}, {1, 0, 0}, {0, 1, 0}}};
    Matrix B = modpow(A, N - 3);
    if (N <= 3) {
        cout << N / 3 << endl;
        return 0;
    }
    cout << B.p[0][0] << endl;
    return 0;
}

