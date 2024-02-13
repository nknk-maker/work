#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    for (int i = 0; i < n - 2; i++) {
        if (s.at(i) == '|') {
            for (int j = i + 1; j < n; j++) {
                if (s.at(j) == '|') {
                    for (int k = 0; k < n; k++) {
                        if (s.at(k) == '*') {
                            if (i < k && k < j) {
                                cout << "in" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "out" << endl;
    return 0;
}