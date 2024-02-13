#include <bits/stdc++.h>
using namespace std;
int main() {
    long long A, B;
    cin >> A >> B;
    long long ans = pow(A, B) + pow(B, A);
    cout << ans << endl;
    return 0;
}