#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, double>> adj[10000];
const long double INF = 1e15;

double dijkstra(int src) {
    vector<double> dist(n, INF);
    dist[src] = 1;
    priority_queue<pair<double, int>> pq;
    pq.push({-1, src});

    while (!pq.empty()) {
        double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost)
            continue;

        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            double nextDist = cost * adj[here][i].second;

            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }

    return dist[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
    for (cin >> c; c--;) {
        cin >> n >> m;

        int a, b;
        double c;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }

        cout << fixed;
        cout.precision(10);

        cout << dijkstra(0) << '\n';
    }
}
