#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    cout << (s.size() > t.size() ? s : t) << endl;
    return 0;
}