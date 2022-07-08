#include <bits/stdc++.h>
using namespace std;

vector<int> h;

int solve(int left, int right) {
	if (left == right)
		return h[left];

	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);
	
	while (left < lo or hi < right) {
		if (hi < right and (lo == left or h[lo - 1] < h[hi + 1])) {
			hi++;
			height = min(height, h[hi]);
		}
		else {
			lo--;
			height = min(height, h[lo]);
		}

		ret = max(ret, height * (hi - lo + 1));
	}
	
	return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
	for (cin >> c; c--;) {
		int n;
		cin >> n;
		h.resize(0);

		int temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			h.push_back(temp);
		}
		
		cout << solve(0, n - 1) << '\n';
	}
}
