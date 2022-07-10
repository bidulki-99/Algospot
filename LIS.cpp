#include <bits/stdc++.h>
using namespace std;

int n;
int cache[501];
int seq[501];

int solve(int start) {
	int& ret = cache[start + 1];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int next = start + 1; next < n; next++)
		if (start == -1 or seq[start] < seq[next])
			ret = max(ret, solve(next) + 1);

	return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
	for (cin >> c; c--;) {
		memset(cache, -1, sizeof(cache));

		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> seq[i];

		cout << solve(-1) - 1 << '\n';
	}
}
