#include <bits/stdc++.h>
using namespace std;

long long a[200009], b[200009];
int N, M;
long long ans = 0;

void imos(int start, int end) {
    int dis = (max(start, end) - min(start, end));
    dis = min(dis, N - dis);
    int add = N - 2 * dis;
    if (start < end) {
        a[start] += add;
        a[end] -= add;
    }
    else {
        a[start] += add;
        a[N + 1] -= add;
        a[1] += add;
        a[end] -= add;
    }
}

int main() {
    cin >> N >> M;
    vector<int> X(M + 1);
    vector<pair<int, int>> path(M);
    for (int i = 1; i <= M; i++) cin >> X[i];
    for (int i = 1; i < M; i++) path[i] = make_pair(X[i], X[i + 1]);
    for (int i = 1; i < M; i++) {
        if (path[i].first > path[i].second) swap(path[i].first, path[i].second);
    }
    for (int i = 1; i < M; i++) ans += min(path[i].second - path[i].first, N - path[i].second + path[i].first);
    for (int i = 1; i < M; i++) {
        if (path[i].second - path[i].first > N / 2) swap(path[i].first, path[i].second);
    }
    for (int i = 1; i < M; i++) imos(path[i].first, path[i].second);
    b[0] = 0;
    for (int i = 1; i <= N + 1; i++) b[i] = b[i-1] + a[i];
    sort(b + 1, b + N + 1);
    cout << ans + b[1] << endl;
    return 0;
}