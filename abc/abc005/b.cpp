#include <iostream>
using namespace std;

int main() {
    int N;
    int T[109];
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> T[i];
    int ans = 109;
    for (int i = 1; i <= N; i++) ans = min(ans, T[i]);
    cout << ans << endl;
    return 0;
}