#include <bits/stdc++.h>
using namespace std;
long long N;
int gcd(int a, int b) {
    if (b == 0) return a;
    if (b > a) swap(a, b);
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
int main() {
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    long long lc = lcm(a.at(0), a.at(1));
    for (int i = 2; i < N; i++) {
        lc = lcm(lc, a.at(i));
    }
    cout << lc << endl;
}