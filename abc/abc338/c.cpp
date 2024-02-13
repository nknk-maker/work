#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, Q[19], A[19], B[19];

bool check(int x, int y) {
    for (int i = 1; i <= N; i++) {
        if (A[i] * x + B[i] * y > Q[i]) return false;
    }
    return true;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> Q[i];
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];

    // 料理Aの個数で全探索
    int x = 0;
    vector<int> ans(1000009);
    while (x <= 1000000) {
        int ok = 0, ng = 1000009;
        while (ng - ok > 1) {
            int m = (ok + ng) / 2;
            if (check(x, m)) ok = m;
            else ng = m;
        }
        if (ok == 0 && !check(x, 0)) break;
        else ans[x] = x + ok;
        x++;
    }
    sort(ans.begin(), ans.end(), greater<int>());
    cout << ans[0] << endl;
    return 0;
}