#include <bits/stdc++.h>
using namespace std;

int N, A[200009], C[200009];

// A[l], A[l + 1], ,,,, A[r - 1] を昇順に整列するfunc
void MergeSort(int l, int r) {
    // r - l == 1の場合、すでにソートされているので何もしない
    if (r - l == 1) return;

    // 2つに分割した後、小さい配列をソート
    int m = (l + r) / 2;
    MergeSort(l, m);
    MergeSort(m, r);

    // この時点で以下の二つの配列がソート済
    // 列Aに該当するもの　A[l, m)
    // 列Bに該当するもの　A[m, r)
    // 以下がMerge操作

    int c1 = l, c2 = m, cnt = 0;
    while (c1 != m || c2 != r) {
        if (c1 == m) {
            // 列Aが空のとき
            C[cnt] = A[c2]; c2++;
        }
        else if (c2 == r) {
            // 列Bが空のとき
            C[cnt] = A[c1]; c1++;
        }
        else {
            // 列Aも列Bも空でないとき
            if (A[c1] <= A[c2]) {
                C[cnt] = A[c1]; c1++;
            }
            else {
                C[cnt] = A[c2]; c2++;
            }
        }
        cnt++;
    }
    // 列A', 列B'を合併した配列C'をAに移す
    // [C[0], ..., C[cnt - 1]] -> [A[l], ... , A[r - 1]]
    for (int i = 0; i < cnt; i++) {
        A[l + i] = C[i];
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    MergeSort(1, N + 1);
    for (int i = 1; i <= N; i++) {
        cout << A[i] << endl;
    }
    return 0;
}