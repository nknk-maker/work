#include <bits/stdc++.h>
using namespace std;
int main() {
    long long tate, yoko, n;
    cin >> n;
    tate = 1;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            tate = max(tate, i);
        }
    }
    yoko = n / tate;
    cout << tate * 2 + yoko * 2 << endl;
}