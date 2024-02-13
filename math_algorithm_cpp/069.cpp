#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<long long> ans = {a * c, a * d, b * c, b * d};
    cout << *max_element(ans.begin(), ans.end()) << endl;
}