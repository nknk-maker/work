#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    for (char x : s) {
        if (x == 'a') continue;
        if (x == 'i') continue;
        if (x == 'u') continue;
        if (x == 'e') continue;
        if (x == 'o') continue;
        cout << x;
    }
    cout << endl;
}