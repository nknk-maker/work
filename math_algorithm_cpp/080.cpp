#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 60);

// 辺の情報
struct Edge{
    // 行先
    int to;
    // コスト
    int cost;
};

using Graph = vector<vector<Edge>>;
// {distance, from}
using Pair = pair<long long, int>;

// dijkstra法
//distancees は頂点数と同じサイズ、全要素INFで初期化しておく
void dijkstra(const Graph& graph, vector<long long>& distances, int startIndex) {

    // "現地店での最短距離、頂点"の順に取り出すpriority_queue
    // デフォルトでは降順であるため、greaterを使う
    priority_queue<Pair, vector<Pair>, greater<Pair>> Q;
    Q.emplace((distances[startIndex]), startIndex);

    while (!Q.empty()) {
        const long long distance = Q.top().first;
        const int pos = Q.top().second;
        Q.pop();

        // 最短経路でなければ処理しない
        if (distances[pos] < distance) {
            continue;
        }

        // 現在の頂点からの各辺について
        for (const Edge& edge : graph[pos]) {
            // to までの新しい距離
            const long long d = (distances[pos] + edge.cost);
            // d が現在の記録よりも小さければ更新
            if (d < distances[edge.to]) {
                distances[edge.to] = d;
                Q.emplace(d, edge.to);
            }
        }
    }
}

int main() {
    long long N, M;
    cin >> N >> M;
    vector<long long> distances(N + 1, INF);
    distances[1] = 0;
    Graph graph(N + 1);
    vector<long long> a(M), b(M), c(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        Edge e, f;
        e.to = b[i];
        e.cost = c[i];
        f.to = a[i];
        f.cost = c[i];
        graph[a[i]].push_back(e);
        graph[b[i]].push_back(f);
    }

    dijkstra(graph, distances, 1);

    if (distances[N] == INF) cout << -1 << endl;
    else cout << distances[N] << endl;
}