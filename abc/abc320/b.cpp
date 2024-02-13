#include <bits/stdc++.h>
using namespace std;
bool solve(string s, int start, int goal) {
    // sのi文字目からj文字目までが回文か
    for (int i = 0; i < goal - start; i++) {
        if (s[start + i] != s[goal - i]) return false;
    }
    return true;
}
int main() {
    string s;
    getline(cin, s);
    long long ans = 1;
    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (solve(s, i, j)) ans = max(ans, (long long) j - i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}