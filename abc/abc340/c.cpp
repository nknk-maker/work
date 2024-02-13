#include <iostream>
using namespace std;

long long N;

int main() {
    cin >> N;
    long long ans = 0;
    long long pos = 2, i = 1;
    while (i * 2< N) {
        ans += pos * i;
        i *= 2;
        pos++;
    }
    ans += (N - i) * pos;
    cout << ans << endl;
    return 0;
}