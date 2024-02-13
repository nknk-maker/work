#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

string s;
vector<pair<char, int>> ans;

int main() {
    cin >> s;
    int pos = 0;
    ans.push_back({s[0], 1});
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ans[pos].first) ans[pos].second++;
        else {
            ans.push_back({s[i], 1});
            pos++;
        }
    }
    for (int i = 0; i <= pos; i++) cout << ans[i].first << ans[i].second;
    cout << endl;
    return 0;
}