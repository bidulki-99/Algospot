#include <bits/stdc++.h>
using namespace std;

int cache[101][101];
string W, S;

bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];

	if (ret != -1)
		return ret;

	while (s < S.size() and w < W.size() and (W[w] == '?' or W[w] == S[s])) {
		w++;
		s++;
	}

	if (w == W.size())
		return ret = (s == S.size());

	if (W[w] == '*')
		for (int skip = 0; skip + s <= S.size(); skip++)
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;

	return ret = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
	for (cin >> c; c--;) {
		cin >> W;

		int n;
		cin >> n;

		vector<string> str, ans;
		for (int i = 0; i < n; i++) {
			cin >> S;
			memset(cache, -1, sizeof(cache));
			
			if (matchMemoized(0, 0) == 1)
				ans.push_back(S);
		}

		sort(ans.begin(), ans.end());
		for (string i : ans)
			cout << i << '\n';
	}
}
