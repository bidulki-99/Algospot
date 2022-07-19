#include <bits/stdc++.h>
using namespace std;

int V, E, n, m;
vector<pair<int, int>> adj[1001];
const int INF = 987654321;

vector<int> dijkstra(int src) {
    vector<int> dist(V + 1, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost)
            continue;

        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
    for (cin >> c; c--;) {
        cin >> V >> E >> n >> m;

        int a, b, c;
        while (E--) {
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }

        vector<int> fire(n);
        for (int i = 0; i < n; i++)
            cin >> fire[i];

        int temp;
        while (m--) {
            cin >> temp;
            adj[0].push_back({temp, 0});
        }

        auto res = dijkstra(0);
        int ans = 0;
        
        for (int i = 0; i < n; i++)
            ans += res[fire[i]];

        cout << ans << '\n';
    }
}
