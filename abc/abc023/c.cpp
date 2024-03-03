// 足す回数を考える問題。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, K, N;

int main() {
    cin >> R >> C >> K >> N;
    vector<int> r(N), c(N), line(R), colum(C);
    for (int i = 0; i < N; i++) cin >> r[i] >> c[i];
    for (int i = 0; i < N; i++) {line[r[i]-1]++; colum[c[i]-1]++;}
    sort(line.begin(), line.end());
    sort(colum.begin(), colum.end());
    long long ans = 0;
    for (int i = 0; i <= K; i++) {
        int width = (upper_bound(line.begin(), line.end(), i) - line.begin()) - (lower_bound(line.begin(), line.end(), i) - line.begin());
        int height = (upper_bound(colum.begin(), colum.end(), K-i) - colum.begin()) - (lower_bound(colum.begin(), colum.end(), K-i) - colum.begin());
        ans += width * height;
    }
    cout << ans << endl;
    return 0;
}