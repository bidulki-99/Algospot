vector<vector<int>> adj;
vector<int> discovered, finished;
int counter;

void dfs2(int here) {
    discovered[here] = counter++;

    for (int i = 0; i < adj.size(); i++) {
        int there = adj[here][i];
        cout << "(" << here << "," << there << ") is a ";

        if (discovered[there] == -1) {
            cout << "tree edge\n";
            dfs2(there);
        }
        else if (discovered[here] < discovered[there])
            cout << "forward edge\n";
        else if (finished[there] == 0)
            cout << "back edge\n";
        else
            cout << "cross edge\n";
    }

    finished[here] = 1;
}
