#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    N %= 4;
    if (N == 0) cout << 6 << endl;
    if (N == 1) cout << 2 << endl;
    if (N == 2) cout << 4 << endl;
    if (N == 3) cout << 8 << endl;
    return 0;
}