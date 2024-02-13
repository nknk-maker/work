#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    int A, B;
    cin >> A >> B;
    if (A < B) swap(A, B);
    cout << gcd(A, B) << endl;
}