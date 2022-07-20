const int MAX_V = 100;
const int INF = 987654321;
int V;
vector<pair<int, int>> adj[MAX_V];

int prim(vector<pair<int, int>>& selected) {
    selected.clear();

    vector<bool> added(V, false);
    vector<int> minWeight(V, INF), parent(V, -1);
    int ret = 0;
    minWeight[0] = parent[0] = 0;

    for (int iter = 0; iter < V; iter++) {
        int u = -1;

        for (int v = 0; v < V; v++)
            if (!added[v] and (u == -1 or minWeight[u] > minWeight[v]))
                u = v;

        if (parent[u] != u)
            selected.push_back({parent[u], u});

        ret += minWeight[u];
        added[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first, weight = adj[u][i].second;

            if (!added[v] and minWeight[v] > weight) {
                parent[v] = u;
                minWeight[v] = weight;
            }
        }
    }

    return ret;
}
