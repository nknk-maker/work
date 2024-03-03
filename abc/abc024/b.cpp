#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N, T;
    cin >> N >> T;
    vector<long long> A(N), B(1200000), C(1200000);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        B[A[i]]++;
        B[min(A[i] + T, (long long) B.size() - 1)]--;
    }
    for (int i = 1; i < C.size(); i++) {
        C[i] = C[i-1] + B[i];
    }
    long long ans = 0;
    for (int i = 0; i < C.size(); i++) {
        ans += (1 && C[i]);
    }
    cout << ans << endl;
    return 0;
}