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
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // out answer
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, (int)G[i].size());
    }
    
    cout << ans << endl;
    return 0;
}