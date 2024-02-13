#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    while (S[0] == 'A') S.erase(S.begin());

    while (S[0] == 'B') S.erase(S.begin());

    while (S[0] == 'C') S.erase(S.begin());
    if (S.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}