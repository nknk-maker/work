#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, D, X[200009], Y[200009];
    cin >> N >> D;
    for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
    long long ans = 0;
    for (int d = 1; d <= D; d++) {
        int id = 0;
        for (int i = 1; i <= N; i++) {
            if (d >= X[i]) {
                if (Y[i] > Y[id]) id = i;
            }
        }
        ans += Y[id];
        Y[id] = 0;
    }
    cout << ans << endl;
    return 0;
}