#include <bits/stdc++.h>
using namespace std;
    long long Ndevj[10];
    void solve(int i) {
        for (int j = 1; j <= 9; j++) {
            if (Ndevj[j] != -1) {
                if (i % Ndevj[j] == 0) {
                    cout << to_string(j);
                    return;
                }
            }
        }
        cout << '-' ;
    }
int main() {
    long long N;
    cin >> N;
    for (int i = 1; i <= 9; i++) {
        if (N % i == 0) Ndevj[i] = N / i;
        else Ndevj[i] = -1;
    }
    for (int i = 0; i <= N; i++) {
        solve(i);
    }
}