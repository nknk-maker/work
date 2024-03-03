#include <iostream>
using namespace std;

int main() {
    int A, B, C, K;
    int S, T;

    // in
    cin >> A >> B >> C >> K >> S >> T;

    // seek answer
    long long ans = A * S + B * T;
    if (S + T >= K) ans -= C * (S + T);

    // out
    cout << ans << endl;
    return 0;
}