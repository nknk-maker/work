#include <bits/stdc++.h>
using namespace std;
long long N;
bool isprime(long long N) {
    for (int i = 2; 1LL * i * i <= N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}
int main() {
    cin >> N;
    if (isprime(N)) cout << "Yes" << endl;
    else cout << "No" << endl;
}