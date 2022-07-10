#include <bits/stdc++.h>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m;
int cache[101][101];
int seq1[101], seq2[101];

int solve(int a, int b) {
	int& ret = cache[a + 1][b + 1];
	if (ret != -1)
		return ret;

	long long A = (a == -1 ? NEGINF : seq1[a]);
	long long B = (b == -1 ? NEGINF : seq2[b]);
	long long maxElement = max(A, B);

	ret = 2;
	for (int next = a + 1; next < n; next++)
		if (maxElement < seq1[next])
			ret = max(ret, solve(next, b) + 1);
	for (int next = b + 1; next < m; next++)
		if (maxElement < seq2[next])
			ret = max(ret, solve(a, next) + 1);

	return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
	for (cin >> c; c--;) {
		memset(cache, -1, sizeof(cache));

		cin >> n >> m;

		for (int i = 0; i < n; i++)
			cin >> seq1[i];
		for (int i = 0; i < m; i++)
			cin >> seq2[i];

		cout << solve(-1, -1) - 2 << '\n';
	}
}
