#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout.setf(ios::fixed);
	cout.precision(8);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n, l;
		cin >> n >> l;

		vector<double> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		double ans = 999999999;
		int sum;
		double avg;

		for (int i = 0; i < n; i++) {
			sum = 0;

			for (int j = i; j < n; j++) {
				sum += a[j];

				if (j - i + 1 >= l) {
					avg = (double)sum / (j - i + 1);
					ans = min(ans, avg);
				}
			}
		}

		cout << ans << '\n';
	}
}
