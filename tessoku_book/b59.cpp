#include <iostream>
#include <algorithm>
using namespace std;

class SegmentTree {
    public:
    int dat[600009];
    int siz = 1;

    void init(int N) {
        while (siz < N) siz *= 2;
        for (int i = 1; i < siz; i++) dat[i] = 0;
    }

    void update(int pos, int x) {
        pos = pos + siz - 1;
        dat[pos] = x;
        while (pos >= 2) {
            pos /= 2;
            dat[pos] = dat[pos * 2] + dat[pos * 2 + 1];
        }
    }

    int query(int l, int r, int a, int b, int u) {
        if (r <= a || b <= l) return 0;
        if (l <= a && b <= r) return dat[u];
        int m = (a + b) / 2;
        int AnswerL = query(l, r, a, m, 2 * u);
        int AnswerR = query(l, r, m, b, 2 * u + 1);
        return AnswerL + AnswerR;
    }
};

int N,A[150009];
SegmentTree Z;

int main() {
    cin >> N;
    Z.init(N);
    for (int i = 1; i <= N; i++) cin >> A[i];
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        Z.update(A[i], 1);
        ans += Z.query(A[i] + 1, Z.siz + 1, 1, Z.siz + 1, 1);
    }
    cout << ans << endl;
    return 0;
}