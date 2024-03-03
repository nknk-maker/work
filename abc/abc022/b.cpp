#include <iostream>
#include <set>
using namespace std;

set<int> S;
int N, A[100009];

int main() {
    int ans = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) {
        auto itr = S.lower_bound(A[i]);
        if (itr == S.end()) S.insert(A[i]);
        else if (*itr != A[i]) S.insert(A[i]);
        else ans++; 
    }
    cout << ans << endl;
    return 0;
}