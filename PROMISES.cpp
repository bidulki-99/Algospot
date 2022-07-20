#include <bits/stdc++.h>
using namespace std;

int V, M, N;
int adj[200][200];

void floyd() {
    for (int i = 0; i < V; i++)
        adj[i][i] = 0;

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

bool update(int a, int b, int c) {
    if (adj[a][b] <= c)
        return false;

    for (int x = 0; x < V; x++)
        for (int y = 0; y < V; y++)
            adj[x][y] = min({adj[x][y], adj[x][a] + c + adj[b][y], adj[x][b] + c + adj[a][y]});

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int c;
    for (cin >> c; c--;) {
        cin >> V >> M >> N;

        memset(adj, 0x3f, sizeof(adj));

        int a, b, c;
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            adj[a][b] = min(adj[a][b], c);
            adj[b][a] = min(adj[b][a], c);
        }

        floyd();

        int ans = 0;
        for (int i = 0; i < N; i++) {
            cin >> a >> b >> c;
            ans += (update(a, b, c) ? 0 : 1);
        }

        cout << ans << '\n';
    }
}
