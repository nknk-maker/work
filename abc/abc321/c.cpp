#include <bits/stdc++.h>
using namespace std;
void make_K(long long n, vector<long long>& k) {
    int last_num = n % 10;
    k.push_back(n);
    for (int i = 0; i < last_num; i++) {
        make_K(n * 10 + i, k);
    }
}
int main() {
    vector<long long> k;
    for (int i = 1; i <= 9; i++) make_K(i, k);
    sort(k.begin(), k.end());
    long long x;
    cin >> x;
    cout << k.size() << endl;
    cout << k[x - 1] << endl;
}