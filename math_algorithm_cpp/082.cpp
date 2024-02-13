#include <bits/stdc++.h>
using namespace std;
long long N;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}
int main() {
    cin >> N;
    vector<pair<long long, long long>> RL(N);
    long long L, R;
    for (int i = 0; i < N; i++) {
        cin >> L >> R;
        RL[i] = make_pair(R, L);
    }
    sort(RL.begin(), RL.end(), cmp);
    L = 0;
    R = 0;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (R <= RL[i].second) {
            L = RL[i].second;
            R = RL[i].first;
            ans++;
        }
    }
    cout << ans << endl;
}