#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, X, Y;
    cin >> N >> X >> Y;
    if (N % 2 == (X + Y) % 2 && N >= abs(X) + abs(Y)) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}