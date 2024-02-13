#include <iostream>
using namespace std;

// x が素数かどうか
bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    // 入力
    int Q, X[10009];
    cin >> Q;
    for (int i = 1; i <= Q; i++) cin >> X[i];

    // 出力
    for (int i = 1; i <= Q; i++) {
        if (isPrime(X[i])) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}