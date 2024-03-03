#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool check(string s) {
    for (int i = 0; i <= s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

int main() {
    long long N;
    cin >> N;
    vector<long long> vec;
    for (long long i = 1; i <= 1000000; i++) {
        if (check(to_string(i * i * i))) vec.push_back(i * i * i);
    }
    int itr = upper_bound(vec.begin(), vec.end(), N) - vec.begin();
    cout << vec[itr - 1] << endl;
    return 0;
}