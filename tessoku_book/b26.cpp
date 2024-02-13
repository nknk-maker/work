#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    bool isPrime[N + 1];
    for (int i = 1; i <= N; i++) isPrime[i] = true;
    isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= N; j += i) isPrime[j] = false;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (isPrime[i]) cout << i << endl;
    }
    return 0;
}