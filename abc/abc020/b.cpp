#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    string C = A + B;
    long long ans = stoi(C);
    cout << ans * 2 << endl;
    return 0;
}