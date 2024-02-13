#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main () {
    int N, D;
    cin >> N >> D;
    int X[N + 1], Y[N + 1];
    for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
    vector<vector<int>> G(D + 1, vector<int> ()); // G[i] : i 日目から始まる仕事のリスト
    for (int i = 1; i <= N; i++) G[X[i]].push_back(Y[i]);
    priority_queue<int> pq;
    int ans = 0;
    for (int i = 1; i <= D; i++) {
        for (int j : G[i]) pq.push(j);
        if (!pq.empty()) {
        ans += pq.top();
        pq.pop();
        }
    }
    cout << ans << endl;
    return 0;
}