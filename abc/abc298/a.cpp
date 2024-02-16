#include <iostream>
using namespace std;

int main() {
    int N; string S;
    cin >> N >> S;
    bool joken1 = false, joken2 = true;
    for (char c : S) {
        if (c == 'o') joken1 = true;
        if (c == 'x') joken2 = false;
    }
    if (joken1 && joken2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
