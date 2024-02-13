#include <bits/stdc++.h>
using namespace std;

long long N;

int main() {
    cin >> N;
    vector<long long> y(5);
    long long a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        y.at(a / 100) ++;
    }
    cout << y[1] * y[4] + y[2] * y[3] << endl;
}