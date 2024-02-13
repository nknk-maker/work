#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S, T = "";
    cin >> N >> S;
    N = S.size();
    vector<int> A;
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') {
            A.push_back(T.size());
            T.push_back(S[i]);
        }
        else if (S[i] == ')') {
            if (A.empty()) {
                T.push_back(')');
                continue;
            }
            //cout  << i << ' ' << T << endl;
            int end = T.size() - 1;
            //cout << A[A.size() - 1] << ' ' << end << endl;
            for (int j = A[A.size() - 1]; j <= end; j++) {
                T.pop_back();
            }
            //cout << T << endl;
            A.pop_back();
        }
        else T.push_back(S[i]);
    }
    cout << T << endl;
}