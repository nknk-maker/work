#include <bits/stdc++.h>
using namespace std;
int main() {
    long long H, W;
    cin >> H >> W;
    vector<long long> line(H);
    vector<long long> col(W);
    vector<vector<long long>> a(H, vector<long long> (W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
            line[i] += a[i][j];
            col[j] += a[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            long long n;
            n = line[i] + col[j] - a[i][j];
            cout << n << ' ';
        }
        cout << endl;
    }
}