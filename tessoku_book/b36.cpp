#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == '1') sum++;
    }
    if ((sum & 1) == (K & 1)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}