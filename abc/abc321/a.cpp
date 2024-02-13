#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    long long last_num = -1;
    while (N != 0) {
        if (N % 10 <= last_num) {
            cout << "No" << endl;
            return 0;
        }
        last_num = N % 10;
        N /= 10;
    }
    cout << "Yes" << endl;
}