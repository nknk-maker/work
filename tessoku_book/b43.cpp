#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M + 1);
    for (int i = 1; i <= M; i++) cin >> A[i];

    vector<int> WA(N + 1);
    for (int i = 1; i <= M; i++) WA[A[i]]++;

    for (int i = 1; i <= N; i++) cout << M - WA[i] << endl;
    return 0;
}