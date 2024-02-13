#include <iostream>
using namespace std;

int main() {
    int N, H, W;
    int A[100009], B[100009];
    cin >> N >> H >> W;
    for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];
    int xor_sum = (A[1]-1) ^ (B[1]-1);
    for (int i = 2; i <= N; i++) xor_sum = ((A[i]-1) ^ (B[i]-1)) ^ xor_sum;
    if (xor_sum == 0) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}