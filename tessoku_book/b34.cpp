#include <iostream>
using namespace std;

int main() {
    int mod[5] = {0, 0, 1, 1, 2};
    int grundy[100009];
    int N, X, Y;
    long long A[100009];
    cin >> N >> X >> Y;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) grundy[i] = mod[A[i] % 5];
    int XOR_sum = 0;
    for (int i = 1; i <= N; i++) XOR_sum = (XOR_sum ^ grundy[i]);
    if (XOR_sum == 0) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}