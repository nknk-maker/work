#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    pair<int, int> num[3];
    num[0] = {A, 0};
    num[1] = {B, 1};
    num[2] = {C, 2};
    sort(num, num + 3);
    int ans[3];
    for (int i = 0; i < 3; i++) ans[num[i].second] = 3 - i;
    for (int i = 0; i < 3; i++) cout << ans[i] << endl;
    return 0;
}