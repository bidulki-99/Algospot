#include <bits/stdc++.h>
using namespace std;

int n;
int board[100][100];
int cache[100][100];
bool flag;

void jump(int y, int x) {
	if (y >= n or x >= n)
		return;

	if (y == n - 1 and x == n - 1) {
		flag = true;
		return;
	}

	if (cache[y][x])
		return;

	int jumpSize = board[y][x];
	jump(y + jumpSize, x);
	jump(y, x + jumpSize);
	cache[y][x] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
	cin >> c;

	while (c--) {
		memset(cache, 0, sizeof(cache));
		cin >> n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];

		flag = false;
		jump(0, 0);
		cout << (flag ? "YES\n" : "NO\n");
	}
}
