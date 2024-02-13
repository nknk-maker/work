#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<long long> a(100009), b(100009), C(1000009), D(1000009);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++) {
        C[a[i]]++;
        C[b[i] + 1]--;
    }
    D[0] = C[0];
    for (int i = 1; i <= 1000000; i++) {
        D[i] = D[i-1] + C[i];
    }
    sort(D.begin(), D.end(), greater<long long>());
    cout << D[0] << endl;
    return 0;
}