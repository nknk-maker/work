#include <iostream>
#include <vector>
using namespace std;

int Q, querytype[109], query2[109], sizeA = 0;

int main() {
    cin >> Q;
    vector<int> A;
    for (int i = 1; i <= Q; i++ ) cin >> querytype[i] >> query2[i];
    for (int i = 1; i <= Q; i++) {
        if (querytype[i] == 1) {A.push_back(query2[i]); sizeA++;}
        else cout << A[sizeA - query2[i]] << endl;
    }
    return 0;
}