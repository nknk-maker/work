#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[i][j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] == 1) cout << j + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}