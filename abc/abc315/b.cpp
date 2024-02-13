#include <bits/stdc++.h>
using namespace std;
int main() {
    long long m;
    cin >> m;
    vector<int> d(m);
    for (int i = 0; i < m; i++) cin >> d.at(i);
    long long sum_day = accumulate(d.begin(), d.end(), 0);
    sum_day++;
    sum_day /= 2;
    int i = 0;
    while (sum_day > d.at(i)) {
        sum_day -= d.at(i);
        i++;
    }
    cout << i + 1 << ' ' << sum_day << endl;
    
}