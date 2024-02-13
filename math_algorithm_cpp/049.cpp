#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    long long mod = 1000000007;
    cin >> N;
    vector<long long> a(N + 1);
    a[1] = 1;
    a[2] = 1;
    for (int i = 3; i <= N; i++ ){
        a[i] = a[i - 1] + a[i - 2];
        a[i] %= mod;
    }
    cout << a[N] << endl;
}