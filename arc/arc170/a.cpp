#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T; S = " " + S; T = " " + T;
    // 一致させられるかどうかを判断
    for (int i = 1; i <= N; i++) {
        if (S[i] == T[i] && S[i] == 'B') continue;
        else if (S[i] == 'A' && T[i] == 'B') {
            cout << -1 << endl;
            return 0;
        }
        else break;
    }
    for (int i = N; i > 0; i--) {
        if (S[i] == T[i] && S[i] == 'A') continue;
        else if (S[i] == 'B' && T[i] == 'A') {
            cout << -1 << endl;
            return 0;
        }
        else break;
    }
    set<int> A, B; // A : BをAにする、B：AをBにする
    for (int i = 1; i <= N; i++) {
        if (S[i] == 'B' && T[i] == 'A') A.insert(i);
        else if (S[i] == 'A' && T[i] == 'B') B.insert(i);
    }
    // にぶたん
    int cnt = 0;
    vector<int> sakujo_A, sakujo_B;
    for (auto itl = A.begin(); itl != A.end(); itl++) {
        auto itr = B.lower_bound(*itl);
        if (itr == B.end()) continue;
        else {
            sakujo_A.push_back(*itl);
            B.erase(*itr);
            cnt++;
        }
    }
    for (int i = 0; i < sakujo_A.size(); i++) {
        A.erase(sakujo_A[i]);
    }

    cout << cnt + A.size() + B.size() << endl;
    return 0;
}