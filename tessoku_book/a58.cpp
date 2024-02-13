#include <iostream>
#include <algorithm>
using namespace std;

class SegmentTree {
    public: // 初期化
    int dat[300000], siz = 1;

    // 要素 dat の初期化を行う（最初は全部ゼロ）
    void init(int N) {
        siz = 1;
        while (siz < N) siz *= 2;
        for (int i = 1; i < siz * 2; i++) dat[i] = 0;
    }

    // クエリ１に対する処理
    void update(int pos, int x) {
        // pos の値を d[u] の形に変換
        pos = pos + siz - 1;
        // dat[pos] の値を x に更新
        dat[pos] = x;
        // dat[pos] を更新したことで、その上の値も更新していく必要がある
        while (pos >= 2) { // pos が１になるまで
            pos /= 2;
            dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]); // dat[pos] の値を更新
        }
    }

    // クエリ２に対する処理
    // 区間を完全に含まれるまで分解していく
    // u は現在のセル番号、[a,b) はセルに対応する半開区間、[l, r) は求めたい半開区間
    int query(int l, int r, int a, int b, int u) {
        // 一切含まれない場合 (r <= a)求めたい半開区間が左にあるか, (b <= l) 右にあるか。
        if (r <= a || b <= l) return -1000000000; // 答えに一切関与しない値を返す
        // 完全に含まれる場合
        if (l <= a && b <= r) return dat[u];
        // 一部だけ含まれる場合
        int m = (a + b) / 2;
        int AnswerL = query(l, r, a, m, u * 2);
        int AnswerR = query(l, r, m, b, u * 2 + 1);
        return max(AnswerL, AnswerR);
    }
};

int N, Q;
int Query[100009], pos[100009], x[100009], l[100009], r[100009];
SegmentTree Z;
int main() {
    // 入力
    cin >> N >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> Query[i];
        if (Query[i] == 1) cin >> pos[i] >> x[i];
        if (Query[i] == 2) cin >> l[i] >> r[i];
    }

    // クエリ処理（[l, r) の最大値を求めるなら、Z.query(1, Z.siz, l, r, 1) を実行すればよい
    // Zの初期化
    Z.init(N);
    for (int i = 1; i <= Q; i++) {
        if (Query[i] == 1) {
            Z.update(pos[i], x[i]);
        }
        if (Query[i] == 2) {
            // 最初のセルに対応する半開区間は [1, siz + 1)
            int Answer = Z.query(l[i], r[i], 1, Z.siz + 1, 1);
            cout << Answer << endl;
        }
    }
    return 0;
}