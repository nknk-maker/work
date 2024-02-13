#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int pattern = a[i];
        switch(pattern) {
            case 1 : break;
            case 2 : cnt++; break;
            case 3 : break;
            case 4 : cnt++; break;
            case 5 : cnt += 2; break;
            case 6 : cnt += 3; break;
            case 7 : break;
            case 8 : cnt++; break;
            case 9 : break;
            case 10 : cnt++; break;
        }
    }
    cout << cnt << endl;
    return 0;
}