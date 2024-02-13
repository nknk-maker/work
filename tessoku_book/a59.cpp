#include <iostream>
#include <algorithm>
using namespace std;

class SegmentTree {
    public:
    int dat[300000];
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
        if (r <= a || b <= l) return 0; // 全く含まれない場合
        if (l <= a && b <= r) return dat[u]; // 完全に含まれる場合
        // 一部分だけ含まれる場合は、分解していく
        int m = (a + b) / 2;
        int AnswerL = query(l, r, a, m, 2 * u);
        int AnswerR = query(l, r, m, b, 2 * u + 1);
        return AnswerL + AnswerR;
    }
};

int N, Q, Query[100009], pos[100009], x[100009], l[100009], r[100009];
SegmentTree Z;

int main() {
    // 入力
    cin >> N >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> Query[i];
        if (Query[i] == 1) cin >> pos[i] >> x[i];
        if (Query[i] == 2) cin >> l[i] >> r[i];
    }

    Z.init(N);
    // クエリの処理
    for (int i = 1; i <= Q; i++) {
        if (Query[i] == 1) Z.update(pos[i], x[i]);
        if (Query[i] == 2) {
            int ans = Z.query(l[i], r[i], 1, Z.siz + 1, 1);
            cout << ans << endl;
        }
    }
    return 0;
}