#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 1 && s[i] != '0') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}