#include <iostream>
using namespace std;

long long mpow(long long a, long long b) {
    long long p = a, ret = 1;
    for (int i = 0; i < 6; i++) {
        if (b & (1LL << i)) ret *= p;
        p *= p;
    }
    return ret;
}

int main() {
    long long N;
    cin >> N;
    long long ans = 0;
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 9; j++) {
            ans += ((N / mpow(10, i)) * mpow(10, i-1) + min(mpow(10, i-1), max(N % mpow(10, i) - j * mpow(10, i-1) + 1, 0LL))) * j;
        }
    }
    cout << ans << endl;
    return 0;
}