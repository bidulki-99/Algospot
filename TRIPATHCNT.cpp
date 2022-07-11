#include <bits/stdc++.h>
using namespace std;

int n;
int triangle[101][101];
int cache[101][101];
int cache2[101][101];

int path(int y, int x) {
	if (y == n - 1)
		return triangle[y][x];

	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	return ret = max(path(y + 1, x + 1), path(y + 1, x)) + triangle[y][x];
}

int count(int y, int x) {
    if (y == n - 1)
        return 1;

    int& ret = cache2[y][x];
    if (ret != -1)
        return ret;

    ret = 0;
    if (path(y + 1, x) >= path(y + 1, x + 1))
        ret += count(y + 1, x);
    if (path(y + 1, x) <= path(y + 1, x + 1))
        ret += count(y + 1, x + 1);
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
    for (cin >> c; c--;) {
        cin >> n;

        memset(cache, -1, sizeof(cache));
        memset(cache2, -1, sizeof(cache2));

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                cin >> triangle[i][j];

        cout << count(0, 0) << '\n';
    }
}
