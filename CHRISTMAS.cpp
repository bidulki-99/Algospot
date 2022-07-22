#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, k;
int d[100000];
vector<int> psum;

int waysToBuy(const vector<int>& psum, int k) {
	const int MOD = 20091101;
	int ret = 0;
	vector<long long> count(k, 0);

	for (int i = 0; i < psum.size(); i++)
		count[psum[i]]++;

	for (int i = 0; i < k; i++)
		if (count[i] >= 2)
			ret = (ret + ((count[i] * (count[i] - 1)) / 2)) % MOD;

	return ret;
}

int maxBuys(const vector<int>& psum, int k) {
	vector<int> ret(psum.size(), 0);
	vector<int> prev(k, -1);

	for (int i = 0; i < psum.size(); i++) {
		if (i > 0)
			ret[i] = ret[i - 1];
		else
			ret[i] = 0;

		int loc = prev[psum[i]];
		if (loc != -1)
			ret[i] = max(ret[i], ret[loc] + 1);

		prev[psum[i]] = i;
	}

	return ret.back();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	for (cin >> c; c--;) {
		cin >> n >> k;

		for (int i = 0; i < n; i++)
			cin >> d[i];

		psum = vector<int>(1, 0);

		for (int i = 1; i <= n; i++)
			psum.push_back((psum[i - 1] + d[i - 1]) % k);

		cout << waysToBuy(psum, k) << ' ' << maxBuys(psum, k) << '\n';
	}
}
