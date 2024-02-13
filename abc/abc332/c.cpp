#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    string s;
    cin >> N >> M >> s;
    int ans = 0;
    int tmp = 0;
    int logo = 0, muzi = M;
    for (int i = 0; i < N; i++) {
        if (s[i] == '2') tmp++;
        if (s[i] == '1') {
            if (muzi == 0) tmp++;
            else muzi--;
        }
        if (s[i] == '0') {
            muzi = M;
            ans = max(ans, tmp);
            tmp = 0;
        }
    }
    ans = max(ans, tmp);
    cout << ans << endl;
    return 0;
}