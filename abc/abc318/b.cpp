#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<bool>> v(101, vector<bool> (101, false));
    int N;
    cin >> N;
    int a, b, c, d;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c >> d;
        for (int i = a; i < b; i++) {
            for (int j = c; j < d; j++) {
                v[i][j] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (v[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}