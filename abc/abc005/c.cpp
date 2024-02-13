#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, M, A[109], B[109];
    cin >> T >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    cin >> M;
    for (int i = 1; i <= M; i++) cin >> B[i];
    int j = 1; // j以降のたこ焼きしか選べない
    for (int i = 1; i <= M; i++) { 
        while (A[j] + T < B[i] && j <= N) j++;
        if (A[j] > B[i] || A[j] + T < B[i]) {
            cout << "no" << endl;
            return 0;
        }
        j++; // たこ焼きを売ったので次のたこ焼きに
    }
    cout << "yes" << endl;
    return 0;
}