#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, P;
    cin >> N >> M >> P;
    if (N < M) cout << 0 << endl;
    else {
        cout << 1 + (N - M) / P << endl;
    }
}