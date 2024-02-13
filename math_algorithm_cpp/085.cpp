#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, X, Y;
    cin >> N >> X >> Y;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            for (int k = j; k <= N; k++) {
                for (int l = k; l <= N; l++) {
                    if (i + j + k + l == X && 1LL * i * j * k * l == Y) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}