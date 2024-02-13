#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    for (int i = 2; 1LL * i * i <= N; i++) {
        while (N % i == 0) {
            cout << i << ' ';
            N /= i;
        }
    }
    if (N != 1) cout << N;
    cout << endl;
}