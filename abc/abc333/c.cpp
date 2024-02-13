#include <bits/stdc++.h>
using namespace std;

long long rep(int n) {
    long long ret = 1;
    for (int i = 0; i < n-1; i++) {
        ret *= 10;
        ret += 1;
    }
    return ret;
}

int main() {
    vector<long long> ans(0);
    for (int i = 1; i <= 11; i++) {
        for (int j = i; j <= 12; j++) {
            for (int k = j; k <= 13; k++) ans.push_back(rep(i) + rep(j) + rep(k));
        }
    }
    sort(ans.begin(), ans.end());
    int N;
    cin >> N;
    cout << ans[N-1] << endl;
    return 0;
}