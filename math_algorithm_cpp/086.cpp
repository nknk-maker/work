#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    long long depth = 0;
    char s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s == '(') depth++;
        else depth--;
        if (depth < 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}