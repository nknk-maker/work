#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long A[200009], B[200009];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) B[i] = B[i-1] + A[i];
    long long MIN  = 1000000000;
    for (int i = 1; i <= N; i++) MIN = min(MIN, B[i]);
    if (MIN < 0) cout << B[N] + abs(MIN) << endl;
    else cout << B[N] << endl;
    return 0;
}