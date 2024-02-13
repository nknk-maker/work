#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    int N, X;
    string A;
    cin >> N >> X >> A;
    queue<int> q;
    q.push(X-1);
    while (!q.empty()) {
        int pos = q.front();
        A[pos] = '@';
        q.pop();
        if (pos > 0 && A[pos-1] == '.') q.push(pos-1);
        if (pos < N-1 && A[pos+1] == '.') q.push(pos+1);
    }
    cout << A << endl;
    return 0;
}