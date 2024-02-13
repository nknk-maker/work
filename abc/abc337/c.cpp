#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[300009];
    bool B[300009];
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) B[A[i]] = true;
    int last;
    for (int i = 1; i <= N; i++) {
        if (!B[i]) last = i;
    }

    int pos = last;
    vector<int> ans;
    while (pos != -1) {
        ans.push_back(pos);
        pos = A[pos];
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < N; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}