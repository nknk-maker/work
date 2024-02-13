#include <bits/stdc++.h>
using namespace std;
long long N, A[109];
int main() {
    cin >> N;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long ans = 0;
    for (int i = 0; i < N - 4; i++) {
        for (int j = i + 1; j < N - 3; j++) {
            for (int k = j + 1; k < N - 2; k++) {
                for (int l = k + 1; l < N - 1; l++) {
                    for (int m = l + 1; m < N; m++) {
                        if (A[i] + A[j] + A[k] + A[l] + A[m] == 1000) {
                            ans++;
                        }
                    } 
                }
            }
        }
    }
    cout << ans << endl;
}