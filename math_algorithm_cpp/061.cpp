#include <bits/stdc++.h>
using namespace std;
// N = 1 -> s, N = 2 -> f, N = 3 -> s, N = 4 -> f, N = 5 -> f, N = 6 -> f, N = 7 -> s, ,,,, -> (N + 1) = 2 ^ x -> s, else f
int main() {
    long long N;
    cin >> N;
    // N -= 2^k-1の形で表せるかを調べる
    bool flag = false;
    for (int i = 0; i <=60; i++) {
        if (N == (1LL << i) - 1LL) flag = true;
    }
    if (flag) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}   