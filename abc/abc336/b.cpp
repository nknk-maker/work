#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int ctz = 0;
    while (true) {
        if ((N & (1 << ctz))) break;
        ctz++;
    }
    cout << ctz << endl;
    return 0;
}