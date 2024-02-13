#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long A[250009], B[250009];
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 2; i <= N; i++) cin >> B[i];
    long long first = 0;
    for (int i = 2; i <= N; i++) A[B[i]] += A[i];

    for (int i = 1; i <= N; i++) first += A[i];
    for (int i = 0; i < N / 2; i++) {
    for (int i = 2; i <= N; i++) A[B[i]] += A[i];
    }
    long long second = 0;
    for (int i = 1; i <= N; i++) second += A[i];
    if (first > second) cout << "-" << endl;
    else if (first < second) cout << "+" << endl;
    else if (A[1] > 0) cout << "+" << endl;
    else if (A[1] < 0) cout << "-" << endl;
    else cout << 0 << endl;
    return 0;
}