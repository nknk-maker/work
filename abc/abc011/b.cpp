#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s[0] > 'Z') {
        cout << char ('A' + s[0] - 'a');
    }
    else cout << s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] <= 'Z') {
            cout << char ('a' + s[i] - 'A');
        }
        else cout << s[i];
    }
    cout << endl;
    return 0;
}

