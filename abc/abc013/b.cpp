#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << min(abs(a - b), a < b ? a + 1 + 9 - b : 9 - a + 1 + b) << endl;
    return 0;
}