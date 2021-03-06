#include <bits/stdc++.h>
using namespace std;

int n, m, k;
const int M = 1000000000 + 100;
int bino[201][201];
int skip;

void calcBino() {
	memset(bino, 0, sizeof(bino));
	
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;

		for (int j = 1; j < i; j++)
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
	}
}

void generate(int n, int m, string s) {
	if (skip < 0)
		return;

	if (n == 0 and m == 0) {
		if (skip == 0)
			cout << s << '\n';
		skip--;
		return;
	}

	if (bino[n + m][n] <= skip) {
		skip -= bino[n + m][n];
		return;
	}

	if (n > 0)
		generate(n - 1, m, s + "-");
	if (m > 0)
		generate(n, m - 1, s + "o");
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	calcBino();

	int c;
	for (cin >> c; c--;) {
		cin >> n >> m >> k;

		string ans;
		skip = k - 1;

		generate(n, m, ans);
	}
}
