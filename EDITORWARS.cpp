#include <bits/stdc++.h>
using namespace std;

int n, m;

struct BipartiteUnionFind {
	vector<int> parent, rank, enemy, size;
	BipartiteUnionFind(int n): parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) {
		if (parent[u] == u)
			return u;

		return parent[u] = find(parent[u]);
	}

	int merge(int u, int v) {
		if (u == -1 or v == -1)
			return max(u, v);

		u = find(u);
		v = find(v);

		if (u == v)
			return u;

		if (rank[u] > rank[v])
			swap(u, v);

		if (rank[u] == rank[v])
			rank[v]++;

		parent[u] = v;
		size[v] += size[u];

		return v;
	}

	bool dis(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v)
			return false;

		int a = merge(u, enemy[v]);
		int b = merge(v, enemy[u]);
		enemy[a] = b;
		enemy[b] = a;

		return true;
	}

	bool ack(int u, int v) {
		u = find(u);
		v = find(v);

		if (enemy[u] == v)
			return false;

		int a = merge(u, v);
		int b = merge(enemy[u], enemy[v]);

		enemy[a] = b;
		if (b != -1)
			enemy[b] = a;

		return true;
	}
};

int maxParty(const BipartiteUnionFind& buf) {
	int ret = 0;
	
	for (int node = 0; node < n; node++) {
		if (buf.parent[node] == node) {
			int enemy = buf.enemy[node];

			if (enemy > node)
				continue;

			int mySize = buf.size[node];
			int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
			ret += max(mySize, enemySize);
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	for (cin >> c; c--;) {
		cin >> n >> m;

		string s;
		int a, b;

		BipartiteUnionFind buf(n);
		int num = -1;
		bool flag = false;

		for (int i = 1; i <= m; i++) {
			cin >> s >> a >> b;

			if (flag)
				continue;

			if (s == "ACK") {
				if (!buf.ack(a, b)) {
					flag = true;
					num = i;
				}
			}
			else {
				if (!buf.dis(a, b)) {
					flag = true;
					num = i;
				}
			}
		}

		if (flag)
			cout << "CONTRADICTION AT " << num << '\n';
		else
			cout << "MAX PARTY SIZE IS " << maxParty(buf) << '\n';
	}
}
