#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> c(9);
    for (int i = 0; i < 9; i++) cin >> c[i];
    vector<vector<int>> vs = {{0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 1, 2}, {3, 4, 5}, {6, 7, 8},{0, 4, 8}, {2, 4, 6}};
    // 調べる必要のあるものだけを抽出（2つ同じ
    vector<vector<int>> search_v;
    for (vector<int> v : vs) {
        // v[0] == v[1]
        if (c[v[0]] == c[v[1]]) {
            search_v.push_back(v);
            continue;
        }
        if (c[v[0]] == c[v[2]]) {
            swap(v[1], v[2]);
            search_v.push_back(v);
            continue;
        }
        if (c[v[1]] == c[v[2]]) {
            swap(v[0], v[2]);
            search_v.push_back(v);
            continue;
        }
    }
    long long per = 0;
    long long all = 0;
    do {
        for (vector<int> s : search_v) {
            // v[0] v[1] <= v[2]か
            if (a[s[0]] < a[s[2]] && a[s[1]] < a[s[2]]) {
                per++;
                break;
            }
        }
        all++;
    }while(next_permutation(a.begin(), a.end()));
    double ans = 1.0 * per / all;
    printf("%.12lf\n", 1 - ans);
}