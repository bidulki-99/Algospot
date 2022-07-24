#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define REP(i, a, b) for (int i = a; i <= b; i++)

int n;
int m[10000], e[10000];

int heat() {
	vector<pair<int, int>> order;

	rep(i, 0, n)
		order.push_back({-e[i], i});

	sort(order.begin(), order.end());
	
	int ret = 0, beginEat = 0;
	rep(i, 0, n) {
		int box = order[i].second;
		beginEat += m[box];
		ret = max(ret, beginEat + e[box]);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	for (cin >> c; c--;) {
		memset(m, 0, sizeof(m));
		memset(e, 0, sizeof(e));

		cin >> n;

		rep(i, 0, n)
			cin >> m[i];
		rep(i, 0, n)
			cin >> e[i];

		cout << heat() << '\n';
	}
}
