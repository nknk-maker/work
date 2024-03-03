#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    long long N, T;
    cin >> N >> T;
    vector<long long> A(T + 1), B(T + 1), score(N + 1);
    for (int i = 1; i <= T; i++) cin >> A[i] >> B[i];
    map<long long, unsigned long long> m;
    m[0] = N;
    for (int i = 1; i <= T; i++) {
        m[score[A[i]]]--;
        if (m[score[A[i]]] == 0) m.erase(score[A[i]]);
        score[A[i]] += B[i];
        m[score[A[i]]]++;
        cout << m.size() << endl;
    }
    return 0;
}