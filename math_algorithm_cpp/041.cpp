#include <bits/stdc++.h>
using namespace std;
long long T, N;
int main() {
    cin >> T >> N;
    vector<long long> A(T + 1, 0);
    vector<long long> B(T + 1, 0);
    int L, R;
    for (int i = 0; i < N; i++) {
        cin >> L >> R;
        A.at(L) ++;
        A.at(R) --;
    }
    B.at(0) = A.at(0);
    for (int i = 1; i < T; i++) {
        B.at(i) = B.at(i - 1) + A.at(i);
    }
    for (int i = 0; i < T; i++) {
        cout << B.at(i) << endl;
    }
    return 0;
}