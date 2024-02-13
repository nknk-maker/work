#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int N;
    int A[100009];
    map<int, long long> m;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) {
        m[A[i]]++;
    }
    long long ans = 0;
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        ans += itr->second * (itr->second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}