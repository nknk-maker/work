#include <iostream>
using namespace std;

int GCD(int A, int B) {
    if (B == 0) return A;
    return GCD(B, A % B);
}

int main() {
    long long A, B;
    cin >> A >> B;
    cout << A / GCD(max(A, B), min(A, B)) * B << endl;
    return 0;
}