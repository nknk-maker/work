#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int young = 0, adult = 0, old = 0;
    if (M & 1) {N--; M -= 3; old++;};
    if (2 * N <= M && M <= 4 * N) {
        int young = (M - 2 * N) / 2;
        int adult = (4 * N - M) / 2;
        cout << adult << ' ' << old << ' ' << young << endl;
    }
    else cout << "-1 -1 -1" << endl;
    return 0;
}