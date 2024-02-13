#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> ans;
    for (int b = 0; b < 10; b++) {
        if (N & (1 << b)) ans.push_back(1<<b);
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << endl;
    return 0;
}