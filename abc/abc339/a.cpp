#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;

int main() {
    cin >> s;
    int size = s.size() - 1;
    while (size >= 0) {
        if (s[size] == '.') break;
        t.push_back(s[size]);
        size--;
    }
    reverse(t.begin(), t.end());
    cout << t << endl;
    return 0;
}