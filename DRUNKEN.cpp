#include <bits/stdc++.h>
using namespace std;

int V, E;
int adj[500][500];
int delay[500];
int W[500][500];

void solve() {
    vector<pair<int, int>> order;

    for (int i = 0; i < V; i++)
        order.push_back({delay[i], i});

    sort(order.begin(), order.end());

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (i == j)
                W[i][j] = 0;
            else
                W[i][j] = adj[i][j];

    for (int k = 0; k < V; k++) {
        int w = order[k].second;

        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) {
                adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
                W[i][j] = min(adj[i][w] + delay[w] + adj[w][j], W[i][j]);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(adj, 0x3f, sizeof(adj));
    memset(W, 0x3f, sizeof(W));
    for (int i = 0; i < 500; i++)
        adj[i][i] = W[i][i] = 0;

    cin >> V >> E;

    for (int i = 0; i < V; i++)
        cin >> delay[i];

    int a, b, d;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> d;
        adj[a - 1][b - 1] = W[a - 1][b - 1] = d;
        adj[b - 1][a - 1] = W[b - 1][a - 1] = d;
    }

    solve();

    int c;
    for (cin >> c; c--;) {
        int a, b;
        cin >> a >> b;
        cout << W[a - 1][b - 1] << '\n';
    }
}
