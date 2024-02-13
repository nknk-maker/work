#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;
    vector<int> h(N);
    for (int i = 0; i < N; i++) h[i] = 1;
    for (int i = 1; i < N; i++) {
        if (s[i-1] == 'A') h[i] = max(h[i], h[i-1] + 1);
    }
    for (int i = N-2; i >= 0; i--) {
        if (s[i] == 'B') h[i] = max(h[i], h[i+1] + 1);
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += h[i];
    }
    cout << ans << endl;
    return 0;
}