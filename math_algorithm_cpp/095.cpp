#include <bits/stdc++.h>
using namespace std;
int main() {
    //　エラトステネスのふるいで1 から sqrt(R) までの約数をふるう。1 ~ floor(sqrt(R)), L ~ Rの両方でふるう必要があるが、L ~ Rはインデックスが全て -Ｌされる。
    long long L, R;
    cin >> L >> R;
    vector<bool> divvec(floor(sqrt(R)) + 1);
    vector<bool> ansvec(R - L + 1);
    for (int i = 2; i <= sqrt(R); i++) {
        if (divvec[i]) {
            // divvecの処理
            for (int j = 2; j * i <= sqrt(R); j++) {
                divvec[i * j] = true;
            }
            // ansvecの処理
            for (long long j = L; j * i <= R; j++) {
                ansvec[i * j] = true;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= R - L + 1; i++ ) {
        if (ansvec[i]) ans++;
    }
    cout << ans << endl;
}