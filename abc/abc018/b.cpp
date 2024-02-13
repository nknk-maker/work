#include <iostream>
#include <string>
using namespace std;

string S;
int N, l[109], r[109];
char T[109];

int main() {
    cin >> S >> N;
    for (int i = 1; i <= N; i++) cin >> l[i] >> r[i];
    for (int i = 1; i <= S.size(); i++) T[i] = S[i-1];
    for (int i = 1; i <= N; i++) {
        for (int j = l[i]; j <= (l[i] + r[i]) / 2; j++) swap(T[j], T[r[i] - (j - l[i])]);
    }
    for (int i = 1; i <= S.size(); i++) cout << T[i];
    cout << endl;
    return 0;
}