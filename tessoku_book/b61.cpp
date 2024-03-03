#include <iostream>
#include <vector>

using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> G[100009];

int main() {
    // in
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // out answer
    pair<int, int> ans = {0, 0};
    for (int i = 1; i <= N; i++) {
        if (ans.second < G[i].size()) ans = make_pair(i, G[i].size());
    }

    cout << ans.first << endl;
    return 0;
}