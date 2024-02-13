#include <iostream>
using namespace std;

long long N, Q;
string S;
long long L[100009], R[100009];

// ハッシュ値を計算するための変数
long long mod = 2147483647;
long long T[100009], H1[100009], H2[100009];
long long power100[100009];

// S[l, r] のハッシュ値を返す関数
long long Hash_value1(int l, int r) {
    long long val = H1[r] - (H1[l-1] * power100[r - l + 1] % mod);
    if (val < 0) val += mod;
    return val;
}

// S[l, r] の逆ハッシュ値を返す関数
long long Hash_value2(int l, int r) {
    long long val = H2[l] - (H2[r+1] * power100[r - l + 1] % mod);
    if (val < 0) val += mod;
    return val;
}

int main() {
    // 入力
    cin >> N >> Q;
    cin >> S;
    for (int i = 1; i <= Q; i++) cin >> L[i] >> R[i];

    // 文字を数値に変換
    for (int i = 1; i <= N; i++) T[i] = (S[i-1] - 'a') + 1;

    // 100 の n 条を前計算
    power100[0] = 1;
    for (int i = 1; i <= N; i++) power100[i] = 100LL * power100[i-1] % mod;

    // ハッシュ値ど逆ハッシュ値の前計算
    H1[0] = 0;
    H2[N + 1] = 0;
    for (int i = 1; i <= N; i++) {
        H1[i] = (H1[i-1] * 100LL + T[i]) % mod;
        H2[N-i+1] = (H2[N-i+2] * 100LL + T[N-i+1]) % mod;
    }

    // クエリに答える
    for (int i = 1; i <= Q; i++) {
        if ((R[i] - L[i] + 1) % 2 == 0) {
            if (Hash_value1(L[i], (L[i] + R[i] - 1) / 2) == Hash_value2((L[i] + R[i] + 1) / 2, R[i])) {
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
        if ((R[i] - L[i] + 1) % 2 == 1) {
            if (Hash_value1(L[i], (L[i] + R[i]) / 2 - 1) == Hash_value2((L[i] + R[i]) / 2 + 1, R[i])) {
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
    }
    return 0;
}