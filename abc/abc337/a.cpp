#include <iostream>
using namespace std;

int main() {
    int N, X[109], Y[109], x = 0, y = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
    for (int i = 1; i <= N; i++) {x += X[i]; y += Y[i];}
    if (x > y) cout << "Takahashi" << endl;
    else if (x < y) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    return 0;
}