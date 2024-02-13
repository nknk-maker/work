#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    bool ans = true;
    vector<char> A(7);
    A =  {'a', 't', 'c', 'o', 'd', 'e', 'r'};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            if (t[i] == '@') swap(s[i], t[i]);
            if (s[i] == '@' && find(A.begin(), A.end(), t[i]) != A.end()) continue;
            ans = false;
        }
    }
    if (ans) cout << "You can win" << endl;
    else cout << "You will lose" << endl;
    return 0;
}