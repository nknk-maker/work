#include <bits/stdc++.h>
using namespace std;
int main() {
    //　エラトステネスのふるいで1 から sqrt(R) までの約数をふるう。1 ~ floor(sqrt(R)), L ~ Rの両方でふるう必要があるが、L ~ Rはインデックスが全て -Ｌされる。
    long long L, R;
    cin >> L >> R;
    vector<bool> divvec(floor(sqrt(R)) + 1, true);
    vector<bool> ansvec(R - L + 1, true);
    for (int i = 2; i <= sqrt(R); i++) {
        if (divvec[i]) {
            // divvecの処理
            for (int j = 2; j * i <= sqrt(R); j++) {
                divvec[i * j] = false;
            }
            // ansvecの処理
            for (long long j = L / i; j * i <= R; j++) {
                ansvec[i * j] = false;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= R - L + 1; i++ ) {
        if (ansvec[i]) {
            ans++;
            cout << i << endl;
        }
    }
    cout << ans << endl;
}