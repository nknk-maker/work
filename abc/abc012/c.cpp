#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) sum += i * j;
    }
    int N;
    cin >> N;
    int n = sum - N;
    for (int i = 1; i <= 9; i++) {
        if (n % i == 0 && n / i <= 9) {
            cout << i << " x " << n / i << endl;
        }
    }
    return 0;
}