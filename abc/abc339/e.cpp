#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    public:
    int dat[2000000], siz = 1;

    void init(int N) {
        while (siz < N) siz *= 2;
        for (int i = 1; i < siz * 2; i++) dat[i] = 0;
    }

    void update(int pos, int x) {
        pos = siz + pos - 1;
        dat[pos] = x;
        while (pos >= 2) {
            pos /= 2;
            dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
        }
    }

    int search(int l, int r, int a, int b, int u) {
        if (r <= a || b <= l) return 0;
        if (l <= a && b <= r) return dat[u];
        int m = (a + b) / 2;
        int AnswerL = search(l, r, a, m, u * 2);
        int AnswerR = search(l, r, m, b, u * 2 + 1);
        return max(AnswerL, AnswerR);
    }
};

int N, D, A[500009];
SegmentTree Z;

int main() {
    cin >> N >> D;
    Z.init(500000);
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) {
        int MAX = Z.search(max(A[i] - D, 1), min(A[i] + D, 500000) + 1, 1, Z.siz + 1, 1);
        Z.update(A[i], MAX + 1);
    }
    int ans = 0;
    for (int i = 1; i <= 500000; i++) {
        ans = max(ans, Z.dat[i + Z.siz - 1]);
    }
    cout << ans << endl;
    return 0;
}