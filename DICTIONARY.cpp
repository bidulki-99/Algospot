#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

void makeGraph(const vector<string>& words) {
    adj = vector<vector<int>>(26, vector<int>(26, 0));

    for (int j = 1; j < words.size(); j++) {
        int i = j - 1;
        int len = min(words[i].size(), words[j].size());

        for (int k = 0; k < len; k++)
            if (words[i][k] != words[j][k]) {
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';
                adj[a][b] = 1;
                break;
            }
    }
}

vector<int> visited, order;

void dfs(int here) {
    visited[here] = 1;

    for (int there = 0; there < adj.size(); there++)    
        if (adj[here][there] and !visited[there])
            dfs(there);
    order.push_back(here);
}

vector<int> topologicalSort() {
    int m = adj.size();
    visited = vector<int>(m, 0);
    order.clear();

    for (int i = 0; i < m; i++)
        if (!visited[i])
            dfs(i);

    reverse(order.begin(), order.end());

    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (adj[order[j]][order[i]])
                return vector<int>();

    return order;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
    for (cin >> c; c--;) {
        cin >> n;

        vector<string> words(n);
        for (int i = 0; i < n; i++)
            cin >> words[i];

        makeGraph(words);
        vector<int> ans = topologicalSort();

        if (ans.empty())
            cout << "INVALID HYPOTHESIS";
        else
            for (int i = 0; i < ans.size(); i++)
                cout << char(ans[i] + 'a');
        cout << '\n';
    }
}
