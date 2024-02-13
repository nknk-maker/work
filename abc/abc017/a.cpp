#include <iostream>
using namespace std;

int main() {
    int s, c;
    double ans = 0;
    for (int i = 1; i <= 3; i++) {
        cin >> s >> c;
        ans += 1.0 * s * c / 10;
    }
    cout << ans << endl;
    return 0;
}