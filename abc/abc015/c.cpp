#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N, K;
    int t[10][10];
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) cin >> t[i][j];
    }
    for (int b = 0; b < pow(K, N); b++) {
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            ans = ans ^  t[i][(int)(b / pow(K, i)) % K];
        }
        if (ans == 0) {
            cout << "Found" << endl;
            return 0;
        }
    }
    cout << "Nothing" << endl;
    return 0;
}