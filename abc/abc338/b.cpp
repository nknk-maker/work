#include <iostream>
#include <map>
using namespace std;
int main() {
    string S;
    cin >> S;
    map<char, int> m;
    for (char c : S) {
        m[c]++;
    }
    pair<char, int> ans = {'a', 0};
    for (auto i = m.begin(); i != m.end(); i++) {
        if (ans.second < i->second) {
            ans = make_pair(i->first, i->second);
        }
    }
    cout << ans.first << endl;
    return 0;
}