#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b > a) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcs(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    long long N;
    cin >> N;
    int div[3];
    div[0] = 3;
    div[1] = 5;
    div[2] = 7;
    long long ans = 0;
    for (int i = 1; i < (1LL << 3); i++) {
        int LCS = 1;
        bool flag = false;
        for (int j = 0; j < 3; j++) {
            if (i & (1LL << j)) {LCS = lcs(LCS, div[j]); flag = 1 - flag;}
        }
        if (flag) ans += N / LCS;
        else ans -= N / LCS;
    }
    cout << ans << endl;
    return 0;
}