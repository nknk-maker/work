#include <iostream>
using namespace std;

int main() {
    // 入力
    int N; char S[200009];
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> S[i];

    // 答えを求める
    bool Answer = false;
    for (int i = 1; i <= N - 2; i++) {
        if (S[i] == S[i+1] && S[i+1] == S[i+2]) Answer = true;
    }

    // 出力
    if (Answer) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}