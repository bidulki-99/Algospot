#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m;
const ll MAX = 2000000000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	for (cin >> c; c--;) {
		cin >> n >> m;

		int ratio = m * 100 / n;

		if ((m + MAX) * 100 / (n + MAX) == ratio) {
			cout << -1 << '\n';
			continue;
		}
		
		ll lo = 0, hi = MAX;
		while (lo + 1 < hi) {
			ll mid = (lo + hi) / 2;

			if ((m + mid) * 100 / (n + mid) == ratio)
				lo = mid;
			else
				hi = mid;

		}

		cout << hi << '\n';
	}
}
