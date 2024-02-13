#include <iostream>
#include <regex>
using namespace std;

int main() {
    string X;
    cin >> X;
    int n = X.size() - 1;
    while (n >= 0) {
        if (X[n] == 'o' || X[n] == 'k' || X[n] == 'u') n--;
        else if (X[n-1] == 'c' && X[n] == 'h') n -= 2;
        else break;
    }
    if (n < 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}