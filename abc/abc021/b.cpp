#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, a, b, K;
    cin >> N >> a >> b >> K;
    vector<int> P(K);
    for (int i = 0; i < K; i++) cin >> P[i];
    P.push_back(a);
    P.push_back(b);
    sort(P.begin(), P.end());
    int size1 = P.size();
    P.erase(unique(P.begin(), P.end()), P.end());
    int size2 = P.size();
    if (size1 == size2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}