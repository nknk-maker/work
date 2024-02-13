#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, K;
    cin >> N >> K;
    long long Ac = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = max(1LL, i - (K - 1)); j <= min(N, i + (K - 1)); j++) {
            for (int k = max(1LL, i - (K - 1)); k <= min(N, i + (K - 1)); k++) {
                if (abs(j - k) <= K - 1) Ac++;
            }
        }
    }
    cout << N * N * N - Ac << endl;
}