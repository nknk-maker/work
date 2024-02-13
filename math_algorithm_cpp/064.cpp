#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, K;
    cin >> N >> K;
    long long a_sum = 0;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        a_sum += a;
    }
    if (abs(a_sum) <= K && a_sum % 2 == K % 2) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}