#include <bits/stdc++.h>
using namespace std;
struct matrix {
    double p[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
};
matrix multiplication(matrix A, matrix B) {
    // i行目j列目kこめの要素を足す
    matrix C;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                C.p[i][j] += A.p[i][k] * B.p[k][j];
            }
        }
    }
    return C;
}
matrix modpow(matrix A, long long n) {
    matrix p = A, ret;
    bool flag = false;
    for (int i = 0; i < 30; i++) {
        if ((n & (1LL << i)) != 0) {
            if (!flag) {
                flag = true;
                ret = p;
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
    long long q;
    cin >> q;
    double x, y, z;
    long long t;
    for (int i = 0; i < q; i++) {
        cin >> x >> y >> z >> t;
        matrix A = {{{1 - x, y, 0}, {0, 1 - y, z}, {x, 0, 1 - z}}};
        matrix B = modpow(A, t);
        double ans1, ans2, ans3;
        ans1 = B.p[0][0] + B.p[0][1] + B.p[0][2];
        ans2 = B.p[1][0] + B.p[1][1] + B.p[1][2];
        ans3 = B.p[2][0] + B.p[2][1] + B.p[2][2];
        printf("%.12lf %.12lf %.12lf\n", ans1, ans2, ans3);
    }
    return 0;
}