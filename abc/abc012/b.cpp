#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int s, min, h;
    s = N % 60;
    N /= 60;
    min = N % 60;
    N /= 60;
    h = N;
    printf("%02d:%02d:%02d\n", h, min, s);
    return 0;
}