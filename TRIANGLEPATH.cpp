#include <bits/stdc++.h>
using namespace std;

int n;
int cache[101][101];
int triangle[101][101];

int solve(int y, int x) {
	if (y == n)
		return triangle[y][x];

	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	return ret = max(solve(y + 1, x + 1), solve(y + 1, x)) + triangle[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
	for (cin >> c; c--;) {
		memset(cache, -1, sizeof(cache));

		cin >> n;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				cin >> triangle[i][j];

		cout << solve(1, 1) << '\n';
	}
}
