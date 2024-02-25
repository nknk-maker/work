#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> G[100009]; // adjacency list

int main() {
    // in
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]); // add B[i] as a vertex adjacent to vertex A[i]
        G[B[i]].push_back(A[i]); // add A[i] as a vertex adjacent to vertex B[i]
    }

    // out
    for (int i = 1; i <= N; i++) {
        cout << i << ": {";
        for (int j = 0; j < G[i].size(); j++) {
            if (j >= 1) cout << ", ";
            cout << G[i][j];
        }
        cout << "}" << endl;
    }
    return 0;
}

