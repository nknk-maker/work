#include <bits/stdc++.h>
using namespace std;
long long N;

void eratoth(long long N, vector<bool>& v) {
    for (int i = 2; i * i <= N; i++) {
        if (v.at(i)) {
            for (int j = 2; i * j <= N; j++) {
                v.at(i * j) = false;
            }
        }
    }
}

int main() {
    cin >> N;
    vector<bool> v(N + 1, true);
    eratoth(N, v);
    for (int i = 2; i <= N; i++) {
        if (v.at(i)) {
            cout << i << endl;
        }
    }
}