#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    set<int> S;
    vector<int> v;
    int a;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a;
        S.insert(a);
    }
    for (auto itr = S.begin(); itr != S.end(); itr++) {
        v.push_back(*itr);
    }
    sort(v.begin(), v.end());
    cout << v[v.size() - 2] << endl;
    return 0;
}