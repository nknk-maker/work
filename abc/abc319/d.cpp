#include <bits/stdc++.h>
using namespace std;
int N, M;
bool h(long long w, vector<long long> L) {
    long long width = 0;
    long long height = 1;
    for (long long i : L) {
        if (width + i > w) {
            height++;
            width = 0;
        }
        width += i;
    }
    if (height <= M) return true;
    else return false;
}
int main() {
    cin >> N >> M;
    vector<long long> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];
    for (int i = 0; i < N; i++) L[i]++;
    long long ok = 2000000000000009 ;
    long long ng = *max_element(L.begin(), L.end()) - 1;
    while (ok - ng > 1) {
        long long m = (ok + ng) / 2;
        if (h(m, L)) ok = m;
        else ng = m;
    }
    cout << ok - 1 << endl;
    return 0;
}
