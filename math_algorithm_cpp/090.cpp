#include <bits/stdc++.h>
using namespace std;
// mの数よりもf(m)の数のほうが圧倒的に少ないため、先にf(m)を計算しておき、f(m)となるのうちm = B + f(m)となるものを加算
// fmを返す関数
long long func_m(long long m) {
    long long ret = 1;
    while (m > 0) {
        ret *= (m % 10);
        m /= 10;
    }
    return ret;
}
void makefm(vector<long long>& fm, long long m) {
    // mが10^11を超えたら終了
    if (m >= 100000000000) {
        return;
    }
    fm.push_back(func_m(m));
    // mのi桁目をmiとすると、m1 <= m2 <= m3 <=...となるように再帰呼び出しを行う
    long long last_num = m % 10; // mの最後の桁
    // mの最後の桁の数以上
    for (int i = last_num; i < 10; i++) {
        makefm(fm, m * 10 + i);
    }
}
int main() {
    long long N, B;
    cin >> N >> B;
    vector<long long> fm;
    makefm(fm, 1);
    fm.push_back(0);
    sort(fm.begin(), fm.end());
    long long ans = 0;
    for (int i = 0; i < fm.size(); i++) {
        // 前と同じなら飛ばす
        if (i != 0 && fm[i] == fm[i - 1]) continue;
        long long m = B + fm[i];
        if (1 <= m && m <= N && func_m(m) == fm[i]) ans++;
    }
    cout << ans << endl;
}