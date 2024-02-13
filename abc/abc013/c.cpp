#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, H, A, B, C, D, E;

bool check(long long a, long long b) {
    if ((B + E) * a + (D + E) * b + H > N * E) return true;
    return false;
}

int main() {
    // 入力
    cin >> N >> H >> A >> B >> C >> D >> E;

    // x の値を固定してyを最小化
    vector<long long> ans(N + 1);
    for (long long x = 0; x <= N; x++) {
        long long ng = -1, ok = N + 1;
        while (ok - ng > 1) {
            long long m = (ok + ng) / 2;
            if (check(x, m)) ok = m;
            else ng = m;
        }
        ans[x] = A * x + C * ok;
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
    return 0;
}