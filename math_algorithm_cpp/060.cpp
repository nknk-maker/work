#include <bits/stdc++.h>
using namespace std;
// N = 1, 2, 3 -> 先手必勝、N = 4 ->　先手必敗、N = 5, 6, 7 -> 先手必勝
// N % 4 == 0 -> 先手必敗、else 先手必勝
int main() {
    long long N;
    cin >> N;
    if (N % 4 == 0) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}