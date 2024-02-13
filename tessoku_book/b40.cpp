#include <iostream>
using namespace std;

int main() {
    int N, A[200009];
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    long long hundmod[100];
    long long ans = 0;
    for (int i = 1; i <= N; i++) hundmod[A[i] % 100]++;
    ans += hundmod[0] * (hundmod[0] - 1) / 2;
    for (int i = 1; i <= 49; i++) {
        ans += hundmod[i] * hundmod[100-i];
    }
    ans += hundmod[50] * (hundmod[50]-1) / 2;
    cout << ans << endl;
    return 0;
}