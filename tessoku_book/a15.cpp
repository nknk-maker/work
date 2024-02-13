#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 入力
    int N, A[100009], B[100009];
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // 配列Tの作成
    vector<int> T;
    for (int i = 1; i <= N; i++) T.push_back(A[i]);
    sort(T.begin(), T.end());

    // 配列Tの重複を消す
    // erase 関数、unique 関数を使う
    T.erase(unique(T.begin(), T.end()), T.end());

    // 答えを求める
    for (int i = 1; i <= N; i++) {
        // vector 型の lowwer_bound を使う
        // vector 型の展示は0 番目からなので１を足す
        B[i] = lower_bound(T.begin(), T.end(), A[i]) - T.begin();
        B[i]++;
    }

    // 答えは空白区切りで出力
    for (int i = 1; i <= N; i++) {
        if (i >= 2) cout << " ";
        cout << B[i];
    }
    cout << endl;
    return 0;
}