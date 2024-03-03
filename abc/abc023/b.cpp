#include <iostream>
using namespace std;

int N;
string S;

int main() {
    cin >> N >> S;
    if (N % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i <= N / 2; i++) {
        if (i % 3 == 0) {
            if (S[N/2+i] != 'b' || S[N/2-i] != 'b') {
                cout << -1 << endl;
                return 0;
            }
        }
        if (i % 3 == 1) {
            if (S[N/2-i] != 'a' || S[N/2+i] != 'c') {
                cout << -1 << endl;
                return 0;
            }
        }
        if (i % 3 == 2) {
            if (S[N/2-i] != 'c' || S[N/2+i] != 'a') {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << N / 2 << endl;
    return 0;
}