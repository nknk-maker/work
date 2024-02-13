#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string T;
    cin >> N;
    cin >> T;
    set<string> s = {};
    s.insert(T);
    string tmp_s;
    int T_len = T.size();
    for (int i = 0; i < T_len; i++) {
        for (int j = 97; j < 123; j++) {
            s.insert(T.substr(0, i) + char(j) + T.substr(i));
        }
    }
    for (int i = 0; i < T_len - 1; i++) {
        for (int j = 97; j < 123; j++) {
            s.insert(T.substr(0, i) + char(j) + T.substr(i + 1));
        }
    }
    for (int i = 0; i < T_len - 1; i++) {
        s.insert(T.substr(0, i) + T.substr(i + 1));
    }
    s.insert(T.substr(0, T_len - 1));
    vector<int> ans;
    string S;
    for (int i = 0; i < N; i++) {
        cin.ignore();
        cin >> S;
        if (s.find(S) != s.end()) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i << ' ';
    }

}