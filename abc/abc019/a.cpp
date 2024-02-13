#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int old[3];
    cin >> old[0] >> old[1] >> old[2];
    sort(old, old + 3);
    cout << old[1] << endl;
    return 0;
}