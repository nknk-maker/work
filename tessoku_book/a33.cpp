#include <iostream>
using namespace std;

int N, A[100009];

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // ニム和を求める
    int XOR_sum = A[1];
    for (int i = 2; i <= N; i++) XOR_sum = (XOR_sum ^ A[i]);

    // 出力
    if (XOR_sum != 0) cout << "First" << endl;
    if (XOR_sum == 0) cout << "Second" << endl;
    return 0;
}