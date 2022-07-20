struct DisjointSet;
const int MAX_V = 100;
int V;
vector<pair<int, int>> adj[MAX_V];

int kruskal(vector<pair<int, int>>& selected) {
    int ret = 0;
    selected.clear();

    vector<pair<int, pair<int, int>>> edges;
    for (int u = 0; u < V; u++)
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first, cost = adj[u][i].second;
            edges.push_back({cost, {u, v}});
        }

    sort(edges.begin(), edges.end());

    DisjointSet sets(V);
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;

        if (sets.find(u) == sets.find(v))
            continue;

        sets.merge(u, v);
        selected.push_back({u, v});
        ret += cost;
    }
    
    return ret;
}
