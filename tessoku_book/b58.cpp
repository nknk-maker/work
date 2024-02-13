#include <iostream>
#include <algorithm>
using namespace std;

class SegmentTree {
    public:
    int dat[300009];
    int siz = 1;

    void init(int N) {
        while (siz < N) siz *= 2;
        for (int i = 1; i < siz * 2; i++) dat[i] = 1000000000;
    }

    void update(int pos, int x) {
        pos = pos + siz - 1;
        dat[pos] = x;
        while (pos >= 2) {
            pos /= 2;
            dat[pos] = min(dat[pos * 2], dat[pos * 2 + 1]);
        }
    }

    // [a, b) はセルに対応する半開区間、[l, r) は求めたい半開区間
    int search(int l, int r, int a, int b, int u) {
        if (r <= a || b <= l) return 1000000000; // 一切含まれない場合
        if (l <= a && b <= r) return dat[u]; // 完全に含まれる場合
        // 一部たけ含まれる場合
        int m = (a + b) / 2;
        int AnswerL = search(l, r, a, m, u * 2);
        int AnswerR = search(l, r, m, b, u * 2 + 1);
        return min(AnswerL, AnswerR);
    }
};

int N, L, R, X[1000009];
SegmentTree Z;

int main() {
    // 入力
    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++) cin >> X[i];
    Z.init(N);
    Z.update(1, 0);
    for (int i = 2; i <= N; i++) {
        int l = lower_bound(X + 1, X + N + 1, X[i] - R) - X;
        int r = upper_bound(X + 1, X + N + 1, X[i] - L) - X;
        r = min(r, i);
        int ans = Z.search(l, r, 1, Z.siz + 1, 1);
        Z.update(i, ans + 1);
    }
    cout << Z.dat[N + Z.siz - 1] << endl;
    return 0;
}