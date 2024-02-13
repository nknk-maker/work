#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int fib[3];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 3; i <= N; i++) {
        fib[2] = (fib[0] + fib[1]) % 1000000007;
        fib[0] = fib[1];
        fib[1] = fib[2];
    }
    cout << fib[2] << endl;
    return 0;
}