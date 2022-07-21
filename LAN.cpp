#include <bits/stdc++.h>
using namespace std;

int n, m;
double adj[500][500];
int x[500], y[500];

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n): parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) {
		if (u == parent[u])
			return u;

		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v)
			return;

		if (rank[u] > rank[v])
			swap(u, v);

		parent[u] = v;

		if (rank[u] == rank[v])
			rank[v]++;
	}
};

double kruskal() {
    double ret = 0;

    vector<pair<double, pair<int, int>>> edges;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
			edges.push_back({adj[i][j], {i, j}});

    sort(edges.begin(), edges.end());

    DisjointSet sets(n);
    for (int i = 0; i < edges.size(); i++) {
        double cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;

        if (sets.find(u) == sets.find(v))
            continue;

        sets.merge(u, v);
        ret += cost;
    }
    
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	for (cin >> c; c--;) {
		cin >> n >> m;

		memset(adj, 0, sizeof(adj));
		memset(x, -1, sizeof(x));
		memset(y, -1, sizeof(y));

		for (int i = 0; i < n; i++)
			cin >> x[i];
		for (int i = 0; i < n; i++)
			cin >> y[i];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adj[i][j] = adj[j][i] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));

		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			adj[a][b] = 0;
			adj[b][a] = 0;
		}

		cout << fixed;
		cout.precision(10);
		cout << kruskal() << '\n';
	}
}
