#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    N--;
    vector<int> s;
    while (N > 0) {
        s.push_back(((N % 5) * 2));
        N = N / 5;
    }
    reverse(s.begin(), s.end());
    if (s.size() == 0) cout << 0 << endl;
    else {for (int i = 0; i < s.size(); i++) cout << s[i];
    cout << endl;}
    return 0;
}