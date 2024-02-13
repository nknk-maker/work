#include <iostream>
using namespace std;
int main() {
  long long N;
  long long A[200009], B[200009];
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];
  for (int i = 1; i <= N; i++) {
    if (abs(A[i] - B[i]) % 2 == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}