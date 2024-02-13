#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            cout << i << endl;
            if (N / i != i) cout << N / i << endl;
        }
    }
}