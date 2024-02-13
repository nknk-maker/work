#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    if (S[0] < 'A' || 'Z' < S[0]) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i < S.size(); i++) {
        if (S[i] < 'a' || 'z' < S[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}