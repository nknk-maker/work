#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    stack<int> S;
    cin >> s;
    vector<pair<int, int>> ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') S.push(i + 1);
        else {
            int l = S.top();
            S.pop();
            ans.push_back(make_pair(l, i + 1));
        }
    }

    for (int i = 0; i < s.size() / 2; i++) {
        cout << ans[i].first <<' ' <<  ans[i].second << endl;
    }
    return 0;
}