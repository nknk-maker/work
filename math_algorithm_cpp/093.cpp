#include <bits/stdc++.h>
using namespace std;
long long gcd(long a, long long b) {
    if (b == 0) return a;
    return gcd(b , a % b);
}
long long lcm(long long a, long long b) {
    if (a < b) swap(a, b);
    return a / gcd(a, b) * b;
}
int main() {
    long long A, B;
    cin >> A >> B;
    if (log10(A) + log10(B) - log10(gcd(A, B)) > 18) {
        cout << "Large" << endl;
        return 0;
    }
    long long LCM = lcm(A, B);
    if (LCM > 1000000000000000000) {
        cout << "Large" << endl;
    }
    else cout << LCM << endl;
    return 0;
}