#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second >= b.second;
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(M);
    vector<long long> score(N,0);
    for (int i = 0; i < N; i++) score[i] += i + 1;
    for (int i = 0; i < M; i++) cin >> A[i];
    vector<vector<pair<int,int>>> yet_solve(N);
    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;
            if (c == 'x') yet_solve[i].push_back(make_pair(j, A[j]));
            else {
                score[i] += A[j];
            }
        }
        sort(yet_solve[i].begin(), yet_solve[i].end(), cmp);
    }
    int MAX = *max_element(score.begin(), score.end());
    for (int i = 0; i < N; i++) {
        long long tmp = score[i];
        if (score[i] == MAX) cout << 0 << endl;
        else {
            for (int j = 0; j < yet_solve.size(); j++) {
                tmp += yet_solve[i][j].second;
                if (tmp > MAX) {
                    cout << j + 1<< endl;
                    break;
                } 
            }
        }
    }
}