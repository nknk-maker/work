#include <bits/stdc++.h>
using namespace std;
int main() {
    // a < b ^ cか
    long long a, b, c;
    cin >> a >> b >> c;
    // b == 2の場合でも６３回目でオーバーフローする
    if (c == 1) {
        cout << "No" << endl;
    }
    else {
        long long cnt_c = 1;
        for (int i = 0; i < b; i++) {
            if (cnt_c > a / c) {
                cout << "Yes" << endl;
                return 0;
            }
            cnt_c *= c;
        }
        cout << "No" << endl;
        return 0;
    }
}