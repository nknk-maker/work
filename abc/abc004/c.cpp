#include <iostream>
using namespace std;

int main() {
    int N;
    int cards[6] = {1, 2, 3, 4, 5, 6};
    cin >> N;
    N %= 30;
    for (int i = 0; i < N; i++) {
        swap(cards[i % 5], cards[i % 5 + 1]);
    }
    for (int i = 0; i < 6; i++) cout << cards[i];
    cout << endl;
    return 0;
}