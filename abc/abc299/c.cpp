#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    int left = -1;
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == '-') {
            len = max(len, i - left);
            left = i;
        }
    }
    len = max(len, n - left);
    if (find(s.begin(), s.end(), 'o') == s.end() | find(s.begin(), s.end(), '-') == s.end()) {
        cout << -1 << endl;
        return 0;
    }
    cout << len  - 1 << endl;
    return 0;
}