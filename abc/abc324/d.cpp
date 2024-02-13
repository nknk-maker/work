#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    sort(S.begin(), S.end()); // Sをソートしておく

    long long max_value = pow(10, N); // Sを並び替えた値は必ず10^N以下

    int ans = 0;
    // 0 < i < sart(10 ^ N)で、i * iをSを並び替えることで作れるかどうかを全探索、Sを並び替えてi * iが作れる == どの文字cについても、
    // i * iにcが含まれる個数 = Sにcが含まれる個数、後はsortして確認する
    for (long i = 0; i * i < max_value; i++) {
        string T = to_string(i * i);
        T.resize(N, '0'); //桁数をそろえる
        sort(T.begin(), T.end());
        if (S == T) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}