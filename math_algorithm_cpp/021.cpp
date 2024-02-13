#include <bits/stdc++.h>
using namespace std;
long long N, R, fact[29];
long long combination(int n, int r) {
    return fact[n] / fact[r] / fact[n - r];
}
int main() {
    cin >> N >> R;
    fact[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fact[i] = fact[i - 1] * i;
    }
    cout << combination(N, R) << endl;
}