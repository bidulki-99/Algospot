#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15;
int k;
string word[MAX_N];
int cache[MAX_N][1 << MAX_N], overlap[MAX_N][MAX_N];

int restore(int last, int used) {
	if (used == (1 << k) - 1)
		return 0;

	int& ret = cache[last][used];
	if (ret != -1)
		return ret;

	for (int next = 0; next < k; next++)
		if ((used & (1 << next)) == 0) {
			int cand = overlap[last][next] + restore(next, used + (1 << next));
			ret = max(ret, cand);
		}

	return ret;
}

string reconstruct(int last, int used) {
	if (used == (1 << k) - 1)
		return "";

	for (int next = 0; next < k; next++) {
		if (used & (1 << next))
			continue;

		int ifUsed = restore(next, used + (1 << next)) + overlap[last][next];

		if (restore(last, used) == ifUsed)
			return (word[next].substr(overlap[last][next])) + reconstruct(next, used + (1 << next));
	}

	return "****oops****";
}

int getOverlap(const string& s1, const string& s2) {
	for (int length = min(s1.size(), s2.size()); length > 0; length--)
		if (s1.substr(s1.size() - length) == s2.substr(0, length))
			return length;

	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	for (cin >> c; c--;) {
		memset(cache, -1, sizeof(cache));
		
		cin >> k;

		for (int i = 0; i < k; i++)
			cin >> word[i];
		
		while (true) {
			bool removed = false;

			for (int i = 0; i < k and !removed; i++)
				for (int j = 0; j < k; j++)
					if (i != j and word[i].find(word[j]) != -1) {
						word[j] = word[k - 1];
						k--;
						removed = true;
					}

			if (!removed)
				break;
		}

		word[k] = "";
		for (int i = 0; i <= k; i++)
			for (int j = 0; j <= k; j++)
				overlap[i][j] = getOverlap(word[i], word[j]);

		cout << reconstruct(k, 0) << '\n';
	}
}
