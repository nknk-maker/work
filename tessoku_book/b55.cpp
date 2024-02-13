#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q, QueryType[100009], x[100009];
    cin >> Q;
    set<int> S;
    for (int i = 1; i <= Q; i++) cin >> QueryType[i] >> x[i];
    for (int i = 1; i <= Q; i++) {
        if (QueryType[i] == 1) S.insert(x[i]);
        if (QueryType[i] == 2) {
            auto itr1 = S.lower_bound(x[i]);
            if (itr1 == S.end()) {
                if (itr1 == S.begin()) cout << -1 << endl;
                else {
                    itr1--;
                    cout << abs(x[i] - *itr1) << endl;
                }
            }
            else {
                if (itr1 == S.begin()) cout << abs(x[i] - *itr1) << endl;
                else {
                    auto itr2 = itr1;
                    itr2--;
                    int ans1 = abs(x[i] - *itr1);
                    int ans2 = abs(x[i] - *itr2);
                    cout << min(ans1, ans2) << endl;
                } 
            }
        }
    }
    return 0;
}