#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, k, m, l;
int prerequisite[12];
int classes[10];
int cache[10][1 << 12];

int graduate(int semester, int taken) {
	if (__builtin_popcount(taken) >= k)
		return 0;

	if (semester == n)
		return INF;

	int& ret = cache[semester][taken];
	if (ret != -1)
		return ret;

	ret = INF;
	int canTake = (classes[semester] & ~taken);

	for (int i = 0; i < n; i++)
		if ((canTake & (1 << i)) and (taken & prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i);

	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		if (__builtin_popcount(take) > l)
			continue;

		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}

	ret = min(ret, graduate(semester + 1, taken));

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	for (cin >> c; c--;) {
		memset(prerequisite, 0, sizeof(prerequisite));
		memset(classes, 0, sizeof(classes));
		memset(cache, -1, sizeof(cache));

		cin >> n >> k >> m >> l;
	
		for (int i = 0; i < n; i++) {
			int preNum;
			cin >> preNum;

			for (int j = 0; j < preNum; j++) {
				int temp;
				cin >> temp;

				prerequisite[i] |= (1 << temp);
			}
		}

		for (int i = 0; i < m; i++) {
			int classNum;
			cin >> classNum;

			for (int j = 0; j < classNum; j++) {
				int temp;
				cin >> temp;

				classes[i] |= (1 << temp);
			}
		}

		int ans = graduate(0, 0);
		if (ans == INF)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << '\n';
	}
}
