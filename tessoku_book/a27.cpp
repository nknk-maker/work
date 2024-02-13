#include <iostream>
using namespace std;

int GCD(int A, int B) {
    if (B == 0) return A;
    return GCD(B, A % B);
}

int main() {
    int A, B;
    cin >> A >> B;
    cout << GCD(max(A, B), min(A, B)) << endl;
    return 0;
}