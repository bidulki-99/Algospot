#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int V, W;
vector<pair<int, int>> adj[100];
vector<pair<int, int>> adj2[100];
bool reachable[100][100];

void calcReachable() {
    for (int i = 0; i < V; i++)
        reachable[i][i] = true;

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                reachable[i][j] = reachable[i][j] or (reachable[i][k] and reachable[k][j]);
}

int bellmanFord(int src, int target) {
    vector<int> upper(V, INF);
    upper[src] = 0;

    for (int iter = 0; iter < V - 1; iter++)
        for (int here = 0; here < V; here++)
            for (int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                upper[there] = min(upper[there], upper[here] + cost);
            }

    for (int here = 0; here < V; here++)
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int cost = adj[here][i].second;

            if (upper[here] + cost < upper[there])
                if (reachable[src][here] and reachable[here][target])
                    return -INF;
        }

    return upper[target];
}

int bellmanFord2(int src, int target) {
    vector<int> upper(V, INF);
    upper[src] = 0;

    for (int iter = 0; iter < V - 1; iter++)
        for (int here = 0; here < V; here++)
            for (int i = 0; i < adj2[here].size(); i++) {
                int there = adj2[here][i].first;
                int cost = adj2[here][i].second;
                upper[there] = min(upper[there], upper[here] + cost);
            }

    for (int here = 0; here < V; here++)
        for (int i = 0; i < adj2[here].size(); i++) {
            int there = adj2[here][i].first;
            int cost = adj2[here][i].second;

            if (upper[here] + cost < upper[there])
                if (reachable[src][here] and reachable[here][target])
                    return -INF;
        }

    return upper[target];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int c;
    for (cin >> c; c--;) {
        cin >> V >> W;

        memset(reachable, false, sizeof(reachable));
        for (int i = 0; i < 100; i++) {
            adj[i].clear();
            adj2[i].clear();
        }

        int a, b, d;
        for (int i = 0; i < W; i++) {
            cin >> a >> b >> d;
            adj[a].push_back({b, d});
            adj2[a].push_back({b, -d});
            reachable[a][b] = true;
        }

        calcReachable();
        auto ans1 = bellmanFord(0, 1);
        auto ans2 = bellmanFord2(0, 1);

        if (!reachable[0][1])
            cout << "UNREACHABLE\n";
        else {
            if (ans1 == -INF)
                cout << "INFINITY ";
            else
                cout << ans1 << ' ';

            if (ans2 == -INF)
                cout << "INFINITY\n";
            else
                cout << -ans2 << '\n';
        }
    }
}
