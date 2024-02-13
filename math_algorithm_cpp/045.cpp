#include <bits/stdc++.h>
#define ll long long
#define graph vector<vector<long long>>
using namespace std;
long long N, M;
int main() {
    cin >> N >> M;
    vector<ll> A(M), B(M);
    graph G(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        int flag = -1;
        for (int j : G[i]) {
            if (j < i) {
                flag++;
            }
        }
        if (!flag) ans++;
    }
    cout << ans << endl;
}