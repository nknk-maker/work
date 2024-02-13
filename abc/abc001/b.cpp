#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    if (m < 100) cout << "00" << endl;
    else if (100 <= m && m <= 5000) printf("%02d\n", m / 100);
    else if (6000 <= m && m <= 30000) printf("%02d\n",  m / 1000 + 50);
    else if (35000 <= m && m <= 70000) printf("%2d\n", (m / 1000 - 30) / 5 + 80);
    else if (m > 70000) cout << 89 << endl;
    return 0;
}