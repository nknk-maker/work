#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, M;
    cin >> N >> M;
    string s, t;
    cin.ignore();
    getline(cin, s);
    getline(cin, t);
    bool flag1 = true, flag2 = true;
    for (int i = 0; i < N; i++) {
        if (s[i] != t[i]) flag1 = false;
    }
    for (int i = 0; i < N; i++) {
        if (s[N-i-1] != t[M-i-1]) flag2 = false;
    }
    if (flag1 && flag2) cout << 0 << endl;
    else if (!(flag1 || flag2)) cout << 3 << endl;
    else if (flag1) cout << 1 << endl;
    else cout << 2 << endl;
}