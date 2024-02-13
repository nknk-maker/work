#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> Map;
    string s;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        Map[s]++;
    }
    pair<string, int> p = make_pair("a", 0);
    for (auto itr = Map.begin(); itr != Map.end(); itr++)  {
        if (itr->second > p.second) {
            p.first = itr->first;
            p.second = itr->second;
        }
    }
    cout << p.first << endl;
}